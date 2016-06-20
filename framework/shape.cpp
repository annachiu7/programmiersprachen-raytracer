#include "shape.hpp"
#include "color.hpp"
#include <iostream>


Shape::Shape():
color_{0,0,0},
name_{""}
{
	//std::cout<<"construct class shape"<<std::endl;
}

Shape::Shape(Color const& clr, std::string name):
color_{clr},
name_{name}
{
	//std::cout<<"construct class shape"<<std::endl;
}

Shape::~Shape()
{
	//std::cout<<"destruct class shape"<<std::endl;
}


//aufgabe 5.4
std::ostream& Shape::print(std::ostream& os) const
{
	os << "name:   " << name_ << "\n"
	   << "color:  <" << color_.r << "," << color_.g << ","<< color_.b << "> \n"; 
	return os;
}

Color const& Shape::get_color() const
{
	return color_;
}

std::string const& Shape::get_name() const
{
	return name_;
}

std::ostream& operator<<(std::ostream& os, Shape const& s)
{
	return s.print(os);
}