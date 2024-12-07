#pragma once
#include "Pixel.h"

class Image {

public:
	Image();
	Image(int width, int hight);
	Image(int width, int hight, Pixel pixel);
	
	bool operator==(const Image& other) const;
	bool operator!=(const Image& other) const;
	Image operator+(const Image& other)const  ;
	Image& operator+=(const Image& other);




private:
	int W;
	int H ;
	Pixel **pixels;
	void allocatePixels(int width, int height, Pixel defaultPixel);
};
