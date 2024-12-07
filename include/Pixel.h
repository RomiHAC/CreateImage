#pragma once
#include <iosfwd>

class Pixel {

public:
	Pixel(unsigned char pixel = ' ');

	bool operator==(const Pixel& other) const; 
	bool operator!=(const Pixel& other) const;
	Pixel operator|(const Pixel& other) const;
	Pixel& operator|=(const Pixel& other);
	Pixel operator&(const Pixel& other) const;

	Pixel& operator&=(const Pixel& other);
	

	friend  std::ostream& operator<< (std::ostream& output, const Pixel& pixel);

	


private:
	unsigned char color;
};
