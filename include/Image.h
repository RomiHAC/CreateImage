#pragma once
#include "Pixel.h"
#include <iosfwd>

class Image {

public:
	Image();
	Image(int width, int hight);
	Image(int width, int hight, Pixel pixel);
	
	bool operator==(const Image& other) const;
	bool operator!=(const Image& other) const;
	Image operator+(const Image& other)const  ;
	Image& operator=(const Image& other);
	Image& operator+=(const Image& other);

	friend std::ostream& operator<<(std::ostream& output, const Image& temp_image);


private:
	int W;
	int H ;
	Pixel **pixels;
	void allocatePixels(int width, int height, Pixel defaultPixel);
};
