#ifndef OPTIHIT_HPP
#define OPTIHIT_HPP

#include <glm/vec3.hpp>
#include "scene.hpp"

struct OptiHit
{

  bool hit;
  float distance;
  shared_ptr<Shape> shape;
  glm::vec3 n;
  gml::vec3 surface_ptr;
  float angle;//hit_angle between n and ray
  //funktionen
  //normale berechnen box und sphere
  //hit berechnen

  hit = shapes->intersect

};


#endif
