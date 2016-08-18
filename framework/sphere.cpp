#include "sphere.hpp"

Sphere::Sphere():
Shape::Shape(),
middle_{0.0},
radius_{1.0f}
{}

Sphere::Sphere(Material const& mat, std::string const& name, glm::vec3 const& mp, float radius):
Shape::Shape(mat, name),
middle_{mp},
radius_{radius}
{}

Sphere::~Sphere()
{}

//float Sphere::area() const
//{
//	return 4*M_PI*radius_*radius_;
//}
//
//float Sphere::volume() const
//{
//	return radius_*radius_*radius_*4/3*M_PI;
//}



//getter
glm::vec3 const& Sphere::get_middle() const
{
	return middle_;
}

float Sphere::get_radius() const
{
	return radius_;
}

// aufgabe5.5
std::ostream& Sphere::print(std::ostream& os) const
{
	Shape::print(os) ;
	os << "middle: <" << middle_.x << "," << middle_.y << "> \n" 
	   << "radius: " << radius_ <<"\n" ;
	return os; 
}

// aufgabe5.6

OptiHit Sphere::intersect(Ray const& ray, float distance) const
{
  OptiHit hit;
	hit.hit = glm::intersectRaySphere(ray.origin_, ray.direction_, middle_, radius_*radius_, distance);
  if (hit.hit)
  {
    hit.closest_shape = this;
    hit.surface_pt = this->calc_surface_pt(ray, distance);
    hit.n = this->calc_n(hit);
  }
	return hit;
}

bool Sphere::does_intersect(Ray const& ray, float& distance) const  			// change the value of distance
{
  OptiHit hit;
	hit.hit = glm::intersectRaySphere(ray.origin_, ray.direction_, middle_, radius_*radius_, distance);
  // if (hit.hit)
  //   hit.closest_shape = this;
  //   hit.n =
  //   hit.surface_pt =
	return hit.hit;
}

glm::vec3 Sphere::calc_n(OptiHit const& hit) const
{
  glm::vec3 p = hit.surface_pt;
  return glm::normalize(p - middle_);

}
