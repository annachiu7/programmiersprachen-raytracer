#include "shape.hpp"


Shape::Shape():
mat_{},
name_{""}
{}

Shape::Shape(Material const& mat, std::string const& name):
mat_{mat},
name_{name}
{}

Shape::~Shape()
{}


//aufgabe 5.4
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

std::ostream& operator<<(std::ostream& os, Shape const& s)
{
	return s.print(os);
}
