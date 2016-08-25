#ifndef SCENE_HPP 
#define SCENE_HPP
#include <iostream>
#include <string>
#include <fstream>  //getline
#include <sstream>
#include <map>
#include <memory>
#include <vector>
#include <cmath>
#include "material.hpp"
#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "camera.hpp"
#include "light.hpp"
#include "composite.hpp"



struct Scene {

  //member
  std::shared_ptr<Composite> root;
  std::vector<Light> lights;
  std::map<std::string, Material> materials;
  Camera camera;
  int width, height;
  std::string filename;
  
};

Scene loadSDF(std::string const& filename);

glm::mat4 transform(glm::vec3 const& scale_, glm::vec4 const& rotate_, glm::vec3 const& translate_);
glm::mat4 rotate_Mat(glm::vec4 const& rotate_);
glm::mat4 scale_Mat(glm::vec3 const& scale_);
glm::mat4 translate_Mat(glm::vec3 const& translate_);

#endif 
