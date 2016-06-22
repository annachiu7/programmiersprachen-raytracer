#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "color.hpp"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "ray.hpp"
#include <string>
#include "material.hpp"
/*
TEST_CASE("test_box")
{
	Box b1{};
	Box b2{{1,0,1},"box",{0,0,0},{1,1,1}};
	Box b3{{1,0,0},"box",{0,1,2},{5,4,3}};
	REQUIRE(b1.get_min().x == Approx(0.0));
	REQUIRE(b2.get_max().y == Approx(1));
	REQUIRE(b1.area() == Approx(0.0));
	REQUIRE(b2.area() == Approx(6));
	REQUIRE(b2.volume() == Approx(1));
	REQUIRE(b3.area() == Approx(46));
	REQUIRE(b3.volume() == Approx(15));
}

TEST_CASE("test_sphere")
{
	Sphere s1{};
	Sphere s2{{1,1,0},"sphere",{1,1,1}, 3.0f};
	REQUIRE(s1.get_middle().x == Approx(0));
	REQUIRE(s1.get_radius() == Approx(0));
	REQUIRE(s2.get_middle().z == Approx(1));
	REQUIRE(s2.get_radius() == Approx(3.0));
	REQUIRE(s2.area() == Approx(113.09734));
	REQUIRE(s2.volume() == Approx(113.09734));
}

TEST_CASE("test_shape_base_member_5.3")
{
	Sphere s{{1,1,0},"sphere",{1,1,1}, 3.0f};
	REQUIRE(s.get_color().r == Approx(1));
	REQUIRE(s.get_color().g == Approx(1));
	REQUIRE(s.get_color().b == Approx(0));
	REQUIRE(s.get_name() == "sphere");
	Box b2{{1,0,1},"box",{0,0,0},{1,1,1}};
	REQUIRE(b2.get_color().r == Approx(1));
	REQUIRE(b2.get_name() == "box");
}

TEST_CASE("test_print_5.5")
{
	Sphere s{{1,1,0},"sphere",{1,1,1}, 3.0f};
	Box b{{1,0,1},"box",{0,0,0},{1,1,1}};
	REQUIRE(1 == 1);
	std::cout<<"\n" << "=============Aufgabe 5.5 test print============="<<"\n";
	std::cout << s << std::endl;
	std::cout << b << std::endl;
}

TEST_CASE ("intersectRaySphere", "[intersect]")
{
// Ray
glm::vec3 ray_origin{0.0, 0.0, 0.0};
glm::vec3 ray_direction{0.0, 0.0, 1.0};
// Sphere
glm::vec3 sphere_center{0.0, 0.0, 5.0};
float sphere_radius{2.0};
float distance{0.0};
auto result = glm::intersectRaySphere(
	ray_origin , glm::normalize(ray_direction) ,   // normalization
	sphere_center , sphere_radius*sphere_radius ,
	distance );
REQUIRE(distance == Approx (3.0f));
}

TEST_CASE("test_intersect_Sphere_5.6")
{
	Sphere s{{1,1,1},"sphere",{0.0,0.0,5.0}, 2.0};
	float distance{0.0};
	auto result = s.intersect({{0.0,0.0,0.0}, {0.0,0.0,1.0}}, distance);
	REQUIRE(distance == Approx(3.0f));
}

TEST_CASE("5.7")
{
	Color red(255 , 0 , 0);
	glm::vec3 position(0 ,0,0);
	std::shared_ptr < Sphere > s1 =
	std::make_shared < Sphere >( red , " sphere0 ", position , 1.2);
	// die statische Klasse von s2 ist Shape, es kann nur die Methode der Klasse Shape aufrufen
	std::shared_ptr < Shape > s2 =
	std::make_shared < Sphere >( red , " sphere1 ", position , 1.2);
	std::cout<<"\n =============Aufgabe 5.7 statischer Typ vs dynamischer Typ============= \n" ;
	s1->print( std :: cout );
	std::cout<<"\n";
	s2->print( std :: cout );
}


TEST_CASE("5.8")
{
	Color red (255 , 0 , 0);
	glm::vec3 position (0 ,0, 0);
	Sphere*s1 = new Sphere ( red , " sphere0 ", position , 1.2);
	Shape*s2 = new Sphere ( red , " sphere1 ", position , 1.2);
	s1->print( std :: cout );
	s2->print( std :: cout );
	delete s1 ;
	delete s2 ;
}
*/

TEST_CASE("test_intersect_box_5.10")
{
	Box a{{},"Box",{0.0,0.0,0.0},{8.0,3.0,3.0}};
	Box b{{},"Box",{5.0,0.0,0.0},{8.0,3.0,3.0}};
	Box c{{},"Box",{0.0,0.0,1.0},{8.0,3.0,3.0}};
	Box d{{},"Box",{4.0,0.0,0.0},{8.0,3.0,3.0}};
	Ray r1{{0,0,0},{1,0,0}};
	Ray r2{{0,0,0},{4,0,3}};
	float distance = 0;
	std::cout<<"=============Aufgabe 5.10 Ray Box Intersection=============\n";
	auto result = a.intersect(r1,distance);
	std::cout<<"a intersect r1: "<<distance<<std::endl;
	result = b.intersect(r1,distance);
	std::cout<<"b intersect r1: "<<distance<<std::endl;
	result = c.intersect(r1,distance);
	std::cout<<"c intersect r1: "<<distance<<std::endl;
	result = d.intersect(r2,distance);
	std::cout<<"d intersect r2: "<<distance<<std::endl;
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
