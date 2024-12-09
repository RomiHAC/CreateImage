#pragma once
#include "Pixel.h"
#include "Image.h"

struct IMAGES {
	IMAGES(IMAGES* next, Image next_image);
	IMAGES* data_images;
	Image image;
};
class ImageDS {

public:
	
	ImageDS(Image current_image, IMAGES new_image);

private:
	Image storage_image;
	Pixel** pixels;
	IMAGES* head;
	unsigned int count=0;
};
