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
  for (unsigned y = 0; y < height_; ++y) {
    for (unsigned x = 0; x < width_; ++x) {
      Pixel p(x,y);

#if 1
      Ray ray = scene_.camera.calc_eye_ray(x,y,scene_.height,scene_.width);
      Box box{{},"DEBUG",{0.1,0.1,-3},{1.0,1.0,-2.0}};
      //Sphere box{{},"DEBUG",{0.0,0.0,-5.0},3};
      OptiHit hit = box.intersect(ray);

      if (hit.hit) 
      {
        p.color = Color(1.0,1.0,1.0);
      }else
      {
        p.color = Color(.0,.0,.0);
      }
#endif

//      p.color = raytrace(ray, 3);
#if 0
      OptiHit hit; 
      for (auto const& shape : scene_.shapes)
      {
        hit = shape->intersect(ray);//hier noch abfragen ob nearest
      }

        if ( hit.closest_shape ) 
        {

          /*
          hit = hit.closest_shape->intersect(ray);
          auto surface_pt= hit.closest_shape->calc_surface_pt(ray, hit.distance);
          auto n = hit.closest_shape->calc_n(hit); 
          */
          auto surface_pt = hit.surface_pt;
          auto n = hit.n;

          for (auto const& light : scene_.lights)
          {
            Ray pt_to_l{surface_pt, light->pos_-surface_pt};  // make ray: intersection to light sources

            glm::vec3 l = pt_to_l.direction_;
            float nl = glm::dot(n,l);
            // calculate light intensity and return color for the pixel
             p.color += Color{ (light->ld_.r) * (hit.closest_shape->get_mat().kd_.r) * nl,
                               (light->ld_.g) * (hit.closest_shape->get_mat().kd_.g) * nl,
                               (light->ld_.b) * (hit.closest_shape->get_mat().kd_.b) * nl };        
             //generate shadow
            // #################### not working yet #######################################
            float t = 0.0f;
            for (auto const& comp : scene_.shapes)  // see if any other objects in the way? // iteration through composite vector
            {
              OptiHit a = comp->intersect(pt_to_l);
              if (a.hit && t!=0.0f )  // exclude intersection with self
              {
                p.color = Color{1,1,1};
                break;
              }
            }
            // ############################################################################ 


          }

        } else {
          p.color = Color(0.1,0.1,0.1);
        }
#endif
      write(p);
    }
  }
  ppm_.save(filename_);
}

#if 0
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

  if (hit.closest_shape) 
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
        for (auto const& comp : scene_.shapes)  
        {
          OptiHit a = comp->intersect(lightray);
          if ( !a.hit )  
          {
            clr += (light->ld_) * (hit.closest_shape->get_mat().kd_) * nl;
            break;
          }
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
