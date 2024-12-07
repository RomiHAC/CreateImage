#pragma once
#include "Image.h"

class ImageDS {

public:
	ImageDS();
	ImageDS(Image *image, int amount);
private:
	Image *images;
	int count ;
};
