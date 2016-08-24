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
  std::map<std::string, Transform> transforms;
  std::map<std::string, Material> materials;
  Camera camera;
  int width, height;
  std::string filename;
  
};

Scene loadSDF(std::string const& filename);
glm::mat4 transform(float s1,s2,s3,rw,r1,r2,r3,t1,t2,t3)
{
  glm::mat4 trans(1.0f); 
  trans[3] = glm::vec4(glm::vec3(t1,t2,t3),1.0f);
  //auto erg = trans * vec;
  glm::mat4 scale(1.0f);
  scale[0][0] = s1;
  scale[1][1] = s2;
  scale[2][2] = s3;
  glm::mat4 rotate (1.0f);
  if(r1 == 1)
  {
    rotate[1][1] = cos(rw);
    rotate[2][1] = -sin(rw);
    rotate[1][2] = sin(rw);
    rotate[2][2] = cos(rw);
  }
  if(r2== 1)
  {
    rotate[0][0] = cos(rw);
    rotate[0][2] = -sin(rw);
    rotate[2][0] = sin(rw);
    rotate[2][2] = cos(rw);
  }
  if(r3 == 1)
  {
    rotate[0][0] = cos(rw);
    rotate[1][0] = -sin(rw);
    rotate[0][1] = sin(rw);
    rotate[1][1] = cos(rw);
  }
  //erg = rotate * erg;
  //erg = scale * erg;
  return trans*rotate*scale;
}


#endif 
