#include "cylinder.hpp"
#include <cmath>
#include <algorithm>

Cylinder::Cylinder():
Shape::Shape(),
bcenter_{0,0,-10},
radius_{1.0f},
height_{1.0f}
{}

Cylinder::Cylinder(Material const& mat, std::string const& name,
		     	   glm::vec3 const& bcenter, float r, float h):
Shape::Shape(),
bcenter_{bcenter},
radius_{r},
height_{h}
{}

//getter
glm::vec3 const& Cylinder::get_bcenter() const
{
	return bcenter_;
}
float Cylinder::get_radius() const
{
	return radius_;
}
float Cylinder::get_height() const
{
	return height_;
}

//functions
OptiHit Cylinder::intersect(Ray const& ray) const
// Ray = o + td
// bcenter = (X,Y,Z)
// intersection = (x,y,z)
// (x-X)^2 + (z-Z)^2 = r^2
// (ox+tdx-X)^2 + (oz+tdz-Z)^2 = r^2
// t^2(dx^2+dz^2) + 2t(dx*(ox-X)+dz(oz-Z)) + ox^2+oz^2+X^2+Z^2
{
	OptiHit hit{this};

	glm::vec3 d = ray.direction_;
	glm::vec3 o = ray.origin_;
	float a = d.x*d.x+d.z*d.z;
	float b = 2*(d.x*(o.x-bcenter_.x)+d.z*(o.z-bcenter_.z));
	float c = o.x*o.x+o.z*o.z+bcenter_.x*bcenter_.x+bcenter_.z*bcenter_.z-radius_*radius_;
	//float b = 2*(o.x*d.x+o.z*d.z), c = o.x*o.x + o.z*o.z-radius_*radius_;

	float q = b*b-4*a*c;
	if (q<0)
	{
		//std::cout << "===== q<0 =====\n";
		return hit;
	} else
	{
		//std::cout << "===== q>=0 =====\n";
		float t1 = (-b+sqrt(q))/(2*a);
		float t2 = (-b-sqrt(q))/(2*a);
		float t;
		if (t1>t2) {std::swap(t1,t2);}  // set t1<t2
		//std::cout << "===== "<<t1<<' '<<t2<<" =====\n";

		if (t2<0) 
		{
			//std::cout << "===== t2<0 =====\n";
			return hit;
		}
		else
		{
			//std::cout << "===== t2>=0 =====\n";
			glm::vec3 p1 = o+t1*d;
			glm::vec3 p2 = o+t2*d;
			glm::vec3 p;
			
			if (t1<0)  // ray origin in the cylinder
			{
				//std::cout << "===== t1<0 =====\n";
				if(bcenter_.y <= p2.y <= bcenter_.y+height_)
				  	{t = t2; p = p2;}
				else 
				{   if (p2.y<bcenter_.y)
					{
						t = (bcenter_.y-o.y)/d.y;
					} else
					{
						t = (bcenter_.y+height_-o.y)/d.y;
					}
					p = o+t*d;
				}
			}

			else // 2 intersections with infinite cylinder
			{
				//std::cout << "===== t1>=0 =====\n";
				if ((p1.y<bcenter_.y||p1.y>bcenter_.y+height_)&&  
					(p2.y<bcenter_.y||p2.y>bcenter_.y+height_))
				{
					return hit;
				}
				else if (bcenter_.y <= p1.y <= bcenter_.y+height_ &&  // intersection with body
					bcenter_.y <= p2.y <= bcenter_.y+height_)
				{
					t = t1;
					p = o+t*d;
				}
				else if (bcenter_.y < p1.y < bcenter_.y+height_)  // intersection with caps
				{
					if (p2.y<bcenter_.y)
					{
						t = (bcenter_.y-o.y)/d.y;
					} else
					{
						t = (bcenter_.y+height_-o.y)/d.y;
					}
					p = o+t*d;
				}
				else
				{
					if (p1.y<bcenter_.y)
					{
						t = (bcenter_.y-o.y)/d.y;
					} else
					{
						t = (bcenter_.y+height_-o.y)/d.y;
					}
					p = o+t*d;
				}
			}

			hit.hit = true;
			hit.distance = t;
			hit.surface_pt = p;
			hit.n = this->calc_n(hit);
			return hit;
		}
	}
}

glm::vec3 Cylinder::calc_n(OptiHit const& hit) const
{
	if (bcenter_.y< hit.surface_pt.y < bcenter_.y+height_)
	{
		glm::vec3 middle = {bcenter_.x, hit.surface_pt.y, bcenter_.z};
		return glm::normalize(hit.surface_pt-middle);
	}
	if (bcenter_.y == hit.surface_pt.y)
	{
		return {0,-1,0};
	}
	if (bcenter_.y+height_ == hit.surface_pt.y)
	{
		return {0,1,0};
	}
}

