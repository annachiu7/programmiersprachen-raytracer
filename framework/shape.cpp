#include "shape.hpp"
#include "color.hpp"


Shape::Shape():
name_{""},
color_{0,0,0}
{}



Color const& Shape::get_color() const
{
	return color_;
}

std::string const& Shape::get_name() const
{
	return name_;
}