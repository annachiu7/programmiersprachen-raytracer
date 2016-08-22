// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#include "renderer.hpp"

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
  for (unsigned y = 0; y < height_; ++y) {
    for (unsigned x = 0; x < width_; ++x) {
      Pixel p(x,y);

      Ray ray = scene_.camera.calc_eye_ray(x,y,scene_.height,scene_.width);

      p.color = raytrace(ray, 3);

      write(p);
    }
  }
  ppm_.save(filename_);
}

#if 1
//Color raytrace(Ray const& ray) const
//Color Renderer::raytrace(Ray const& ray, unsigned depth) 
Color Renderer::raytrace(Ray const& ray, unsigned depth) const
{  
  Color clr;

  OptiHit hit;
  for (auto const& shape : scene_.shapes)
  {
    hit = shape->intersect(ray);
  }

  if (hit.hit) 
    {
      float c = 0.001;

      for (auto const& light : scene_.lights) 
      {
        Ray lightray{ hit.surface_pt, light->pos_-hit.surface_pt };  // make ray: point to light source
        lightray.origin_+= lightray.direction_ * c;  // no intersect with self

        glm::vec3 l = lightray.direction_;
        float nl = glm::dot(hit.n,l);

        // ambient light !(to be implemented after extension of scene.cpp)
        clr += (light->la_) * (hit.closest_shape->get_mat().ka_); 

        // diffuse light (generated when not shadow)
          // see if any other objects in the way? iteration through composite vectors
        OptiHit hitbetween;
        for (auto const& comp : scene_.shapes)  
        {
          hitbetween = comp->intersect(lightray);
        }
        if ( !hitbetween.hit )  
        {
          clr += (light->ld_) * (hit.closest_shape->get_mat().kd_) * std::max(nl,0.0f);

          // specular light
          glm::vec3 v = -ray.direction_;   // vector from surface_p to cam
          glm::vec3 r = glm::normalize(2*nl*hit.n-l);    // reflection vector
          float rv = glm::dot(r,v);

          clr += (light->ld_) * (hit.closest_shape->get_mat().ks_) 
                 *pow(std::max(rv,0.0f), hit.closest_shape->get_mat().m_);
        }

      }
    } else 
    {
      clr = Color(0.1,0.1,0.1);
    }

  return clr;
}
#endif


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
