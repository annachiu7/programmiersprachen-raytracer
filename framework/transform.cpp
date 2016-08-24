#include "transform.hpp"

Transform::Transform():
  name_{""},
  scale_{1.0,1.0,1.0},
  translate_{0.0,0.0,0.0},
  rotate_{0.0,0.0,0.0,0.0}
  {}

Transform::Transform(std::string const& nam,glm::vec3 const& trans,
            glm::vec4 const& rotat):
  name_{nam},
  scale_{1.0,1.0,1.0},
  translate_{trans},
  rotate_{rotat}
  {}

Transform::Transform(std::string const& nam,glm::vec3 const& scal,
          glm::vec3 const& trans,glm::vec4 const& rotat):
  name_{nam},
  scale_{scal},
  translate_{trans},
  rotate_{rotat}
  {}

glm::mat4 Transform::world_transform()
{
  glm::mat4 trans(1.0f); 
  trans[3] = glm::vec4(glm::vec3(translate_),1.0f);
  //auto erg = trans * vec;
  glm::mat4 scale(1.0f);
  scale[0][0] = scale_.x;
  scale[1][1] = scale_.y;
  scale[2][2] = scale_.z;
  glm::mat4 rotate (1.0f);
  if(rotate_.y == 1)
  {
    rotate[1][1] = cos(rotate_.x);
    rotate[2][1] = -sin(rotate_.x);
    rotate[1][2] = sin(rotate_.x);
    rotate[2][2] = cos(rotate_.x);
  }
  if(rotate_.z == 1)
  {
    rotate[0][0] = cos(rotate_.x);
    rotate[0][2] = -sin(rotate_.x);
    rotate[2][0] = sin(rotate_.x);
    rotate[2][2] = cos(rotate_.x);
  }
  if(rotate_.w == 1)
  {
    rotate[0][0] = cos(rotate_.x);
    rotate[1][0] = -sin(rotate_.x);
    rotate[0][1] = sin(rotate_.x);
    rotate[1][1] = cos(rotate_.x);
  }
  //erg = rotate * erg;
  //erg = scale * erg;
  return trans*rotate*scale;
}
