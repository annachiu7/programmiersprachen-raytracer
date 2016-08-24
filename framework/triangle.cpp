#include "triangle.hpp"

Triangel::Triangel():
  Shape::Shape(),
  a_{0.0},
  b_{0.0},
  b_{0.0}
  {}

Triangel::Triangel(Material const& mat, std::string const& name,
                    glm::vec3 const& a, glm::vec3 const& b,
                    glm::vec3 const& c):
  Shape::Shape(mat,name),
  a_{a},
  b_{b},
  b_{c}
  {}
