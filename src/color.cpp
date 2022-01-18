#include "color.hpp"

Color hex_color(unsigned int hex){
	Color color;
	//std::cout << "in: " << std::hex << hex << '\n';
	int depth = hex % 0x100;
//	std::cout << "depth: " << std::hex << depth << '\n';
//	std::cout << "depth: " << std::dec << depth/ 0xff << '\n';
	hex -= depth;
	hex /= 0x100;

	int b = hex % 0x100;
	hex -= b;
	hex /= 0x100;
/*
	std::cout << "B: " << std::hex << b << '\n';
	std::cout << "B: " << std::dec << b / 0xff << '\n';
	*/

	int g = hex % 0x100;
	hex -= g;
	hex /= 0x100;
	/*
	 std::cout << "G: " << std::hex << g << '\n';
	std::cout << "G: " << std::dec << g / 0xff << '\n';
	*/

	int r = hex % 0x100;
	hex -= r;
	hex /= 0x100;

	/*
	std::cout << "R: " << std::hex << r << '\n';
	std::cout << "R: " << std::dec << r / 0xff << '\n';
	std::cout << "out " << std::hex << hex << '\n';
	*/

	color.r = r/0xff;
	color.g = g/0xff;
	color.b = b/0xff;
	color.a = depth/0xff;
	return color;
}
