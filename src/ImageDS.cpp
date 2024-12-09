#include <iostream>
#include "ImageDS.h"



ImageDS::ImageDS(Image current_image, IMAGES new_image):storage_image(current_image), head(nullptr) {
    IMAGES(head, storage_image);

}


IMAGES::IMAGES(IMAGES* next, Image next_image):data_images(next), image(next_image){}


