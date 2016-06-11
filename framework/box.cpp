#include "box.hpp"
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <cmath>
#include "color.hpp"



Box::Box():
min_{0.0},
max_{0.0}
{}

Box::Box(Color clr, std::string name, glm::vec3 min, glm::vec3 max):
min_{min},
max_{max}
{
	color_ = clr;
	name_ = name;
}

float Box::area() const
{
	auto l = max_.x-min_.x;
	auto h = max_.y-min_.y;
	auto b = max_.z-min_.z;
	return 2*(l*h + l*b + h*b);
}

float Box::volume() const
{
	return std::abs((max_.x-min_.x)*(max_.y-min_.y)*(max_.z-min_.z));
}


//getter
glm::vec3 const& Box::get_min() const
{
	return min_;
}

glm::vec3 const& Box::get_max() const
{
	return max_;
}