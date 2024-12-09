#include <iostream>
#include "Image.h"

Image::Image() : W(0), H(0), pixels(nullptr) {}

Image::Image(int width, int height) : W(width), H(height) {
    allocatePixels(width, height, ' ');
}

Image::Image(int width, int height, Pixel pixel) : W(width), H(height) {
    allocatePixels(width, height, pixel);
}
Image::~Image()
{
    for (int row = 0; row < H; ++row) {
        delete pixels[row];
    }
    delete[] pixels;
}

//have a problrm with  the width and hight?
void Image::allocatePixels(int width, int height, Pixel defaultPixel) {
    // Update class members
    W = width;
    H = height;

    // Allocate memory
    pixels = new Pixel * [H];
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

    // Create a new Image with uninitialized pixels
    Image result;
    result.allocatePixels(newWidth, newHeight, Pixel(' ')); 

    // Copy current image pixels
    for (int row = 0; row < H; ++row) {
        for (int col = 0; col < W; ++col) {
            result.pixels[row][col] = pixels[row][col];
        }
    }

    // Copy other image pixels
    for (int row = 0; row < other.H; ++row) {
        for (int col = 0; col < other.W; ++col) {
            result.pixels[row][col + W] = other.pixels[row][col];
        }
    }

    return result;
}



Image& Image::operator=(const Image& other) {
    if (this == &other) return *this;

    
    for (int i = 0; i < (*this).getHeight(); ++i) {
        delete[] pixels[i];
    }
    delete[] pixels;


    W = other.W;
    H = other.H;

   
    allocatePixels((*this).getWidth(), (*this).getHeight(), Pixel(0));
    for (int row = 0; row < (*this).getHeight(); ++row) {
        for (int col = 0; col < (*this).getWidth(); ++col) {
            pixels[row][col] = other.pixels[row][col];
        }
    }

    return *this;
}

Image& Image::operator+=(const Image& other) {
    *this =*this + other; 
     return *this;
}



std::ostream& operator<<(std::ostream& output, const Image& temp_image)
{
    
    output << "Image (" << temp_image.getWidth() << "x" << temp_image.getHeight() << "):" << std::endl;

    for (int row = 0; row < temp_image.getHeight(); ++row) {
        for (int col = 0; col < temp_image.getWidth(); ++col) {
            //need to make function to get the pixels
            output << temp_image.pixels[row][col] << " "; 
        }
        output << std::endl;
    }

    return output;

}

Image Image::operator|(const Image& other) const {
   int maxW = std::max(W, other.W);
    int maxH = std::max((*this).getHeight(), other.getHeight());
    Image new_return(maxW, maxH, Pixel(' '));
   
    for (int row = 0; row < maxW; row++) {
        for (int col = 0; col < maxH; col++) {
            new_return.pixels[row][col] = pixels[row][col] | other.pixels[row][col];
        }

    }

    return new_return;

}
Image& Image::operator|=(const Image& other)  {
    *this = *this | other;
    return *this;

}

int Image::getHeight() const 
{
    return H;
}
int Image::getWidth() const
{
    return W;
}
 

