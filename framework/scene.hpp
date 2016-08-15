//scene.hpp
#ifndef SCENE_HPP 
#define SCENE_HPP
#include <iostream>
#include <string>
#include <fstream>  //getline
#include <sstream>
#include <map>
#include <memory>
#include "material.hpp"
#include "shape.hpp"
//#include "light.hpp"
//#include "camera.hpp"


struct Scene {
  //Scene load_stf(std::string const& A);
  //OptionalHit(Ray const&) const;

  std::vector<std::shared_ptr<Shape>> shapes;
 // std::vector<Light> lights;
  std::map<std::string, Material> materials;
  //Camera camera;

 
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
              int minx,miny,minz,maxx,maxy,maxz;

              ss>>name;
              ss>>minx;
              ss>>miny;
              ss>>minz;
              ss>>maxx;
              ss>>maxy;
              ss>>maxz;
              ss>>color;

              Box box{materials[color],name,{minx,miny,minz},{maxx,maxy,maxz}};
              std::cout << box << std::endl;
              //std::shared_ptr<Shape> box0 = std::make_shared<Box> (materials[color],name,{minx,miny,minz},{maxx,maxy,maxz});
              //shapes.push_back(box0);
            }
          }
        }
      }
    }
  }

  int width, height;
  std::string filename;
  };
#endif //scene.hpp
