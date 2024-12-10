#include "Pixel.h"
#include <stdexcept>

const unsigned char Pixel::BLACK = (unsigned char)219;
const unsigned char Pixel::GRAY = (unsigned char)176;
const unsigned char Pixel::WHITE = (unsigned char)32;

Pixel::Pixel(unsigned char pixel) {
    if (pixel != BLACK && pixel != GRAY && pixel != WHITE) {
        throw std::invalid_argument("Invalid pixel value");
    }
    color = pixel;
}

Pixel Pixel::operator|(const Pixel& other) const {
    return Pixel(color > other.color ? color : other.color);
}

Pixel& Pixel::operator|=(const Pixel& other) {
    color = color > other.color ? color : other.color;
    return *this;
}

Pixel Pixel::operator&(const Pixel& other) const {
    return Pixel(color < other.color ? color : other.color);
}

Pixel& Pixel::operator&=(const Pixel& other) {
    color = color < other.color ? color : other.color;
    return *this;
}

Pixel& Pixel::operator=(const Pixel& other) {
    if (this != &other) {
        color = other.color;
    }
    return *this;
}

unsigned char Pixel::getColor() const { 
    return color;
}

bool operator==(const Pixel& first, const Pixel& other) {
    return first.getColor() == other.getColor();
}

bool operator!=(const Pixel& first, const Pixel& other) {
    return !(first == other);
}

std::ostream& operator<<(std::ostream& os, const Pixel& pixel) {
    os << (int)pixel.getColor(); // Cast to int for readable output
    return os;
}
