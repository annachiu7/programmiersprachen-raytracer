#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP
#include "shape.hpp" 
#include <vector>
#include <map>
#include <glm/vec3.hpp>
#include <memory>
//#include "optiHit.hpp"
#include "shape.hpp"


class Composite : public Shape
{
public:
  Composite();
  Composite(std::string const& name);
  ~Composite();

	bool does_intersect(Ray const& ray, float& distance) const override;
  OptiHit intersect(Ray const& ray, float& distance) const override;
  glm::vec3 calc_n(OptiHit const& hit) const override;
  void add_shape(std::shared_ptr<Shape>  s);

private:
  std::vector<std::shared_ptr<Shape>> shapes_;
};
#endif
