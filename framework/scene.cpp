#include "scene.hpp"

struct Scene{
  
  Scene load_stf(std::string const& A){

    std::ifstream file;
    file.open(A);
    std::string line;
    
    if (file.is_open())
    {
      while(std::getline(file, line))
      {
        Material mat;
        std::map<std::string, Material> materialmap;
      
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
    
            materialmap[mat.name_] = mat;
    
            std::cout << mat << std::endl;
          }
        }
        else{std::cout << "undefined material! \n";}
      }
  }

    return 0;
  }
