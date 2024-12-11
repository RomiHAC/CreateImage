#pragma once
#include <iosfwd>

class Pixel {
private:
    unsigned char color;

public:
    static const unsigned char BLACK;
    static const unsigned char GRAY;
    static const unsigned char WHITE;

    // Constructor
    Pixel(unsigned char pixel = WHITE);

    // Logical operators
    Pixel operator|(const Pixel& other) const;
    Pixel& operator|=(const Pixel& other);

    Pixel operator&(const Pixel& other) const;
    Pixel& operator&=(const Pixel& other);

    Pixel& operator=(const Pixel& other);

    friend std::ostream& operator<<(std::ostream& os, const Pixel& pixel);
    unsigned char getColor() const; // Updated to return unsigned char
};

// Comparison operators
bool operator==(const Pixel& first, const Pixel& other);
bool operator!=(const Pixel& first, const Pixel& other);

// Stream output
//std::ostream& operator<<(std::ostream& output, const Pixel& pixel);
