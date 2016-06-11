#include "sphere.hpp"
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <cmath>
#include "color.hpp"


Sphere::Sphere():
middle_{0.0},
radius_{0.0f}
{}

Sphere::Sphere(Color clr, std::string name, glm::vec3 mp, float radius):
middle_{mp},
radius_{radius}
{
	color_ = clr;
	name_ = name;
}

float Sphere::area() const
{
	return 4*M_PI*radius_*radius_;
}

float Sphere::volume() const
{
	return radius_*radius_*radius_*4/3*M_PI;
}



//getter
glm::vec3 const& Sphere::get_middle() const
{
	return middle_;
}

float const& Sphere::get_radius() const
{
	return radius_;
}