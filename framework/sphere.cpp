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


//getter{{{
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
//}}}
// aufgabe5.6

OptiHit Sphere::intersect(Ray const& rayman) const
{
  float t = 0.0;
  Ray ray = transformRay(get_transf_inv(),rayman);
	bool res = glm::intersectRaySphere(ray.origin_, ray.direction_,
    middle_, radius_*radius_, t);
  if (res)
  {

    glm::vec3 p = ray.origin_ + t * ray.direction_;
    p = glm::vec3(get_transf()*glm::vec4(p,1.0));
    glm::vec3 n = glm::normalize(p - middle_);
    n = glm::normalize(glm::vec3(glm::transpose(get_transf_inv())*glm::vec4(n, 0.0)));
    return OptiHit{true, t, this, n, p};
  }
	return OptiHit{};
}


glm::vec3 Sphere::calc_n(OptiHit const& hit) const
{
  glm::vec3 p = hit.surface_pt;
  return glm::normalize(p - middle_);

}
