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

   
   

    // Logical operators
    Pixel operator|(const Pixel& other) const;
    Pixel& operator|=(const Pixel& other);

    Pixel operator&(const Pixel& other) const;
    Pixel& operator&=(const Pixel& other);

    Pixel& operator=(const Pixel& other);
    char getColor() const;

   
};
bool operator==(const Pixel&  first,const Pixel& other) ;
bool operator!=(const Pixel& first, const Pixel& other) ;
//made globali
std::ostream& operator<<(std::ostream& output, const Pixel& pixel);
