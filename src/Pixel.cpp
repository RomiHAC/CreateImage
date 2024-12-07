#include <iostream>
#include "Pixel.h"
//need to check where to put it
const unsigned char BLACK = (unsigned char)219;
const unsigned char GRAY = (unsigned char)176;
const unsigned char WHITE = (unsigned char)32;

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

std::ostream& operator<<(std::ostream& output, const Pixel& pixel) {
	output << pixel;
	return output;
}
Pixel Pixel::operator|(const Pixel& other) const {
	return Pixel(color > other.color ? color : other.color);
}

Pixel& Pixel::operator|=(const Pixel& other)  {
	color = color > other.color ? color : other.color;
	return *this;
}
Pixel Pixel::operator&(const Pixel & other) const {
	return Pixel(color < other.color ? color : other.color);
}
Pixel &Pixel::operator&=(const Pixel& other)  {
	color =  color < other.color ? color : other.color;
	return *this;
}


