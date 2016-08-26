#include "camera.hpp"
#include <cmath>

Camera::Camera():
name_{""},
fov_x_{45},
origin_{0.0,0.0,0.0}
{}

Camera::Camera(std::string const& name, double fov_x, glm::vec3 const& origin):
name_{name},
fov_x_{fov_x},
origin_{origin}
{}

Camera::Camera(std::string const& name, double fov_x):
name_{name},
fov_x_{fov_x},
//origin_{glm::vec3(translate_*glm::vec4(0.0,0.0,0.0,1.0f))},
origin_{0.0,0.0,0.0},
//dir_{glm::vec3(rotate_ * glm::vec4(0.0,0.0,-1.0, 0.0))},
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
  	Ray ray{glm::vec3(translate_*glm::vec4(origin_,1.0f)), glm::vec3(rotate_ * glm::vec4(direction, 0.0))};
    //Ray ray{origin_, dir_};
    transf_ =  transformMatrix();
    transf_inv_ = glm::inverse(transf_);
    //ray = transformRray(ray);

  	return ray;
}
glm::mat4 Camera::transformMatrix()
{
  glm::mat4 transformatrix; 
  glm::vec4 e = translate_ * glm::vec4(origin_,1.0);
  transformatrix[3] = e;
  glm::vec4 n = rotate_ * glm::vec4(glm::vec3(dir_),0.0);
  n = glm::vec4(glm::normalize(glm::vec3(n* -1.0f)),0.0);
  transformatrix[2] = n ;
  glm::vec3 u = glm::cross(glm::vec3(n), up_);
  n = glm::normalize(n);
  transformatrix[0] = glm::vec4(( u ),0.0) ;
  glm::vec3 v = glm::normalize(glm::cross(u, glm::vec3(n)));
  transformatrix[1] = glm::vec4(v,0.0);
  //auto erg = transformRay(transformatrix, ray);

  return transformatrix;
}
