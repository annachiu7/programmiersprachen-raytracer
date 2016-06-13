#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include "color.hpp"
#include <iostream>

class Shape
{
public:
	Shape();
	Shape(Color clr, std::string name);
	//virtual void draw() const = 0;
	virtual float area() const = 0;
	virtual float volume() const = 0;
	
	//aufgabe 5.4
	virtual std::ostream& print(std::ostream& os) const;

	//getter
	Color const& get_color() const;
	std::string const& get_name() const;

protected:
	Color color_;
	std::string name_;
};

//aufgabe 5.4

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif