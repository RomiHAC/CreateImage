#pragma once
#include <iosfwd>

class Pixel {

public:
	Pixel(unsigned char pixel = ' ');


	const unsigned char BLACK = (unsigned char)219;
	const unsigned char GRAY = (unsigned char)176;
	const unsigned char WHITE = (unsigned char)32;
	
	bool operator==(const Pixel& other) const; 
	bool operator!=(const Pixel& other) const;

	


private:
	unsigned char color;
};
