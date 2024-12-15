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
//    //DSimg->setHeight(other.GetHeight());
//    //DSimg->setWidth(other.GetWidth());
//   H = other.H;
//    W = other.W;
//    DSimg = new ImageDS(*other.DSimg); // Deep copy
//
//    return *this;
//}
Image& Image::operator=(const Image& other) {
    if (this == &other) return *this; // Self-assignment check

    // Free existing memory
    delete DSimg;

    // Deep copy the DSimg object from the other Image
    DSimg = new ImageDS(*other.DSimg); // Assuming ImageDS has a proper copy constructor

    return *this;
}

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
Image operator+(const Image& original, const Image& other) {
    int newHeight = std::max(original.GetHeight(), other.GetHeight());
    int newWidth = original.GetWidth() + other.GetWidth();

    Image result(newHeight, newWidth, Pixel(' '));

    // Copy this image's pixels
    for (int row = 0; row < original.GetHeight(); ++row) {
        for (int col = 0; col < original.GetWidth(); ++col) {
            result(row, col) = original(row, col);
        }
    }

    // Copy the other image's pixels
    for (int row = 0; row < other.GetHeight(); ++row) {
        for (int col = 0; col < other.GetWidth(); ++col) {
            result(row, col + original.GetWidth()) = other(row, col);
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
Image operator|(const Image& original, const Image& other) {
    int newWidth = std::max(original.GetHeight(), other.GetHeight());
    int newHeight = std::max(original.GetWidth(), other.GetWidth());

    Image result(newHeight, newWidth, Pixel(' '));

    for (int row = 0; row < result.GetHeight(); ++row) {
        for (int col = 0; col < result.GetWidth(); ++col) {
            Pixel pixel1 = (row < original.GetHeight() && col < original.GetWidth()) ? original(row, col) : Pixel(' ');
            Pixel pixel2 = (row < other.GetHeight() && col < other.GetWidth()) ? other(row, col) : Pixel(' ');
            result(row, col) = pixel1 | pixel2; // Assuming Pixel supports the | operator
        }
    }

    return result;
}

// Compound union operator
Image& operator|=(Image& original, const Image& other) {
    original = original | other;
    return original;
}

// Intersection operator
Image operator&(const Image& original, const Image& other) {
    int minWidth = std::min(original.GetWidth(), other.GetWidth());
    int minHeight = std::min(original.GetHeight(), other.GetHeight());

    Image result(minHeight, minWidth, Pixel(' '));

    for (int row = 0; row < minHeight; ++row) {
        for (int col = 0; col < minWidth; ++col) {
            Pixel pixel1 = original(row, col);
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
Image operator*(const Image& original, unsigned int N) {
    int newWidth = original.GetWidth() * N;
    Image result(original.GetHeight(), newWidth, Pixel(' '));

    for (unsigned int n = 0; n < N; ++n) {
        for (int row = 0; row < original.GetHeight(); ++row) {
            for (int col = 0; col < original.GetWidth(); ++col) {
                result(row, col + n * original.GetWidth()) = original(row, col);
            }
        }
    }

    return result;
}

// Negation operator
Image& operator~(Image& original) {
    for (int row = 0; row < original.GetHeight(); ++row) {
        for (int col = 0; col < original.GetWidth(); ++col) {
            Pixel& p = original(row, col);
            p = (p == WHITE) ? BLACK : WHITE;
        }
    }

    return original;
}

// Equality operator
bool operator==(const Image& lhs, const Image& rhs) {
    if (lhs.GetHeight() != rhs.GetHeight() || lhs.GetWidth() != rhs.GetWidth()) {
        return false;
    }

    for (int row = 0; row < lhs.GetHeight(); ++row) {
        for (int col = 0; col < lhs.GetWidth(); ++col) {
            if (lhs(row, col) != rhs(row, col)) {
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
    for (int row = 0; row < image.GetHeight(); ++row) {
        for (int col = 0; col < image.GetWidth(); ++col) {
            os << image(row, col);
        }
        os << std::endl;
    }
    return os;
}
