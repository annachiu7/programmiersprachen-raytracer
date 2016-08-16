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
  const std::size_t checkersize = 20;

  for (unsigned y = 0; y < height_; ++y) {
    for (unsigned x = 0; x < width_; ++x) {
      Pixel p(x,y);
      Ray ray = scene_.camera.calc_eye_ray(x,y,scene_.height,scene_.width);

      float nearest_t = 10000.0;
      Shape* closest = nullptr;
      float t = 0.0;
      for (auto const& shape : scene_.shapes) {
        bool hit = shape->intersect(ray, t);
        if (hit && 0 < t && t < nearest_t) {
          nearest_t = t;
          closest = shape.get();
        }
      }

      glm::vec3 normal{ray.origin_ + ray.direction_*t};
      normal.x = normal.x-0;
      normal.y = normal.y-0;
      normal.z = normal.z+3;
      normal = glm::normalize(normal);
      auto tmpN = normal * 0.5f + 0.5f;

      // p.color = raytrace(ray, 3);
      if ( closest ) {
        p.color = Color(tmpN.x,tmpN.y,tmpN.z);
        //p.color = Color(1.0,1.0,1.0);
      } else {
        p.color = Color(0,0,0);
      }

      write(p);
    }
  }
  ppm_.save(filename_);
}

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
