#include <iostream>
#include "Image.h"

Image::Image() : W(0), H(0), pixels(nullptr) {}

Image::Image(int width, int height) : W(width), H(height) {
    allocatePixels(width, height,32);
}

Image::Image(int width, int height, Pixel pixel) : W(width), H(height) {
    allocatePixels(width, height, pixel);
}

//have a problrm with  the width and hight?
void Image::allocatePixels(int width, int height, Pixel defaultPixel) {
    // Update class members
    W = width;
    H = height;

    // Allocate memory
    pixels = new Pixel*[H];
    for (int row = 0; row < H; ++row) {
        pixels[row] = new Pixel[W];
        for (int col = 0; col < W; ++col) {
            pixels[row][col] = defaultPixel;
        }
    }
}

bool Image::operator==(const Image& other) const {
    if (H != other.H || W != other.W) return false;

    for (int row = 0; row < H; ++row) {
        for (int col = 0; col < W; ++col) {
            if (pixels[row][col] != other.pixels[row][col]) {
                return false;
            }
        }
    }
    return true;
}


bool Image::operator!=(const Image& other) const {
             
    return !(*this == other);

}


Image Image::operator+(const Image& other) const {
    int newHeight = std::max(H, other.H);
    int newWidth = W + other.W;

    Image result(newWidth, newHeight, Pixel(32)); 

    
    for (int row = 0; row < H; ++row) {
        for (int col = 0; col < W; ++col) {
            result.pixels[row][col] = pixels[row][col]; 
        }
    }

    
    for (int row = 0; row < other.H; ++row) {
        for (int col = 0; col < other.W; ++col) {
            result.pixels[row][col + W] = other.pixels[row][col]; 
        }
    }

    return result; 
}


//problem the + operetor - cant use it
Image& Image::operator+=(const Image& other) {
    *this =*this + other; 
     return *this;
}




