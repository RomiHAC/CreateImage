#include "ImageDS.h"
#include <stdexcept> // For exceptions


ImageDS::ImageDS() : width(0), height(0), pixels(nullptr) {}

ImageDS::ImageDS(int width, int height) : width(width), height(height) {
    allocatePixels(width, height);
}

ImageDS::ImageDS(int width, int height, Pixel pixel) : width(width), height(height) {
    allocatePixels(width, height);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            pixels[i][j] = pixel; // Initialize all pixels to the provided value
        }
    }
}

ImageDS::ImageDS(const ImageDS& other) : width(other.width), height(other.height) {
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

void ImageDS::setPixel(int x, int y, const Pixel& pixel) {
    if (x < 0 || x >= height || y < 0 || y >= width) {
        throw std::out_of_range("Pixel coordinates out of range");
    }
    pixels[x][y] = pixel;
}

int ImageDS::GetWidth() const {
    return width;
}

int ImageDS::GetHeight() const {
    return height;
}

void ImageDS::allocatePixels(int width, int height) {
    pixels = new Pixel*[height];
    for (int i = 0; i < height; ++i) {
        pixels[i] = new Pixel[width];
    }
}

void ImageDS::deallocatePixels() {
    if (pixels) {
        for (int i = 0; i < height; ++i) {
            delete[] pixels[i];
        }
        delete[] pixels;
        pixels = nullptr;
    }
}
