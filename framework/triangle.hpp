#ifndef BUW_TRIANGLE_HPP
#define BUW_TRIANGLE_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <catch.hpp>
#include <algorithm>

Class Triangle : public Shape{
public:
  Triangle();
  Triangle(Material const& mat, std::string const& name,
            glm::vec3 const& a, glm::vec3 const& b,
            glm::vec3 const& c);
  ~Triangle();

  //getter
  glm::vec3 const& get_a() const;
  glm::vec3 const& get_b() const;
  glm::vec3 const& get_c() const;
  
private:
  glm::vec3 a_,b_,c_;
};
#endif
