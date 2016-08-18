#include "optiHit.hpp"

OptiHit calc_optihit(Scene const& scene,Ray const& ray)
{
  OptiHit hit;

  float nearest_distance = 10000.0;
  hit.closest_shape = nullptr;
  hit.distance = 0.0;

  for (auto const& shape : scene.shapes) // iteration through all shapes, find the nearest intersection
  {
    hit.hit = shape->intersect(ray, hit.distance);
    if (hit.hit && 0 < hit.distance && hit.distance < nearest_distance) 
    {
      nearest_distance = hit.distance;
      hit.closest_shape = shape.get();
    }
  }
  return hit;
}
