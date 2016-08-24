#include "triangle.hpp"

Triangle::Triangle():
  Shape::Shape(),
  a_{0.0},
  b_{0.0},
  c_{0.0}
  {}

Triangle::Triangle(Material const& mat, std::string const& name,
                    glm::vec3 const& a, glm::vec3 const& b,
                    glm::vec3 const& c):
  Shape::Shape(mat,name),
  a_{a},
  b_{b},
  c_{c}
  {}

Triangle::~Triangle()
  {}
