#pragma once
#include "Pixel.h"

class Image {

public:
	Image();
	Image(int width, int hight);
	Image(int width, int hight, Pixel pixel);

private:
	int W;
	int H;
	Pixel p;
};
