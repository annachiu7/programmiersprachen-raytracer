#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "color.hpp"
#include <iostream>

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
	std::cout << s << std::endl;
	std::cout << b << std::endl;
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
