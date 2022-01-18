#ifndef COLOR_H
#define COLOR_H
#include <iostream>
typedef  struct color {
	float r, g, b, a;
}Color;

Color hex_color(unsigned int hex);
#endif
