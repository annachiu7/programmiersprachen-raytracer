#ifndef BUW_TRANSFORM_HPP
#define BUW_TRANSFORM_HPP

#include <glm/glm.hpp>
#include <string>
#include <math.h>


struct Transform
{
  Transform();
//Camera transform construkter, da 
//hier keine scale benoetigt wird
  Transform(std::string const& nam,glm::vec3 const& trans,
              glm::vec4 const& rotat);

  Transform(std::string const& nam,glm::vec3 const& scal,
            glm::vec3 const& trans,glm::vec4 const& rotat);
    
  glm::mat4 world_transform();
   
  std::string name_;
  glm::vec3 scale_, translate_;
  glm::vec4 rotate_;
};

#endif
