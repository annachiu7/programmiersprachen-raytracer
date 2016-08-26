#include "composite.hpp"

Composite::Composite()
  :Shape::Shape{}
  , shapes_{}
  {}

Composite::Composite(std::string const& name):
  Shape::Shape{name},
  shapes_{}
  {}

Composite::~Composite() {}



OptiHit Composite::intersect(Ray const& ray) const
{
  OptiHit hit;
  OptiHit tmphit;
  for (auto const& shape : shapes_)
  {
    Ray rayman;
    rayman.origin_ = glm::vec3(shape->get_transf_inv()* glm::vec4(ray.origin_,1.0f));
    rayman.direction_ = glm::vec3(shape->get_transf_inv() * glm::vec4(ray.direction_,0.0f));
    tmphit = shape->intersect(rayman);
    if(tmphit.distance < hit.distance)
    {
      hit = tmphit;
    }
  }

  return hit;
}



glm::vec3 Composite::calc_n(OptiHit const& hit) const
{
  return hit.closest_shape->calc_n(hit);
}
 

void Composite::add_shape(std::shared_ptr<Shape>  s)
{
  shapes_.push_back(s);
}
