#ifndef BUW_RAY_HPP
#define BUW_RAY_HPP
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include <glm/vec3.hpp>

struct Ray
{
	Ray():
	origin_{0,0,0},
	direction_{1,0,0}
	{}

	Ray(glm::vec3 const& orig, glm::vec3 const& dir):
	origin_{orig},
	direction_{glm::normalize(dir)}
	{}

	Ray(glm::vec3 const& orig, glm::vec3 const& dir, float d):
	origin_{orig},
	direction_{glm::normalize(dir)},
    surface_pt_{orig + direction_ * d}
	{}
	
	glm::vec3 origin_,direction_,surface_pt_;	
};

Ray transformRay(glm::mat4 const& mat, Ray const& ray);

#endif
	
