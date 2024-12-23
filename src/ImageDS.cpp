#include "ImageDS.h"
#include <stdexcept> // For exceptions

ImageDS::ImageDS() : height(0), width(0), pixels(nullptr) {}

ImageDS::ImageDS(int height, int width) : height(height), width(width) {
    allocatePixels(width, height);
}

ImageDS::ImageDS(int height, int width, Pixel pixel) : height(height), width(width) {
    allocatePixels(width, height);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            pixels[i][j] = pixel; // Initialize all pixels to the provided value
        }
    }
}

// Copy Constructor
ImageDS::ImageDS(const ImageDS& other) : height(other.height), width(other.width) {
    allocatePixels(width, height);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            pixels[i][j] = other.pixels[i][j];
        }
    }
}

// Destructor
ImageDS::~ImageDS() {
    deallocatePixels();
}

ImageDS& ImageDS::operator=(const ImageDS& other) {
    if (this == &other) return *this;

    deallocatePixels(); // Free existing memory
    width = other.width;
    height = other.height;
    allocatePixels(width, height);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            pixels[i][j] = other.pixels[i][j];
        }
    }

    return *this;
}

// Get pixel (const)
Pixel ImageDS::getPixel(int x, int y) const {
    if (x < 0 || x >= height || y < 0 || y >= width) {
        throw std::out_of_range("Pixel coordinates out of range");
    }
    return pixels[x][y];
}

// Get pixel (non-const)
Pixel& ImageDS::getPixel(int x, int y) {
    if (x < 0 || x >= height || y < 0 || y >= width) {
        throw std::out_of_range("Pixel coordinates out of range");
    }
    return pixels[x][y];
}

// Set a pixel value
void ImageDS::setPixel(int x, int y, const Pixel& pixel) {
    if (x < 0 || x >= height || y < 0 || y >= width) {
        throw std::out_of_range("Pixel coordinates out of range");
    }
    pixels[x][y] = pixel;
}

int ImageDS::getWidth() const {
    return width;
}

int ImageDS::getHeight() const {
    return height;
}

// Allocate memory for pixels
void ImageDS::allocatePixels(int W, int H) {
    pixels = new Pixel * [H];
    for (int i = 0; i < H; ++i) {
        pixels[i] = new Pixel[W];
    }
}

// Deallocate memory for pixels
void ImageDS::deallocatePixels() {
    if (pixels) {
        for (int i = 0; i < height; ++i) {
            delete[] pixels[i];
        }
        delete[] pixels;
        pixels = nullptr;
    }
}
