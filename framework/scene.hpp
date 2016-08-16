//scene.hpp
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
#include "box.hpp"
#include "sphere.hpp"
#include "camera.hpp"
#include "light.hpp"



struct Scene {
  //OptionalHit(Ray const&) const;
//  Scene(std::vector<std::shared_ptr<Shape>> const& shape,
//                    std::map<std::string, Material> const& material,
//                    Camera const& cam):
//        shapes{shape},
//        materials{material},
//        camera{cam}
//        {}
//


/*  member  */
  std::vector<std::shared_ptr<Shape>> shapes;
  std::vector<Light> lights;
  std::map<std::string, Material> materials;
  Camera camera;
  int width, height;
  std::string filename;
  
};

Scene loadSDF(std::string const& filename);


#endif //scene.hpp
