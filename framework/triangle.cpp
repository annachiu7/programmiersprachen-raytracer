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

//getter
glm::vec3 const& Triangle::get_a() const
{
  return a_;
}
glm::vec3 const& Triangle::get_b() const
{
  return b_;
}
glm::vec3 const& Triangle::get_c() const
{
  return c_;
}

//functions
OptiHit Triangle::intersect(Ray const& ray) const
{
  glm::vec3 pos;
  float t;
  bool res = glm::intersectRayTriangle(ray.origin_, ray.direction_,
                                     a_, b_, c_, pos );
  if (res)
  {
    //float t = (pos - ray.origin_)/ray.direction_;
    glm::vec3 n = glm::normalize(glm::cross(a_-b_, a_-c_));
    return OptiHit{true, t, this, n, pos};
  }
  return OptiHit{};
}

glm::vec3 Triangle::calc_n(OptiHit const& hit) const
{
  glm::vec3 n = glm::normalize(glm::cross(a_-b_, a_-c_));
  return n;
}

