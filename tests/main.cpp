#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include <iostream>
#include "transform.hpp"
#include <glm/glm.hpp>

TEST_CASE("transform",""){
  Transform t1{};  
  glm::vec4 a{1.0,1.0,1.0,1.0};
  REQUIRE(t1.name_ == ""); 
  auto b = t1.world_transform(a);
  REQUIRE(b.x == 1.0);
  Transform t2{"bla",{1.0,1.0,1.0},{1.0,0.0,0.0},{0.0,0.0,0.0,0.0}};
  b = t2.world_transform(a);
  REQUIRE(b.x == 2.0);

}

/*
TEST_CASE("ctor test","aufgabe5.2"){//{{{
  //Box b1{};
  auto b1 = std::make_shared<Box> ();
  REQUIRE (b1->get_min().x == 0.0f);
  REQUIRE (b1->get_min().y == 0.0f);
  REQUIRE (b1->get_min().z == 0.0f);
  auto s1 = std::make_shared<Sphere> ();
  REQUIRE (s1->get_radius() == .0f);
  REQUIRE (s1->get_middle().x == .0f);
  REQUIRE (s1->get_middle().y == .0f);
  REQUIRE (s1->get_middle().z == .0f);
}//}}}
TEST_CASE("methoden area volume","aufgabe5.2"){//{{{
  //Box b1{};
  auto b1 = std::make_shared<Box> ();
  auto s1 = std::make_shared<Sphere> ();
  REQUIRE (b1->area() == 0.0f );
  REQUIRE (b1->volume() == 0.0f);
  REQUIRE (s1->area() == Approx(.0f));
  REQUIRE (s1->volume() == Approx(.0f));
}//}}}

TEST_CASE("ctor name & color","aufgabe bis5.5")//{{{
{
  Material m1{{"???"},{1.0,0.5,0.75},{1.0,0.5,0.75},{1.0,0.5,0.75},{0.9}};
  Sphere s1 {m1,{"bla"},{2.0f,1.0f,2.0f},{2.0f}};

  Box b1 {m1,{"bla"},{3.0f,2.0f,1.0f},{4.0f,3.0f,2.0f}};
  std::cout << "name von s1 " << s1.get_name() << "\n";
  REQUIRE ( s1.get_name() == "bla"); 
  REQUIRE ( b1.get_name() == "bla"); 
  REQUIRE (s1.get_mat().ka_.r == 1.0f); 
  REQUIRE (s1.get_mat().ka_.g == 0.5f); 
  REQUIRE (s1.get_mat().ka_.b == 0.75f); 
  REQUIRE (b1.get_mat().ka_.r == 1.0f); 
  REQUIRE (b1.get_mat().ka_.g == 0.5f); 
  REQUIRE (b1.get_mat().ka_.b == 0.75f); 
//  Shape sh1 {{"bla"},{1.0,0.5,0.75}};kann man nicht aufrufen,da abstrackter typ
//  REQUIRE (sh1.name() == "bla"); 
  std::cout << b1 << "\n";
  std::cout << s1 << "\n";
}//}}}

TEST_CASE("intersectRaySphere","[intersect]")//{{{
{
  Material m1{{"???"},{1.0,0.5,0.75},{1.0,0.5,0.75},{1.0,0.5,0.75},{0.9}};
  glm::vec3 ray_origin{0.0,0.0,0.0};

  glm::vec3 ray_direction{0.0,0.0,1.0};

  glm::vec3 sphere_center{0.0,0.0,5.0};
  float sphere_radius{1.0};

  float distance{0.0};
  auto result = glm::intersectRaySphere(
    ray_origin, ray_direction,
    sphere_center, sphere_radius, distance);

  REQUIRE ( distance == Approx(4.0f));

  glm::vec3 origin{0,0,1};
  glm::vec3 direction{0,0,1};
  //direction = glm::normalize{direction};
  Ray ray{origin, direction};

  Sphere s1{m1,{"bla"},{0,5,0},{2.0}};
  REQUIRE (!s1.intersect(ray,distance));
  Sphere s2{m1,{"bla"},{0,0,0},{2.0}};
  REQUIRE (s2.intersect(ray,distance));

}//}}}

TEST_CASE("dctor","5.8")//{{{
{
  std::cout << "----------------------\n";
  std::cout << "hier faengt dector an!!!\n";
  std::cout << "----------------------\n";
  Color red(255,0,0);
  glm::vec3 position(0,0,0);
  Material m1{{"???"},{1.0,0.5,0.75},{1.0,0.5,0.75},{1.0,0.5,0.75},{0.9}};

  Sphere* s1 = new Sphere(m1, "sphere0",position, 1.2f );
  Shape* s2 = new Sphere(m1, "sphere0",position, 1.2f );
  
  s1->print(std::cout);
  s2->print(std::cout);
  
  delete s1;
  delete s2;
}//}}}
TEST_CASE("test_intersect_box_5.10")
{
  Material m1{{"???"},{1.0,0.5,0.75},{1.0,0.5,0.75},{1.0,0.5,0.75},{0.9}};
	Box a{m1,"Box",{0.0,0.0,0.0},{8.0,3.0,3.0}};
	Box b{m1,"Box",{5.0,0.0,0.0},{8.0,3.0,3.0}};
	Box c{m1,"Box",{0.0,0.0,1.0},{8.0,3.0,3.0}};
	Box d{m1,"Box",{4.0,0.0,0.0},{8.0,3.0,3.0}};
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
TEST_CASE("test_box")//{{{
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
//}}}
*/

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
