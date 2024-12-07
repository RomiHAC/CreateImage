#include <iostream>
#include "Pixel.h"

Pixel::Pixel(unsigned char pixel)
{
	color = pixel;
}

bool Pixel::operator==(const Pixel& other) const
{
	return color == other.color;
}

bool Pixel::operator!=(const Pixel& other) const
{
	return  !(*this == other);
}





