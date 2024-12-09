#pragma once
#include "Pixel.h"
#include <iosfwd>

class Image {

public:
	Image();
	Image(int width, int hight);
	Image(int width, int hight, Pixel pixel);

	
	
	
	Image operator+(const Image& other)const  ;
	Image& operator=(const Image& other);
	Image& operator+=(const Image& other);
	Image operator|(const Image& other) const;
	Image& operator|=(const Image& other);
	Image operator&(const Image& other) const;
	Image& operator&=(const Image& other);
	Image operator*(unsigned int N) const;
	Image& operator~();
	const Pixel& operator()(unsigned int X, unsigned int Y) const;
	Pixel& operator()(unsigned int X, unsigned int Y);
	




	int getHeight() const;
	int getWidth() const;

private:
	int W;
	int H ;
	Pixel pixel;
	//void allocatePixels(int width, int height, Pixel defaultPixel);
};

bool operator==(const Image& first , const Image& other)  ;
bool operator!=(const Image& first, const Image& other) ;
std::ostream& operator<<(std::ostream& output, const Image& temp_image);
