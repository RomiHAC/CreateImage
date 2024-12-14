#pragma once
#include "Pixel.h"

class ImageDS {
public:
    ImageDS();
    ImageDS(int height, int width);
    ImageDS(int height, int width, Pixel pixel);
    ImageDS(const ImageDS& other);
    ~ImageDS();

  //  ImageDS& operator=(const ImageDS& other);

    Pixel getPixel(int x, int y) const;
    Pixel& getPixel(int x, int y);
    void setPixel(int x, int y, const Pixel& pixel);

    int getWidth() const;
    int getHeight() const;
    void setHeight(int H);
    void setWidth(int W);

private:
    int width;
    int height;
    Pixel** pixels;

    void allocatePixels(int W, int H);
    void deallocatePixels();
};
