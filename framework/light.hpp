#ifndef BUW_LIGHT_HPP
#define BUW_LIGHT_HPP

#include <glm/vec3.hpp>
#include <string>
#include "color.hpp"


struct Light
{
	Light():
	name_{""},
	pos_{0,0,0},
	la_{0.2f,0.2f,0.2f},
	ld_{1,1,1}
	{}	

	Light(std::string const& name, glm::vec3 const& pos, Color const& la, Color const& ld):
	name_{name},
	pos_{pos},
	la_{la},
	ld_{ld}
	{}

	std::string name_;
	glm::vec3 pos_;
	Color la_;
	Color ld_;
};

#endif