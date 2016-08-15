#ifndef BUW_CAMERA_HPP
#define BUW_CAMERA_HPP

#include <glm/vec3.hpp>
#include <string>
#include "ray.hpp"

class Camera
{
public:
	Camera();
	Camera(std::string const& name, glm::vec3 const& pos, double fov_x);
	~Camera();
private:
	std::string name_;
	glm::vec3 pos_;
	double fov_x_;
};


#endif