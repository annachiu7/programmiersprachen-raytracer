#ifndef BUW_CAMERA_HPP
#define BUW_CAMERA_HPP

#include <glm/vec3.hpp>
#include <string>
#include "ray.hpp"

struct Camera
{
	Camera();
	Camera(std::string const& name, double fov_x, glm::vec3 const& origin);
	Camera(std::string const& name, double fov_x, glm::vec3 const& origin, glm::vec3 const& dir, glm::vec3 const& up);

	std::string name_;
	double fov_x_;
	glm::vec3 origin_;
	glm::vec3 dir_;
	glm::vec3 up_;

  	Ray calc_eye_ray(int x, int y, int height, int width);
};


#endif
