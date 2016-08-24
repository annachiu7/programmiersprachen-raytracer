#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include "color.hpp"
#include <iostream>
#include <string>
#include "material.hpp"
#include "ray.hpp"
#include <glm/glm.hpp>
#include "transform.hpp"
//#include "optiHit.hpp"

struct OptiHit;

class Shape
{
public:
	Shape();
	Shape(Material const& mat, std::string const& name);
	Shape(Material const& mat, std::string const& name, Transform const& world_transf,
        Transform const& world_transf_inv);
	Shape(std::string const& name);
	~Shape();
	
	//aufgabe 5.4
	virtual std::ostream& print(std::ostream& os) const;

	//getter
	Material const& get_mat() const;
	std::string const& get_name() const;
  Transform const& get_world_transf() const;
  Transform const& get_world_transf_inv() const;

	//aufgabe 6.3
	virtual OptiHit intersect(Ray const& ray) const = 0 ;

  glm::vec3 calc_surface_pt(Ray const& ray, float distance) const;

  virtual glm::vec3 calc_n(OptiHit const& hit) const = 0;


protected:
	Material mat_;
	std::string name_;
  Transform world_transf_;
  Transform world_transf_inv_;

};

struct OptiHit
{
  OptiHit():
  hit{false},
  distance{10000.0},
  closest_shape{nullptr},
  n{},
  surface_pt{}
  {}

  OptiHit(const Shape* s):
    hit{false},
    distance{10000.0},
    closest_shape(s),
    n{},
    surface_pt{}
  {}

  OptiHit(bool h, float d, const Shape* c, glm::vec3 const& n0, glm::vec3 const& s):
  hit{h},
  distance{d},
  closest_shape{c},
  n{n0},
  surface_pt{s}
  {}
  
  bool hit;//wird in intersect berechnet
  float distance;//wird in intersect berechnet
  const Shape* closest_shape;//wird in intersect berechnet
  glm::vec3 n;
  glm::vec3 surface_pt;
};
//aufgabe 5.4

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif
