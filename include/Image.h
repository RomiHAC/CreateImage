#pragma once
#include "Pixel.h"
#include "ImageDS.h"
#include <iostream>

class Image {
public:
    Image();                                 
    Image(int height, int width);              
    Image(int height, int width, Pixel pixel); 
    const Pixel operator()(unsigned int X, unsigned int Y) const; // Access pixel (const)
    Pixel& operator()(unsigned int X, unsigned int Y);            // Access pixel (non-const)
    int GetHeight() const;                 
    int GetWidth() const;                  

private:
    ImageDS DSimg;
};

bool operator==(const Image& lhs, const Image& rhs); // check if equal
bool operator!=(const Image& lhs, const Image& rhs);// check if not equal
Image operator+(const Image& original, const Image& other);
Image& operator+=(Image& original, const Image& other); // Compound concatenation operator
Image operator|(const Image& original, const Image& other); // Union operator
Image& operator|=(Image& original, const Image& other); //Compound Union operator
Image operator&(const Image& original, const Image& other);  // Intersection operator
Image& operator&=(Image& original, const Image& other);       // Compound intersection operator
Image operator*(const Image& original, unsigned int N);     // Repeat operator
Image operator*(unsigned int N, const Image& original);// Repeat operator
Image& operator*=(Image& original, unsigned int N);// Compound Repeat operator
Image& operator~(Image& original);                        // Negation operator
std::ostream& operator<<(std::ostream& os, const Image& image); // Output stream operator
