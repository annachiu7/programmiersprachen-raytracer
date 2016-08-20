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

bool Composite::does_intersect(Ray const& ray, float& distance) const
{
  OptiHit hit;
  float nearest_distance = 10000.0;
  hit.closest_shape = nullptr;
  hit.distance = 0.0;
  for (auto const& shape : shapes_) {
    hit.hit = shape->does_intersect(ray, hit.distance);
    if (hit.hit && 0 < hit.distance && hit.distance < nearest_distance) {
      nearest_distance=hit.distance;
      hit.closest_shape = shape.get();
    }
  }
  return hit.hit;
}


OptiHit Composite::intersect(Ray const& ray, float& distance) const
{
  OptiHit hit;
  float nearest_distance = 10000.0;
  hit.closest_shape = nullptr;
  hit.distance = 0.0;
  for (auto const& shape : shapes_) {
    hit.hit = shape->does_intersect(ray, hit.distance);
    if (hit.hit && 0 < hit.distance && hit.distance < nearest_distance) {
      nearest_distance=hit.distance;
      hit.closest_shape = shape.get();
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
