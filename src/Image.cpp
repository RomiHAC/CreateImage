#include "Image.h"
#include <algorithm>

Image::Image() : W(0), H(0), DSimg(nullptr) {}

Image::Image(int width, int height) : W(width), H(height), DSimg(new ImageDS(width, height)) {}

Image::Image(int width, int height, Pixel pixel)
    : W(width), H(height), DSimg(new ImageDS(width, height, pixel)) {}

Image::Image(const Image& other) : W(other.W), H(other.H), DSimg(new ImageDS(*other.DSimg)) {}

Image::~Image() {
    delete DSimg;
}

//// Assignment Operator
//void Image::operator=(const Image& other) {
//    if (this == &other) return;
//
//    delete DSimg;                          // Free existing memory
//    W = other.W;
//    H = other.H;
//    DSimg = new ImageDS(*other.DSimg);     // Deep copy
//}

//void Image::operator=(const Image& other) {
//    if (this == &other) return;
//
//
//
//    W = other.getWidth();
//    H = other.getHeight();
//    Image temp(W, H, ' ');
//
//    for (int row = 0; row < (*this).getHeight(); ++row) {
//        for (int col = 0; col < (*this).getWidth(); ++col) {
//            temp(row, col) = other(row, col);
//        }
//    }
//    //(*this)(temp);
//
//}

const Pixel Image::operator()(unsigned int X, unsigned int Y) const {
    return DSimg->getPixel(X, Y);
}

Pixel& Image::operator()(unsigned int X, unsigned int Y) {
    return DSimg->getPixel(X, Y);
}


int Image::GetHeight() const {
    return H;
}

int Image::GetWidth() const {
    return W;
}


Image Image::operator+(const Image& other) const {
    int newHeight = std::max(H, other.H);
    int newWidth = W + other.W;

    Image result(newWidth, newHeight, Pixel(' '));
    for (int row = 0; row < H; ++row) {
        for (int col = 0; col < W; ++col) {
            result(row, col) = (*this)(row, col);
        }
    }
    for (int row = 0; row < other.H; ++row) {
        for (int col = 0; col < other.W; ++col) {
            result(row, col + W) = other(row, col);
        }
    }

    return result;
}


void Image::operator+=(const Image& other) {
    *this = *this + other;
}




//Image Image::operator|(const Image& other) const {
//
//    int maxW = std::max(W, other.W);
//    int maxH = std::max(H, other.H);
//
//
//    Image new_return(maxW, maxH, Pixel(' '));
//
//    // Fill the resulting image
//    for (int row = 0; row < maxH; row++) {
//        for (int col = 0; col < maxW; col++) {
//
//
//            Pixel pixelA = (row < H && col < W) ? (*this)(row, col) : Pixel(' ');        // Get pixel from current image or default
//            Pixel pixelB = (row < other.H && col < other.W) ? other(row, col) : Pixel(' '); // Get pixel from other image or default
//
//            //Define the union logic for combining two pixels
//            new_return(row, col) = pixelA | pixelB; // Assuming `Pixel` supports the `|` operator
//        }
//    }
//
//    return new_return;
//}


Image Image::operator|(const Image& other) const {
    Image result(std::max(W, other.W), std::max(H, other.H), Pixel(' '));
    for (int row = 0; row < result.GetHeight(); ++row) {
        for (int col = 0; col < result.GetWidth(); ++col) {
            Pixel pixel1 = (row < H && col < W) ? (*this)(row, col) : Pixel(' ');
            Pixel pixel2 = (row < other.H && col < other.W) ? other(row, col) : Pixel(' ');
            result(row, col) = (pixel1 == Pixel::WHITE || pixel2 == Pixel::WHITE) ? Pixel::WHITE : Pixel::BLACK;
        }
    }
    return result;
}


void Image::operator|=(const Image& other) {
    *this = *this | other;
}


Image Image::operator&(const Image& other) const {
    int minW = std::min(W, other.W);
    int minH = std::min(H, other.H);


    Image new_return(minW, minH, Pixel(' '));

   
    for (int row = 0; row < minW; row++) {
        for (int col = 0; col < minH; col++) {

            Pixel pixelA = (row < H && col < W) ? (*this)(row, col) : Pixel(' ');        
            Pixel pixelB = (row < other.H && col < other.W) ? other(row, col) : Pixel(' '); 

           
            new_return(row, col) = pixelA & pixelB; 
        }
    }

    return new_return;

}

void Image::operator&=(const Image& other) {
    *this = *this & other;
}

// Repeat the image N times
//Image Image::operator*(unsigned int N) const {
//    Image result(W * N, H, Pixel(' '));
//    for (unsigned int n = 0; n < N; ++n) {
//        for (int row = 0; row < H; ++row) {
//            for (int col = 0; col < W; ++col) {
//                result(row, col + n * W) = (*this)(row, col);
//            }
//        }
//    }
//    return result;
//}
Image Image::operator*(unsigned int N) const {
    Image result; 
    for (unsigned int i = 0; i < N; ++i) {
        result += *this;
    }
    return result;
}

Image operator*(unsigned int N,const Image& original)  {
      return original*N;
}

void operator*=(Image& original , unsigned int N) {
    original =  original * N;
}

Image& Image::operator~() {
    for (int row = 0; row < H; ++row) {
        for (int col = 0; col < W; ++col) {
            Pixel& p = (*this)(row, col);
            p = (p == Pixel::WHITE) ? Pixel::BLACK : Pixel::WHITE;
        }
    }
    return *this;
}

bool operator==(const Image& lso, const Image& rso) {
    if (lso.GetHeight() != rso.GetHeight() || lso.GetWidth() != rso.GetWidth()) {
        return false;
    }
    for (int row = 0; row < lso.GetHeight(); ++row) {
        for (int col = 0; col < lso.GetWidth(); ++col) {
            if (lso(row, col) != rso(row, col)) {
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const Image& lso, const Image& rso) {
    return !(lso == rso);
}


std::ostream& operator<<(std::ostream& os, const Image& image) {

    os << "Image (" << image.GetWidth() << "x" << image.GetHeight() << "):" << std::endl;
    for (int row = 0; row < image.GetHeight(); ++row) {
        for (int col = 0; col < image.GetWidth(); ++col) {
            os << image(row, col);
        }
        os << std::endl;
    }
    return os;
}
