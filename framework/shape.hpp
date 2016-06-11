#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include "color.hpp"

class Shape
{
public:
	Shape();
	//virtual void draw() const = 0;
	virtual float area() const = 0;
	virtual float volume() const = 0;

	//getter
	Color const& get_color() const;
	std::string const& get_name() const;

protected:
	std::string name_;
	Color color_;
};

#endif