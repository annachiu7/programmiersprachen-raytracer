// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#include "renderer.hpp"

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
  std::cout << "Achtung Achtung: Ueberschreibe scene_\n";
  scene_.shapes.push_back(std::make_shared<Sphere>(Material(), "gugel", glm::vec3(0,0,-3.0), 1.0));

  for (unsigned y = 0; y < height_; ++y) {
    for (unsigned x = 0; x < width_; ++x) {
      Pixel p(x,y);
      // Ray ray = scene_.camera.calc_eye_ray(x,y);
      glm::vec3 origin{float(x)*2.0/float(width_) - 1.0,float(y)*2.0/float(height_) - 1.0,0};
      glm::vec3 direction{0,0,-1};
      Ray ray{origin, direction};

      float nearest_t = 10000.0;
      Shape* closest = nullptr;
      for (auto const& shape : scene_.shapes) {
        float t = 0.0;
        bool hit = shape->intersect(ray, t);
        if (hit && 0 < t && t < nearest_t) {
          nearest_t = t;
          closest = shape.get();
        }
      }

      // p.color = raytrace(ray, 3);
      if ( closest ) {
        // p.color = normal * 0.5f + 0.5f:
        p.color = Color(1.0,1.0,1.0);
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
