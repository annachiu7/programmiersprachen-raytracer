#include "camera.hpp"

Camera::Camera():
name_{""},
pos_{0,0,0},
fov_x_{45}
{}

Camera::Camera(std::string const& name, glm::vec3 const& pos, double fov_x):
name_{name},
pos_{pos},
fov_x_{fov_x}
{}
