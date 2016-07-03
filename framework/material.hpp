#ifndef BUW_MATERIAL_HPP
#define BUW_MATERIAL_HPP
#include "color.hpp"
#include <string>
#include <iostream>

struct Material
{
	Material():
	name_{""},
	ka_{0,0,0},
	kd_{0,0,0},
	ks_{0,0,0},
	m_{0.0f}
	{}

	Material(std::string const& name, Color const& ambient, Color const& diffuse, Color const& specular, float m):
	name_{name},
	ka_{ambient},
	kd_{diffuse},
	ks_{specular},
	m_{m}
	{}

	friend std::ostream& operator<<(std::ostream& os, Material const& mat)
	{
		os << "name:     " << mat.name_ << "\n"
	   	   << "ambient:  " << mat.ka_ << "\n"
	   	   << "diffuse:  " << mat.kd_ << "\n"
	   	   << "specular: " << mat.ks_ << "\n"
	   	   << "material: " << mat.m_ << "\n";
		return os;
	}

	std::string name_;
	Color ka_; //ambient
	Color kd_; //diffuse
	Color ks_; //specular
	float m_;

	/*
	std::ostream& print(std::ostream& os)
	{
		os << "name:   " << name_ << "\n"
	   	   << "ambient:  " << ka_.r << "," << ka_.g << ","<< ka_.b << " \n"
	   	   << "diffuse:  " << kd_.r << "," << kd_.g << ","<< kd_.b << " \n" 
	   	   << "specular: " << ks_.r << "," << ks_.g << ","<< ks_.b << " \n"
	   	   << "material: " << m_ << "\n";
		return os;
	}
	*/
	
};

#endif
