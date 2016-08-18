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

/*
float Box::area() const
{
	auto l = max_.x-min_.x;
	auto h = max_.y-min_.y;
	auto b = max_.z-min_.z;
	return 2*(l*h + l*b + h*b);
}

float Box::volume() const
{
	return std::abs((max_.x-min_.x)*(max_.y-min_.y)*(max_.z-min_.z));
}
*/


//getter
glm::vec3 const& Box::get_min() const
{
	return min_;
}

glm::vec3 const& Box::get_max() const
{
	return max_;
}

//aufgabe5.5
std::ostream& Box::print(std::ostream& os) const
{
	Shape::print(os) ;
	os << "min:    <" << min_.x << "," << min_.y << "> \n" 
	   << "max:    <" << max_.x << "," << max_.y << "> \n" ;
	return os; 
}


OptiHit Box::intersect(Ray const& ray, float distance) const
{
  OptiHit hit;
  hit.hit = this->does_intersect(ray, distance);
  if (hit.hit)
  {
    hit.closest_shape = this;
    hit.surface_pt = this->calc_surface_pt(ray, distance);
    hit.n = this->calc_n(hit); 
  }
  return hit;
}


//aufgabe5.10
bool Box::does_intersect(Ray const& ray, float& distance) const
{
	float tnear,tfar;
	distance = -1;

	if (ray.direction_.x != 0.0)
	{
		float t1 = (min_.x - ray.origin_.x) / ray.direction_.x;
		float t2 = (max_.x - ray.origin_.x) / ray.direction_.x;
		tfar = std::max(t1,t2);
		tnear = std::min(t1,t2);
	}
	else 
	{
		if(min_.x > ray.origin_.x || max_.x < ray.origin_.x) {return false;}
	}

	if (ray.direction_.y != 0.0)
	{
		float t1 = (min_.y - ray.origin_.y) / ray.direction_.y;
		float t2 = (max_.y - ray.origin_.y) / ray.direction_.y;
		float tnear = std::max(tnear, std::min(t1,t2));
		float tfar = std::min(tfar, std::max(t1,t2));
		if (tnear > tfar)
		{
			return false;
		}
	}
	else 
	{
		if(min_.y > ray.origin_.y || max_.y < ray.origin_.y) {return false;}
	}

	if (ray.direction_.z != 0.0)
	{
		float t1 = (min_.z - ray.origin_.z) / ray.direction_.z;
		float t2 = (max_.z - ray.origin_.z) / ray.direction_.z;
		tnear = std::max(tnear, std::min(t1,t2));
		tfar = std::min(tfar, std::max(t1,t2));
		if (tnear > tfar)
		{
			return false;
		}
	}
	else 
	{
		if(min_.z > ray.origin_.z || max_.z < ray.origin_.z) {return false;}
	}

	distance = tnear*sqrt(ray.direction_.x*ray.direction_.x +
					      ray.direction_.y*ray.direction_.y +
					      ray.direction_.z*ray.direction_.z);
	return true;
}

glm::vec3 Box::calc_n(OptiHit const& hit) const
{
  glm::vec3 debug{0,0,1};
  return debug;
}
