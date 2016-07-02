//scene.hpp
#ifndef SCENE_HPP 
#define SCENE_HPP
#include <iostream>
#include <string>
#include <fstream>  //getline
#include <sstream>
#include <map>
#include "material.hpp"

struct Scene {
  Scene load_stf(std::string const& A);
  int width, height;
  std::string filename;
  }
#endif //scene.hpp
