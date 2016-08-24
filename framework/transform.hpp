#ifndef BUW_TRANSFORM_HPP
#define BUW_TRANSFORM_HPP

#include <glm/glm.hpp>
#include <string>
#include <math.h>


struct Transform
{
  Transform():
	  name_{""},
    scale_{1.0,1.0,1.0},
    translate_{0.0,0.0,0.0},
    rotate_{0.0,0.0,0.0,0.0}
    {}

  Transform(std::string const& nam,glm::vec3 const& scal,
            glm::vec3 const& trans,glm::vec4 const& rotat):
	  name_{nam},
    scale_{scal},
    translate_{trans},
    rotate_{rotat}
    {}
    
  glm::vec4 world_transform(glm::vec4 const& vec);
   
  std::string name_;
  glm::vec3 scale_, translate_;
  glm::vec4 rotate_;
};

#endif
