#include "composite.hpp"

Composite::Composite()
  : name_{""}
  , shapes_{}
  {}

Composite::Composite(std::string const& name):
  name_{"name"},
  shapes_{}
  {}

Composite::~Composite() {}

bool Composite::intersect(Ray const& ray, float& distance) const
{
  OptiHit hit;
  float nearest_distance = 10000.0;
  hit.closest_shape = nullptr;
  hit.distance = 0.0;
  for (auto const& shape : shapes_) {
    hit.hit = shape->intersect(ray, hit.distance);
    if (hit.hit && 0 < hit.distance && hit.distance < nearest_distance) {
      nearest_distance=hit.distance;
      hit.closest_shape = shape.get();
    }
  }
  return hit.hit;
}
//OptiHit intersect(Ray const& ray, float distance) const
//{
//  OptiHit hit;
//  return hit;
//}
