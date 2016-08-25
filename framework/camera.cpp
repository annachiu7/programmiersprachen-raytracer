#include "camera.hpp"
#include <cmath>

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

Camera::Camera(std::string const& name, double fov_x):
name_{name},
fov_x_{fov_x},
origin_{0.0,0.0,0.0},
dir_{0.0,0.0,-1.0},
up_{}
{}

Camera::Camera(std::string const& name, double fov_x, glm::vec3 const& origin, 
			   glm::vec3 const& dir, glm::vec3 const& up):
name_{name},
fov_x_{fov_x},
origin_{origin},
dir_{dir},
up_{up}
{}


Ray Camera::calc_eye_ray(int x, int y, int height, int width)
{
	// -------- das einfache Kameramodell -------- //
	// ----- Die Breite der Bildebene ist 1 ------ //
	// Blickrichtung ist die negative z-Richtung!
	// Die Position der Camera kann sich aber irgendwo befinden
  	glm::vec3 direction{float(x)*1.0/float(width) -0.5,
                        float(y)*1.0/float(height) -0.5, 
                        -1.0*(0.5/tan(fov_x_/2))}; // distance = 0.5 / tan(winkel/2)
  	Ray ray{origin_, direction};
    //ray = transformRay(transf_, ray);

  	return ray;
}
