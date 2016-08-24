#include "transform.hpp"

glm::vec4 Transform::world_transform(glm::vec4 const& vec)
{
  glm::mat4 trans(1.0f); 
  trans[3] = glm::vec4(glm::vec3(translate_),1.0f);
  auto erg = trans * vec;
  glm::mat4 scale(1.0f);
  erg = scale * erg;
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
  erg = rotate * erg;
  return erg;
}
