#include "camera.hpp"

Camera::Camera():
name_{""},
pos_{0,0,0},
fov_x_{45}
{}

Camera::Camera(std::string const& name, glm::vec3 const& pos, double fov_x):
name_{name},
pos_{pos},
fov_x_{fov_x}
{}

Ray Camera::calc_eye_ray(int x, int y, int height, int width)
{
  glm::vec3 origin{float(x)*2.0/float(width) -1.0,
                    float(y)*2.0/float(height) -1.0,0};
  glm::vec3 direction{0,0,-1};
  Ray ray{origin, direction};
  return ray;
}
