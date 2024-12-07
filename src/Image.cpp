#include <iostream>
#include "Image.h"

Image::Image() {}

Image::Image(int width, int hight) : W(width), H(hight) {}

Image::Image(int width, int hight, Pixel pixel) : W(width), H(hight), p(pixel) {}

