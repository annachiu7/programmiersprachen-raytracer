#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include "color.hpp"
#include <iostream>
#include <string>
#include "material.hpp"
#include "ray.hpp"

class Shape
{
public:
	Shape();
	Shape(Material const& mat, std::string const& name);
	~Shape();
	//virtual void draw() const = 0;
	virtual float area() const = 0;
	virtual float volume() const = 0;
	
	//aufgabe 5.4
	virtual std::ostream& print(std::ostream& os) const;

	//getter
	Material const& get_mat() const;
	std::string const& get_name() const;

	//aufgabe 6.3
	virtual bool intersect(Ray const& ray, float& t) const = 0 ;

  //virtual bool calc_n

protected:
	Material mat_;
	std::string name_;
};

//aufgabe 5.4

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif
