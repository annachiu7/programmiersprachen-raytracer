#ifndef OPTIHIT_HPP
#define OPTIHIT_HPP

#include <glm/vec3.hpp>
#include "scene.hpp"

struct OptiHit
{
  bool hit;//wird in calc_optihit berechnet
  float distance;//wird in calc_optihit berechnet
  std::shared_ptr<Shape> closest_shape;//wird in calc_optihit berechnet
  glm::vec3 n;
  glm::vec3 surface_ptr;
  float angle;//hit_angle between n and ray
};

OptiHit calc_optihit(Scene const& scene, Ray const& ray);
//float calc_distance();
//glm::vec3 calc_surface_ptr();
//glm::vec3 calc_n();
//bool calc_hit();
//std::shared_ptr<Shape> calc_closest_ptr();
#endif
