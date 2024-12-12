#include "Image.h"
#include <algorithm>


// Default Constructor
Image::Image() : DSimg(new ImageDS(0, 0)) {}

// Constructor with height and width
Image::Image(int height, int width) : DSimg(new ImageDS(height, width)) {}

// Constructor with height, width, and default pixel value
Image::Image(int height, int width, Pixel pixel)
    : DSimg(new ImageDS(height, width, pixel)) {}

// Copy Constructor
Image::Image(const Image& other) : DSimg(new ImageDS(*other.DSimg)) {}

// Destructor
Image::~Image() {
    delete DSimg;
}

//Assignment Operator
//Image& Image::operator=(const Image& other) {
//    if (this == &other) return *this; // Self-assignment check
//
//    delete DSimg; // Free existing memory
//    H = other.H;
//    W = other.W;
//    DSimg = new ImageDS(*other.DSimg); // Deep copy
//
//    return *this;
//}

// Access pixel (const)
const Pixel Image::operator()(unsigned int X, unsigned int Y) const {
    return DSimg->getPixel(X, Y);
}

// Access pixel (non-const)
Pixel& Image::operator()(unsigned int X, unsigned int Y) {
    return DSimg->getPixel(X, Y);
}

// Getters for dimensions
int Image::GetHeight() const {
    return DSimg->getHeight();
}

int Image::GetWidth() const {
    return DSimg->getWidth();
}



// Addition operator
Image Image::operator+(const Image& other) const {
    int newHeight = std::max(DSimg->getHeight(), other.DSimg->getHeight());
    int newWidth = DSimg->getWidth() + other.DSimg->getWidth();

    Image result(newHeight, newWidth, Pixel(' '));

    // Copy this image's pixels
    for (int row = 0; row < DSimg->getHeight(); ++row) {
        for (int col = 0; col < DSimg->getWidth(); ++col) {
            result(row, col) = (*this)(row, col);
        }
    }

    // Copy the other image's pixels
    for (int row = 0; row < other.DSimg->getHeight(); ++row) {
        for (int col = 0; col < other.DSimg->getWidth(); ++col) {
            result(row, col + DSimg->getWidth()) = other(row, col);
        }
    }

    return result;
}

// Compound addition operator
Image& operator+=(Image& original, const Image& other) {
    original = original + other;
    return original;
}

// Union operator
Image Image::operator|(const Image& other) const {
    int newWidth = std::max(DSimg->getWidth(), other.DSimg->getWidth());
    int newHeight = std::max(DSimg->getHeight(), other.DSimg->getHeight());

    Image result(newHeight, newWidth, Pixel(' '));

    for (int row = 0; row < result.GetHeight(); ++row) {
        for (int col = 0; col < result.GetWidth(); ++col) {
            Pixel pixel1 = (row < DSimg->getHeight() && col < DSimg->getWidth()) ? (*this)(row, col) : Pixel(' ');
            Pixel pixel2 = (row < other.DSimg->getHeight() && col < other.DSimg->getWidth()) ? other(row, col) : Pixel(' ');
            result(row, col) = pixel1 | pixel2; // Assuming Pixel supports the | operator
        }
    }

    return result;
}

// Compound union operator
Image& operator|=(Image &original ,const Image& other) {
    original = original | other;
    return original;
}

// Intersection operator
Image Image::operator&(const Image& other) const {
    int minWidth = std::min(DSimg->getWidth(), other.DSimg->getWidth());
    int minHeight = std::min(DSimg->getHeight(), other.DSimg->getHeight());

    Image result(minHeight, minWidth, Pixel(' '));

    for (int row = 0; row < minHeight; ++row) {
        for (int col = 0; col < minWidth; ++col) {
            Pixel pixel1 = (*this)(row, col);
            Pixel pixel2 = other(row, col);
            result(row, col) = (pixel1 == WHITE && pixel2 == WHITE) ? WHITE : BLACK;
        }
    }

    return result;
}

// Compound intersection operator
Image& operator&=(Image& original, const Image& other) {
    original = original & other;
    return original;
}

Image operator*(unsigned int N, const Image& original)
{
    return original * N;
}

Image& operator*=(Image& original, unsigned int N) {
    original = original * N;
    return original;
}

// Repeat operator
Image Image::operator*(unsigned int N) const {
    int newWidth = DSimg->getWidth() * N;
    Image result(DSimg->getHeight(), newWidth, Pixel(' '));

    for (unsigned int n = 0; n < N; ++n) {
        for (int row = 0; row < DSimg->getHeight(); ++row) {
            for (int col = 0; col < DSimg->getWidth(); ++col) {
                result(row, col + n * DSimg->getWidth()) = (*this)(row, col);
            }
        }
    }

    return result;
}

// Negation operator
Image& Image::operator~() {
    for (int row = 0; row < DSimg->getHeight(); ++row) {
        for (int col = 0; col < DSimg->getWidth(); ++col) {
            Pixel& p = (*this)(row, col);
            p = (p == WHITE) ? BLACK : WHITE;
        }
    }

    return *this;
}

// Equality operator
bool Image::operator==(const Image& other) const {
    if (DSimg->getHeight() != other.DSimg->getHeight() || DSimg->getWidth() != other.DSimg->getWidth()) {
        return false;
    }

    for (int row = 0; row < DSimg->getHeight(); ++row) {
        for (int col = 0; col < DSimg->getWidth(); ++col) {
            if ((*this)(row, col) != other(row, col)) {
                return false;
            }
        }
    }

    return true;
}

// Inequality operator
bool operator!=(const Image& lhs, const Image& rhs) {
    return !(lhs == rhs);
}

// Output stream operator
std::ostream& operator<<(std::ostream& os, const Image& image) {
    for (int row = 0; row < image.DSimg->getHeight(); ++row) {
        for (int col = 0; col < image.DSimg->getWidth(); ++col) {
            os << image(row, col);
        }
        os << std::endl;
    }
    return os;
}
