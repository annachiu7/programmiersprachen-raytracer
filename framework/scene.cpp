#include "scene.hpp"

Scene loadSDF(std::string const& filename)
{
  Scene scene;

  std::ifstream file;
  file.open(filename);
  std::string line;
    if(file.is_open())
    {
      while(std::getline(file, line))
      {
        Material mat;

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

            scene.materials[mat.name_]= mat;
            std::cout << "another material added to scene...\n";
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
              std::shared_ptr<Shape> box0 = std::make_shared<Box> (scene.materials[color],name,min,max);
              scene.shapes.push_back(box0);
              std::cout << "another box added to scene...\n";
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

              std::shared_ptr<Shape> sphere0 = std::make_shared<Sphere> (scene.materials[color],name,
                middlpt,r);
              scene.shapes.push_back(sphere0);
              std::cout << "another sphere added to scene...\n";
            }
          }
          if (keyword == "camera")
          {
            ss>>scene.camera.name_;
            ss>>scene.camera.fov_x_;
            ss>>scene.camera.pos_.x;
            ss>>scene.camera.pos_.y;
            ss>>scene.camera.pos_.z;
            std::cout << "another camera added to scene...\n";
          } 
        }
      }
    }
  return scene;
}