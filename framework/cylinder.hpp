#ifndef BUW_CYLINDER_HPP
#define BUW_CYLINDER_HPP
#include "shape.hpp"

class Cylinder : public Shape
{
public:
	Cylinder();
	Cylinder(Material const& mat, std::string const& name,
		     glm::vec3 const& bcenter, float r, float h);

	//getter
	glm::vec3 const& get_bcenter() const;
	float get_radius() const;
	float get_height() const;

	//functions
  	OptiHit intersect(Ray const& ray) const override;
  	glm::vec3 calc_n(OptiHit const& hit) const override;

private:
	glm::vec3 bcenter_;
	float radius_;
	float height_;	
};

#endif