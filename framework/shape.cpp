#include "shape.hpp"


Shape::Shape():
  mat_{},
  name_{""}
  {}

Shape::Shape(Material const& mat, std::string const& name):
  mat_{mat},
  name_{name}
  {}

Shape::Shape(Material const& mat, std::string const& name, 
              glm::mat4 const& world_transf,
              glm::mat4 const& world_transf_inv):
  mat_{mat},
  name_{name},
  world_transf_{world_transf},
  world_transf_inv_{world_transf_inv}
  {}
  

Shape::Shape(std::string const& name):
  mat_{},
  name_{name}
  {}

Shape::~Shape()
  {}


//aufgabe 5.4{{{
std::ostream& Shape::print(std::ostream& os) const
{
	os << "name:      " << name_ << "\n"
	   << "material:  " << mat_ << "\n"; 
	return os;
}

Material const& Shape::get_mat() const
{
	return mat_;
}

std::string const& Shape::get_name() const
{
	return name_;
}

glm::mat4 const& Shape::get_world_transf() const
{
  return world_transf_;
}

glm::mat4 const& Shape::get_world_transf_inv() const
{
  return world_transf_inv_;
}

std::ostream& operator<<(std::ostream& os, Shape const& s)
{
	return s.print(os);
}


glm::vec3 Shape::calc_surface_pt(Ray const& ray, float distance) const
{
  glm::vec3 s_pt{ray.origin_ + ray.direction_*distance};
  return s_pt;
}
//}}}
