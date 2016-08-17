#include "camera.hpp"

Camera::Camera():
name_{""},
fov_x_{45},
origin_{0,0,0}
{}

Camera::Camera(std::string const& name, double fov_x, glm::vec3 const& origin):
name_{name},
fov_x_{fov_x},
origin_{origin}
{}

Camera::Camera(std::string const& name, double fov_x, glm::vec3 const& origin, glm::vec3 const& dir, glm::vec3 const& up):
name_{name},
fov_x_{fov_x},
origin_{origin},
dir_{dir},
up_{up}
{}

Ray Camera::calc_eye_ray(int x, int y, int height, int width)
{
  //glm::vec3 origin{0,0,0};
  glm::vec3 direction{float(x)*2.0/float(width) -1.0,
                      float(y)*2.0/float(height) -1.0,-1.0};
  Ray ray{origin_, direction};
  return ray;
}
