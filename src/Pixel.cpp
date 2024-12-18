#include "Pixel.h"
#include <iostream>
#include <stdexcept>

Pixel::Pixel(unsigned char pixel) {
    if (pixel != BLACK && pixel != GRAY && pixel != WHITE) {
        throw std::invalid_argument("Invalid pixel value");
    }
    color = pixel;
}

Pixel operator|(const Pixel& original, const Pixel& other) {
    return Pixel(original.getColor() > other.getColor() ? original.getColor() : other.getColor());
}

Pixel& operator|=(Pixel& original, const Pixel& other) {
    original = original | other;
    return original;
}

Pixel operator&(const Pixel& original, const Pixel& other) {
    return Pixel(original.getColor() < other.getColor() ? original.getColor() : other.getColor());
}

Pixel& operator&=(Pixel& original, const Pixel& other) {
    original = original & other;
    return original;
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
    os << pixel.getColor();
    return os;
}
