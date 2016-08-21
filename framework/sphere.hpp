#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP
#include "shape.hpp"
#include <iostream>
#include <glm/vec3.hpp>

class Sphere : public Shape{
public:
	Sphere();
	Sphere(Material const& mat, std::string const& name, glm::vec3 const& mp, float radius);
	~Sphere();

	//getter 
	glm::vec3 const& get_middle() const;
	float get_radius() const;

	std::ostream& print(std::ostream& os) const override;

  OptiHit intersect(Ray const& ray) const override;

  glm::vec3 calc_n(OptiHit const& hit) const override;

private:
	glm::vec3 middle_;
	float radius_;
};

#endif
