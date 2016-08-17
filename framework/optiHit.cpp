#include "optiHit.hpp"

OptiHit calc_optihit(Scene const& scene,Ray const& ray)
{
  OptiHit optihit;
  float nearest_distance = 10000.0;
  optihit.closest_shape = nullptr;
  optihit.distance = 0.0;
  for (auto const& shape : scene.shapes) {
    optihit.hit = shape->intersect(ray, optihit.distance);
    if (optihit.hit && 0 < optihit.distance && optihit.distance < nearest_distance) {
      nearest_distance=optihit.distance;
      optihit.closest_shape = shape;
    }
  }
}
