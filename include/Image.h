#pragma once
#include "Pixel.h"
#include <iosfwd>

class Image {

public:
	Image();
	Image(int width, int hight);
	Image(int width, int hight, Pixel pixel);

	~Image();
	
	bool operator==(const Image& other) const;
	bool operator!=(const Image& other) const;
	Image operator+(const Image& other)const  ;
	Image& operator=(const Image& other);
	Image& operator+=(const Image& other);
	Image operator|(const Image& other) const;
	Image& operator|=(const Image& other);




	int getHeight() const;
	int getWidth() const;

private:
	int W;
	int H ;
	Pixel **pixels;
	void allocatePixels(int width, int height, Pixel defaultPixel);
};


std::ostream& operator<<(std::ostream& output, const Image& temp_image);
