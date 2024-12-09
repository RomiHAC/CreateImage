#pragma once
#include <iostream>

class Pixel {
private:
    unsigned char color;

public:
    static const unsigned char BLACK;
    static const unsigned char GRAY;
    static const unsigned char WHITE;

    // Constructor
    Pixel(unsigned char pixel = WHITE);

    // Comparison operators
    bool operator==(const Pixel& other) const;
    bool operator!=(const Pixel& other) const;

    // Logical operators
    Pixel operator|(const Pixel& other) const;
    Pixel& operator|=(const Pixel& other);

    Pixel operator&(const Pixel& other) const;
    Pixel& operator&=(const Pixel& other);

    Pixel& operator=(const Pixel& other);
   char getColor() const;

    // Stream output
    //std::ostream& operator<<(std::ostream& output, const Pixel& pixel);
};
//made globali
std::ostream& operator<<(std::ostream& output, const Pixel& pixel);
