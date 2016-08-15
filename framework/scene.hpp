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
//#include "light.hpp"


struct Scene {
  //Scene load_stf(std::string const& A);
  //OptionalHit(Ray const&) const;
  

  std::vector<std::shared_ptr<Shape>> shapes;
 // std::vector<Light> lights;
  std::map<std::string, Material> materials;
  Camera camera;

 
  void sdfloader()
  {
  std::ifstream file;
  file.open("defineMaterial.txt");
  std::string line;
    if(file.is_open())
    {
      while(std::getline(file, line))
      {
        Material mat;

        //std::map<std::string, Material> materialmap;

        std::stringstream ss;
        std::string keyword;

        ss<<line;
        ss>>keyword;
        if (keyword == "define")
        {
          ss>>keyword;
          if (keyword == "material")
          {
            ss>>mat.name_;
            ss>>mat.ka_.r;
            ss>>mat.ka_.g;
            ss>>mat.ka_.b;
            ss>>mat.kd_.r;
            ss>>mat.kd_.g;
            ss>>mat.kd_.b;
            ss>>mat.ks_.r;
            ss>>mat.ks_.g;
            ss>>mat.ks_.b;
            ss>>mat.m_;

            materials[mat.name_]= mat;
          }
          if (keyword == "shape")
          {
            ss>>keyword;
            if (keyword =="box")
            {
              std::string name,color;
              glm::vec3 min, max;

              ss>>name;
              ss>>min.x;
              ss>>min.y;
              ss>>min.z;
              ss>>max.x;
              ss>>max.y;
              ss>>max.z;
              ss>>color;

              //std::cout << box << std::endl;
              std::shared_ptr<Shape> box0 = std::make_shared<Box> (materials[color],name,min,max);
              shapes.push_back(box0);
            }
            if (keyword == "sphere")
            {
              std::string name, color;
              glm::vec3 middlpt;
              float r;

              ss>>name;
              ss>>middlpt.x;
              ss>>middlpt.y;
              ss>>middlpt.z;
              ss>>r;
              ss>>color;

              std::shared_ptr<Shape> sphere0 = std::make_shared<Sphere> (materials[color],name,
                middlpt,r);
              shapes.push_back(sphere0);

            }
          }
          if (keyword == "camera")
          {
            ss>>camera.name_;
            ss>>camera.fov_x_;
            ss>>camera.pos_.x;
            ss>>camera.pos_.y;
            ss>>camera.pos_.z;
          } 
        }
      }
    }
  }

  int width, height;
  std::string filename;
  };
#endif //scene.hpp
