#include <iostream>
#include "ImageDS.h"

ImageDS::ImageDS(): images(nullptr),count(0) {}

ImageDS::ImageDS(Image* image, int amount) :images(image), count(amount) {}

