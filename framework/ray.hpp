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
	direction_{glm::normalize(dir)},
  inverse_dir_{1.0f/dir.x,1.0f/dir.y,1.0f/dir.z}
	{}

	Ray(glm::vec3 const& orig, glm::vec3 const& dir, float d):
	origin_{orig},
	direction_{glm::normalize(dir)},
  inverse_dir_{1.0f/dir.x,1.0f/dir.y,1.0f/dir.z},
  surface_pt_{orig + dir * d}
	{}
	
	glm::vec3 origin_,inverse_dir_,direction_,surface_pt_;	
};

#endif
	
