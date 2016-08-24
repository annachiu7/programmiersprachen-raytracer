#ifndef BUW_TRIANGLE_HPP
#define BUW_TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape{
public:
	Triangle();
	Triangle(glm::vec3);

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