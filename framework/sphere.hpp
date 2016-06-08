#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>

class Sphere : public Shape 
{
public:
	Sphere();
	Sphere(glm::vec3 mp, float radius);
	float area() const override;
	float volume() const override;

	//getter 
	glm::vec3 const& get_middle() const;
	float const& get_radius() const;

private:
	glm::vec3 middel_;
	float radius_;
};

#endif