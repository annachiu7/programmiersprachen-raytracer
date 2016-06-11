#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>
#include "color.hpp"

class Box : public Shape
{
public:
	Box();
	Box(Color clr, std::string name, glm::vec3 min, glm::vec3 max);
	float area() const override;
	float volume() const override;

	//getter
	glm::vec3 const& get_min() const;
	glm::vec3 const& get_max() const;

private:
	glm::vec3 min_;
	glm::vec3 max_;
};

#endif