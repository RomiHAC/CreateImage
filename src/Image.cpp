#include <iostream>
#include "Image.h"
#include "Pixel.h"



// Default Constructor
Image::Image() : W(0), H(0), DSimg(0, 0, Pixel()) {
    
}

// Constructor with width and height
Image::Image(int width, int height) : W(width), H(height), DSimg(width, height, Pixel()) {
   
}

// Constructor with width, height, and a pixel
Image::Image(int width, int height, Pixel pixel) : W(width), H(height), DSimg(width, height, pixel) {
    
}

// Copy Constructor
Image::Image(const Image& other) : W(other.W), H(other.H), DSimg(other.DSimg) {
    // Copy constructor: copies the dimensions and DSimg from another Image.
}






bool operator==(const Image& first, const Image& other) 
{
    int difH = abs(first.getHeight() - other.getHeight());
    int difW = abs(first.getWidth() != other.getWidth());
    if ( difH != 0 || difW != 0) return false;
    for (int row = 0; row < first.getHeight(); ++row) {
        for (int col = 0; col < first.getWidth(); ++col) {
            if (first(row,col) != other(row,col)) {
              return false;
            }
        }
    }
    return true;
}


bool operator!=(const Image& first, const Image& other)  {
             
    return !(first == other);

}
 

Image Image::operator+(const Image& other) const {
    int newHeight = std::max(H, other.H);
    int newWidth = W + other.W;

    // Create a new Image with uninitialized pixels
    Image result(newWidth, newHeight,Pixel(' '));
    

    // Copy current image pixels
    for (int row = 0; row < H; ++row) {
        for (int col = 0; col < W; ++col) {
           result(row,col) = (*this)(row,col);
        }
    }

    // Copy other image pixels
    for (int row = 0; row < other.H; ++row) {
        for (int col = 0; col < other.W; ++col) {
            result(row, col + W) = other(row,col);
        }
    }

    return result;
}



void Image::operator=(const Image& other) {
    if (this == &other) return;

    
    
    W = other.getWidth();
    H = other.getHeight();
    Image temp(W, H, ' ');

    for (int row = 0; row < (*this).getHeight(); ++row) {
       for (int col = 0; col < (*this).getWidth(); ++col) {
           temp(row,col) = other(row,col);
       }
   }
    //(*this)(temp);
    
}

void Image::operator+=(const Image& other) {
    *this = *this + other;  
}





std::ostream& operator<<(std::ostream& os, const Image& temp_image)
{
    
    os << "Image (" << temp_image.getWidth() << "x" << temp_image.getHeight() << "):" << std::endl;

    for (int row = 0; row < temp_image.getHeight(); ++row) {
        for (int col = 0; col < temp_image.getWidth(); ++col) {
            
            os << temp_image(row,col) << " "; 
        }
        os << std::endl;
    }

    return os;

}

Image Image::operator|(const Image& other) const {
   
    int maxW = std::max(W, other.W); 
    int maxH = std::max(H, other.H); 

    
    Image new_return(maxW, maxH, Pixel(' ')); 

    // Fill the resulting image
    for (int row = 0; row < maxH; row++) {
        for (int col = 0; col < maxW; col++) {

             
            Pixel pixelA = (row < H && col < W) ? (*this)(row,col) : Pixel(' ');        // Get pixel from current image or default
            Pixel pixelB = (row < other.H && col < other.W) ? other(row,col) : Pixel(' '); // Get pixel from other image or default

            //Define the union logic for combining two pixels
            new_return(row,col) = pixelA | pixelB; // Assuming `Pixel` supports the `|` operator
        }
    }

    return new_return;
}

void Image::operator|=(const Image& other)  {
    *this = *this | other;

}

Image Image::operator&(const Image& other) const  {
    int minW = std::min(W, other.W);
    int minH = std::min(H, other.H);


    Image new_return(minW, minH, Pixel(' '));

    // Fill the resulting image
    for (int row = 0; row < minW; row++) {
        for (int col = 0; col < minH; col++) {

            Pixel pixelA = (row < H && col < W) ? (*this)(row, col) : Pixel(' ');        // Get pixel from current image or default
            Pixel pixelB = (row < other.H && col < other.W) ? other(row, col) : Pixel(' '); // Get pixel from other image or default

            //Define the union logic for combining two pixels
            new_return(row, col) = pixelA & pixelB; // Assuming `Pixel` supports the `&` operator
        }
    }

    return new_return;
    
}
void  Image::operator&=(const Image& other) {
    *this = *this & other;
  
    
}
Image Image::operator*(unsigned int N) const {
    Image result; // Start with a default empty image
    for (unsigned int i = 0; i < N; ++i) {
        result += *this; // Accumulate the current image N times
    }
    return result;
}

//Image Image::operator(unsigned int N)*(Image i) const {
  //  Image add_images = *this;
   // return add_images * N;
//}


Image& Image::operator~() {

    for (int row = 0; row < (*this).getHeight(); row++) {
        for (int col = 0; col < (*this).getWidth(); col++) {
            //need to use imageDS for the arrey
              if((*this)(row,col) == Pixel ::WHITE){
                 (*this)(row,col) = Pixel::BLACK;
             
              }
              else if((*this)(row, col) == Pixel::BLACK) {
                  (*this)(row, col) = Pixel::WHITE;
                 
               }
            
        }
    
    } 
    
}
const Pixel Image::operator()(unsigned int X, unsigned int Y) const {
    //return the pixel(x,y) ;
}
Pixel& Image::operator()(unsigned int X, unsigned int Y)  {
    //return the pixel(x,y) ;
}

 
int Image::getHeight() const 
{
    return H;
}
int Image::getWidth() const
{
    return W;
}
 

