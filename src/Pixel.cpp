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
bool Pixel::operator==(const Pixel& other) const {
    return (*this).getColor() == other.getColor();
}

bool Pixel::operator!=(const Pixel& other) const {
    return !((*this) == other);
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
std::ostream& operator<<(std::ostream& output, const Pixel& pixel) {
    output << pixel.getColor();
    return output;
}

Pixel& Pixel::operator=(const Pixel& other)  {
    color = other.getColor();
    return *this;

}
char Pixel::getColor() const {
    return color;

}


