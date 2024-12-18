#pragma once
#include <iosfwd>
const unsigned char BLACK = (unsigned char)219;
const unsigned char GRAY = (unsigned char)176;
const unsigned char WHITE = (unsigned char)32;

class Pixel {
private:
    unsigned char color;

public:
    Pixel(unsigned char pixel = WHITE);
    Pixel(unsigned char pixel);

    Pixel& operator=(const Pixel& other);
    unsigned char getColor() const; 
};

bool operator==(const Pixel& first, const Pixel& other);
bool operator!=(const Pixel& first, const Pixel& other);
std::ostream& operator<<(std::ostream& output, const Pixel& pixel); 
Pixel operator|(const Pixel& original, const Pixel& other);
Pixel& operator|=(Pixel& original, const Pixel& other);
Pixel operator&(const Pixel& original, const Pixel& other);
Pixel& operator&=(Pixel& original, const Pixel& other);
