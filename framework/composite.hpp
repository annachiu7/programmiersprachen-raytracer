#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP
#include "shape.hpp" 
#include <vector>
#include <map>
#include <glm/vec3.hpp>
#include <memory>
#include "optiHit.hpp"


class Composite : public Shape
{
public:
  Composite();
  Composite(std::string const& name);
  ~Composite();

	bool intersect(Ray const& ray, float& distance) const override;
 // OptiHit intersect(Ray const& ray, float distance) const override;

private:
  std::vector<std::shared_ptr<Composite>> shapes_;
  std::string name_; 
};
#endif
