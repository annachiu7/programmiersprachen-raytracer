#include "box.hpp"

Box::Box():
Shape::Shape(),
min_{0.0},
max_{0.0}
{}

Box::Box(Material const& mat, std::string const& name, glm::vec3 const& min, glm::vec3 const& max):
Shape::Shape(mat, name),
min_{min},
max_{max}
{}

Box::~Box()
{}



//getter
glm::vec3 const& Box::get_min() const
{
	return min_;
}

glm::vec3 const& Box::get_max() const
{
	return max_;
}

//functions
OptiHit Box::intersect(Ray const& ray) const
{

  OptiHit hit{this};
  float tmin = -INFINITY, tmax = INFINITY;

  float t1 = (min_.x - ray.origin_.x)/ray.direction_.x;
  float t2 = (max_.x - ray.origin_.x)/ray.direction_.x;
  tmin = std::max(tmin,std::min(t1,t2));
  tmax = std::min(tmax,std::max(t1,t2));

  t1 = (min_.y - ray.origin_.y)/ray.direction_.y;
  t2 = (max_.y - ray.origin_.y)/ray.direction_.y;
  tmin = std::max(tmin,std::min(t1,t2));
  tmax = std::min(tmax,std::max(t1,t2));

  t1 = (min_.z - ray.origin_.z)/ray.direction_.z;
  t2 = (max_.z - ray.origin_.z)/ray.direction_.z;
  tmin = std::max(tmin,std::min(t1,t2));
  tmax = std::min(tmax,std::max(t1,t2));

  if (tmax > std::max(0.0F, tmin))
  {
    hit.distance = sqrt(tmin*tmin*(
                      ray.direction_.x*ray.direction_.x +
                      ray.direction_.y*ray.direction_.y +
                      ray.direction_.z*ray.direction_.z ));
    hit.surface_pt = this->calc_surface_pt(ray, hit.distance);
    hit.hit = true;  
    hit.n = this->calc_n(hit);
  }
  return hit;
}


glm::vec3 Box::calc_n(OptiHit const& hit) const
{
  auto surface_pt = hit.surface_pt; 
  if(surface_pt.x == Approx(min_.x))
  {
    return glm::vec3{-1.0,0.0,0.0};
  }
  if(surface_pt.y == Approx(min_.y))
  {
    return glm::vec3{0.0,-1.0,0.0};
  }
  if(surface_pt.z == Approx(min_.z))
  {
    return glm::vec3{0.0,0.0,-1.0};
  }
  if(surface_pt.x == Approx(max_.x))
  {
    return glm::vec3{1.0,0.0,0.0};
  }
  if(surface_pt.y == Approx(max_.y))
  {
    return glm::vec3{0.0,1.0,0.0};
  }
  if(surface_pt.z == Approx(max_.z))
  {
    return glm::vec3{0.0,0.0,1.0};
  }
}


//aufgabe5.5
std::ostream& Box::print(std::ostream& os) const
{
  Shape::print(os) ;
  os << "min:    <" << min_.x << "," << min_.y << "> \n" 
     << "max:    <" << max_.x << "," << max_.y << "> \n" ;
  return os; 
}