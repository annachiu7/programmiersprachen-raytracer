// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#include "renderer.hpp"
//#include "optiHit.hpp"

Renderer::Renderer(Scene const& scene)
  :scene_(scene)
  , colorbuffer_(scene.width*scene.height, Color(0.0, 0.0, 0.0))
  , ppm_(scene.width, scene.height)
{}

Renderer::Renderer(Scene const& scene, unsigned w, unsigned h, std::string const& file)
  : scene_(scene)
  , width_(w)
  , height_(h)
  , colorbuffer_(w*h, Color(0.0, 0.0, 0.0))
  , filename_(file)
  , ppm_(width_, height_)
{}

void Renderer::render()
{
  const std::size_t checkersize = 20;

  for (unsigned y = 0; y < height_; ++y) {
    for (unsigned x = 0; x < width_; ++x) {
      Pixel p(x,y);

      Ray ray = scene_.camera.calc_eye_ray(x,y,scene_.height,scene_.width);

      OptiHit hit; 
      for (auto const& shape : scene_.shapes)
      {
        hit = shape->intersect(ray,hit.distance);//hier noch abfragen ob nearest
      }

        if ( hit.closest_shape ) {
          hit = hit.closest_shape->intersect(ray, 0);
          auto surface_pt= hit.closest_shape->calc_surface_pt(ray, hit.distance);
          auto n = hit.closest_shape->calc_n(hit); 

          for (auto const& light : scene_.lights)
          {
            Ray pt_to_l{surface_pt, light->pos_};  // make ray: intersection to light sources
        
            /* generate shadow
            // #################### not working yet #######################################
            float t = 0.0f;
            bool lighted = true;  // initially with light
            for (auto const& shape : scene_.shapes)  // see if any other objects in the way?
            {
              if (shape.get() != hit.closest_shape ) {  // exclude intersection with self
                if (shape->intersect(pt_to_l, t) == true)  // in the way, then no light
                {
                    lighted = false;
                    p.color = Color{0,0,0};
                    break;
                }
              } 
            }*/
            // ############################################################################

            glm::vec3 l = pt_to_l.direction_;
            float nl = glm::dot(n,l);
            // calculate light intensity and return color for the pixel
             p.color += Color{ (light->ld_.r) * (hit.closest_shape->get_mat().kd_.r) * nl,
                               (light->ld_.g) * (hit.closest_shape->get_mat().kd_.g) * nl,
                               (light->ld_.b) * (hit.closest_shape->get_mat().kd_.b) * nl };
          }

          // p.color = raytrace(ray, 3);
        } else {
          p.color = Color(0.1,0.1,0.1);
        }

      write(p);
    }
  }
  ppm_.save(filename_);
}
/*
Color raytrace(Ray const& ray) const
{  
  
  return Color;
}
*/

void Renderer::write(Pixel const& p)
{
  // flip pixels, because of opengl glDrawPixels
  size_t buf_pos = (width_*p.y + p.x);
  if (buf_pos >= colorbuffer_.size() || (int)buf_pos < 0) {
    std::cerr << "Fatal Error Renderer::write(Pixel p) : "
      << "pixel out of ppm_ : "
      << (int)p.x << "," << (int)p.y
      << std::endl;
  } else {
    colorbuffer_[buf_pos] = p.color;
  }

  ppm_.write(p);
}
