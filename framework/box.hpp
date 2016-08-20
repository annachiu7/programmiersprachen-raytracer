#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>

class Box : public Shape{
public:
	Box();
	Box(Material const& mat, std::string const& name, glm::vec3 const& min, glm::vec3 const& max);
	~Box();
	//float area() const override;
	//float volume() const override;

	//getter
	glm::vec3 const& get_min() const;
	glm::vec3 const& get_max() const;
	
	std::ostream& print(std::ostream& os) const override;

	bool does_intersect(Ray const& ray, float& distance) const override;
  OptiHit intersect(Ray const& ray, float& distance) const override;

  glm::vec3 calc_n(OptiHit const& hit) const override;

private:
	glm::vec3 min_;
	glm::vec3 max_;
};

#endif
