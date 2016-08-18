#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include "color.hpp"
#include <iostream>
#include <string>
#include "material.hpp"
#include "ray.hpp"
//#include "optiHit.hpp"
struct OptiHit;
class Shape
{
public:
	Shape();
	Shape(Material const& mat, std::string const& name);
	Shape(std::string const& name);
	~Shape();
	//virtual void draw() const = 0;
  /*
	virtual float area() const = 0;
	virtual float volume() const = 0;
  */ 
	
	//aufgabe 5.4
	virtual std::ostream& print(std::ostream& os) const;

	//getter
	Material const& get_mat() const;
	std::string const& get_name() const;

	//aufgabe 6.3
	virtual bool does_intersect(Ray const& ray, float& t) const = 0 ;
	virtual OptiHit intersect(Ray const& ray, float t) const = 0 ;

  glm::vec3 calc_surface_pt(Ray const& ray, float distance) const;

  virtual glm::vec3 calc_n(OptiHit const& hit) const = 0;


protected:
	Material mat_;
	std::string name_;
};

struct OptiHit
{
  //OptiHit(bool h, float d, Shape* const& c,glm::vec3 const& n, glm::vec3 const& s);
  OptiHit():
  hit{false},
  distance{0.0},
  closest_shape{},
  n{},
  surface_pt{}
  {}

  OptiHit(bool h, float d, Shape* const& c,glm::vec3 const& n0, glm::vec3 const& s):
  hit{h},
  distance{d},
  closest_shape{c},
  n{n0},
  surface_pt{s}
  {}
  
  bool hit;//wird in calc_optihit berechnet
  float distance;//wird in calc_optihit berechnet
  Shape* closest_shape;//wird in calc_optihit berechnet
  glm::vec3 n;
  glm::vec3 surface_pt;
  float angle;//hit_angle between n and ray
};
//aufgabe 5.4

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif
