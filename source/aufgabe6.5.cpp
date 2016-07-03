#include <iostream>
#include <string>
#include "material.hpp"
#include <fstream>  //getline
#include <sstream>
#include <map>
#include <vector>
#include "box.hpp"
#include "sphere.hpp"

int main(int argc, char const *argv[])
{
	std::ifstream file;
	file.open("../framework/defineMaterial.txt");
	std::string line;
	
	if (file.is_open())
	{
		while(std::getline(file, line))
		{
			Material mat;
      //Box box;
      //Sphere sphere;

			std::map<std::string, Material> materialmap;
      //std::vector<std::shared_ptr<Shape>> shapevec;
		
			std::stringstream ss;
			std::string keyword;
		
			ss<<line;
			ss>>keyword;
			if (keyword == "define")
			{
				ss>>keyword;
				if (keyword == "material")//{{{
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
				}//}}}
//        if (keyword == "shape")
//        {
//          ss>>keyword;
//          if (keyword == "box")
//          {
//            ss>>box.name_;
//            ss>>box.min().x;
//            ss>>box.min().y;
//            ss>>box.min().z;
//
//            ss>>box.max().x;
//            ss>>box.max().y;
//            ss>>box.max().z;
//
//            box.mat[red];
//
//
//          }
//        }

			}
			else{std::cout << "undefined material! \n";}
		}
}

	return 0;
}
