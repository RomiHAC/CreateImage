#include "Pixel.h"
#include <stdexcept>

const unsigned char Pixel::BLACK = (unsigned char)219;
const unsigned char Pixel::GRAY = (unsigned char)176;
const unsigned char Pixel::WHITE = (unsigned char)32;

// Constructor
Pixel::Pixel(unsigned char pixel) {
    if (pixel != BLACK && pixel != GRAY && pixel != WHITE) {
        throw std::invalid_argument("Invalid pixel value");
    }
    color = pixel;
}

// Comparison operators
bool operator==(const Pixel& first,const Pixel& other)  {
    return first.getColor() == other.getColor();
}

bool operator!=(const Pixel& first, const Pixel& other)  {
    return !(first == other);
}

// Logical operators
Pixel Pixel::operator|(const Pixel& other) const {
    return Pixel((*this).getColor() > other.getColor() ? (*this).getColor() : other.getColor());
}

Pixel& Pixel::operator|=(const Pixel& other) {
    color = (*this).getColor() > other.getColor() ? (*this).getColor() : other.getColor();
    return *this;
}

Pixel Pixel::operator&(const Pixel& other) const {
    return Pixel((*this).getColor() < other.getColor() ? (*this).getColor() : other.getColor());
}

Pixel& Pixel::operator&=(const Pixel& other) {
    color = (*this).getColor() < other.getColor() ? (*this).getColor() : other.getColor();
    return *this;
}

// Stream output
std::ostream& operator<<(std::ostream& os, const Pixel& pixel) {
    os << pixel.getColor();
    return os;
}

Pixel& Pixel::operator=(const Pixel& other)  {
    color = other.getColor();
    return *this;

}
char Pixel::getColor() const {
    return color;

}


