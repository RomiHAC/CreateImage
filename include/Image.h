#pragma once
#include "Pixel.h"
#include "ImageDS.h"
#include <iostream>

class Image {
public:
    Image();
    Image(int width, int height);
    Image(int width, int height, Pixel pixel);
    Image(const Image& other);
    ~Image();

    Image operator+(const Image& other) const;
    //void operator=(const Image& other);
    void operator+=(const Image& other);
    Image operator|(const Image& other) const;
    void operator|=(const Image& other);
    Image operator&(const Image& other) const;
    void operator&=(const Image& other);

    Image operator*(unsigned int N) const;
    Image& operator~();

    const Pixel operator()(unsigned int X, unsigned int Y) const;
    Pixel& operator()(unsigned int X, unsigned int Y);

    int GetHeight() const;
    int GetWidth() const;

private:
    int W;
    int H;
    ImageDS* DSimg;
};
Image operator*(unsigned int N, const Image& original);
void operator*=(Image& original, unsigned int N);

// lso / rso = Left side operator / Right side operator
bool operator==(const Image& lso, const Image& rso);
bool operator!=(const Image& lso, const Image& rso);
std::ostream& operator<<(std::ostream& os, const Image& image);
