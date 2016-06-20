#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>
#include "color.hpp"
#include "ray.hpp"

class Sphere : public Shape 
{
public:
	Sphere();
	Sphere(Color const& clr, std::string name, glm::vec3 const& mp, float radius);
	~Sphere();
	float area() const override;
	float volume() const override;

	//getter 
	glm::vec3 const& get_middle() const;
	float get_radius() const;

	std::ostream& print(std::ostream& os) const;

	bool intersect(Ray const& ray, float& distance) const;

private:
	glm::vec3 middle_;
	float radius_;
};

#endif