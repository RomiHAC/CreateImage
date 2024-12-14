#pragma once
#include <iosfwd>
const unsigned char BLACK = (unsigned char)219;
const unsigned char GRAY = (unsigned char)176;
const unsigned char WHITE = (unsigned char)32;

class Pixel {
private:
    unsigned char color;

public:


    // Constructor
    Pixel(unsigned char pixel = WHITE);
    Pixel(const Pixel& other);
    // Logical operators
    //Pixel operator|(const Pixel& other) const;


    //Pixel operator&(const Pixel& other) const;


    Pixel& operator=(const Pixel& other);

    //friend std::ostream& operator<<(std::ostream& os, const Pixel& pixel);

    unsigned char getColor() const; // Updated to return unsigned char
};

// Comparison operators
bool operator==(const Pixel& first, const Pixel& other);
bool operator!=(const Pixel& first, const Pixel& other);

// Stream output
std::ostream& operator<<(std::ostream& output, const Pixel& pixel);

Pixel operator|(const Pixel& original, const Pixel& other);
Pixel& operator|=(Pixel& original, const Pixel& other);

Pixel operator&(const Pixel& original, const Pixel& other);
Pixel& operator&=(Pixel& original, const Pixel& other);
