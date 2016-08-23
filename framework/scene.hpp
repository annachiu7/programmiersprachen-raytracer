#ifndef SCENE_HPP 
#define SCENE_HPP
#include <iostream>
#include <string>
#include <fstream>  //getline
#include <sstream>
#include <map>
#include <memory>
#include <vector>
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


#endif 
