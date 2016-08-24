#include "scene.hpp"
#include "transform.hpp"

Scene loadSDF(std::string const& filename)
{
  Scene scene;
  std::map<std::string,std::shared_ptr<Shape>> allobjects;
  std::map<std::string,std::shared_ptr<Shape>> tmp_shapes;
  //float s1=1.0f,s2=1.0f,s3=1.0f,rw=0.0f,r1=0,r2=0,r3=0,t1=0,t2=0,t3=0;
  glm::vec3 scale, translate;
  glm::vec4 rotate;

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

              std::shared_ptr<Shape> box0 = std::make_shared<Box> (scene.materials[color],name,min,max);
              allobjects[name] = box0;
              tmp_shapes = allobjects;
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

              std::shared_ptr<Shape> sphere0 = std::make_shared<Sphere> (scene.materials[color],name, middlpt,r);
              allobjects[name] = sphere0;
              tmp_shapes = allobjects;
              std::cout << "another sphere added to scene...\n";
            }
            if (keyword == "composite")
            {
              std::string name, shape;

              ss>>name;
              auto comp0 = std::make_shared<Composite> (name);
              while (ss>>shape)
              {
                comp0->add_shape(tmp_shapes[shape]);
                tmp_shapes.erase(shape);
              }
              tmp_shapes[name] = comp0;
            }
          }


          if (keyword == "camera")
          {
            ss>>scene.camera.name_;
            ss>>scene.camera.fov_x_;
            ss>>scene.camera.origin_.x;
            ss>>scene.camera.origin_.y;
            ss>>scene.camera.origin_.z;
            ss>>scene.camera.dir_.x;
            ss>>scene.camera.dir_.y;
            ss>>scene.camera.dir_.z;
            ss>>scene.camera.up_.x;
            ss>>scene.camera.up_.y;
            ss>>scene.camera.up_.z;

            std::cout << "another camera added to scene...\n";
          } 
          if (keyword == "light")
          {
          	std::string name;
          	glm::vec3 pos;
          	Color ambient;
          	Color diffuse;

          	ss>>name;
          	ss>>pos.x;
          	ss>>pos.y;
          	ss>>pos.z;
          	ss>>ambient.r;
          	ss>>ambient.g;
          	ss>>ambient.b;
          	ss>>diffuse.r;
          	ss>>diffuse.g;
          	ss>>diffuse.b;

            Light* light = new Light{name,pos,ambient,diffuse};
            scene.lights.push_back(*light);
            std::cout << "another light added to scene...\n";

          }
        }
#if 1
        else if (keyword == "transform")
        {
          std::string shapename;
          ss>>shapename;
          ss>>keyword;
          if (keyword == "scale")
          {
            ss>>scale.x;
            ss>>scale.y;
            ss>>scale.z;
          } else { scale={1,1,1}; }

          if (keyword == "rotate")
          {
            ss>>rotate.x;
            ss>>rotate.y;
            ss>>rotate.z;
            ss>>rotate.w;
          } else { rotate={0,0,0,0}; }

          if (keyword == "translate")
          {
            ss>>translate.x;
            ss>>translate.y;
            ss>>translate.z;
          } else { translate={0,0,0}; }

          //allobjects[name].set_transf()

        }
#endif        
        else if (keyword == "render")
        {
        	ss>>keyword;
        	ss>>scene.filename;
        	ss>>scene.width;
        	ss>>scene.height;

        	std::cout << "rendering taking place...\n" ;
        }
      }
    }
  auto root = std::make_shared<Composite> ("root");
  for (auto const& shape : tmp_shapes)
  {
    root->add_shape(shape.second);
  }
  scene.root = root;
  return scene;
}

