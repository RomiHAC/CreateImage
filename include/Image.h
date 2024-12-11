#pragma once
#include "Pixel.h"
#include "ImageDS.h"
#include <iostream>

class Image {
public:
    Image();                                    // Default Constructor
    Image(int height, int width);              // Constructor with dimensions
    Image(int height, int width, Pixel pixel); // Constructor with dimensions and default pixel
    Image(const Image& other);                 // Copy Constructor
    ~Image();                                  // Destructor

    //Image& operator=(const Image& other);      // Assignment Operator
    bool operator==(const Image& other) const ;

    Image operator+(const Image& other) const; // Concatenation operator
      


    Image operator|(const Image& other) const; // Union operator
    

    Image operator&(const Image& other) const; // Intersection operator
   

    Image operator*(unsigned int N) const;     // Repeat operator

    Image& operator~();                        // Negation operator

    const Pixel operator()(unsigned int X, unsigned int Y) const; // Access pixel (const)
    Pixel& operator()(unsigned int X, unsigned int Y);            // Access pixel (non-const)

    friend std::ostream& operator<<(std::ostream& os, const  Image& image);

    int GetHeight() const;                     // Get image height
    int GetWidth() const;                      // Get image width

private:
    //int W;             // Width of the image
    //int H;             // Height of the image
    ImageDS* DSimg;    // Pointer to the underlying data structure
};

// Comparison operators


//bool operator==(const Image& lhs, const Image& rhs);
bool operator!=(const Image& lhs, const Image& rhs);

Image& operator+=(Image &original,const Image& other); // Compound concatenation operator

Image& operator|=(Image& original, const Image& other); //Compound Union operator

Image& operator&=(Image &original,const Image& other);       // Compound intersection operator

Image operator*(unsigned int N, const Image& original);// Repeat operator

Image& operator*=( Image& original ,unsigned int N);// Compound Repeat operator



// Output stream operator
//std::ostream& operator<<(std::ostream& os, const Image& image);
