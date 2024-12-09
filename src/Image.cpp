#include <iostream>
#include "Image.h"

Image::Image() : W(0), H(0), pixel(' ') {}

Image::Image(int width, int height) : pixel(' ') {
    W = width > 0 ? width : 0;
    H = height > 0 ? height : 0;
   // allocatePixels(width, height, ' ');
}

Image::Image(int width, int height, Pixel pixel) : pixel(pixel) {
    W = width > 0 ? width : 0;
    H = height > 0 ? height : 0;
    //allocatePixels(width, height, pixel);
}



/*Image::~Image()
{
    for (int row = 0; row < H; ++row) {
        delete pixels[row];
    }
    delete[] pixels;
}*/






//have a problrm with  the width and hight?
/*void Image::allocatePixels(int width, int height, Pixel defaultPixel) {
   // Update class members
    W = width;
    H = height;

    // Allocate memory
    pixel = new Pixel * [H];
    for (int row = 0; row < H; ++row) {
        pixels[row] = new Pixel[W];
        for (int col = 0; col < W; ++col) {
            pixels[row][col] = defaultPixel;
        }
    }
}*/





bool operator==(const Image& first, const Image& other) 
{
    int difH = abs(first.getHeight() - other.getHeight());
    int difW = abs(first.getWidth() != other.getWidth());
    if ( difH != 0 || difW != 0) return false;
    for (int row = 0; row < first.getHeight(); ++row) {
        for (int col = 0; col < first.getWidth(); ++col) {
            //if (pixel[row][col] != other.pixel[row][col]) {
              //  return false;
            //}
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
    //result.allocatePixels(newWidth, newHeight, Pixel(' ')); 

    // Copy current image pixels
    for (int row = 0; row < H; ++row) {
        for (int col = 0; col < W; ++col) {
           // result.pixels[row][col] = pixels[row][col];
        }
    }

    // Copy other image pixels
    for (int row = 0; row < other.H; ++row) {
        for (int col = 0; col < other.W; ++col) {
            //result.pixels[row][col + W] = other.pixels[row][col];
        }
    }

    return result;
}



Image& Image::operator=(const Image& other) {
    if (this == &other) return *this;

    
   // for (int i = 0; i < (*this).getHeight(); ++i) {
    //    delete[] pixels[i];
  //  }
   // delete[] pixels;


    W = other.getWidth();
    H = other.getHeight();

   
    //allocatePixels((*this).getWidth(), (*this).getHeight(), Pixel(0));
   // for (int row = 0; row < (*this).getHeight(); ++row) {
   //     for (int col = 0; col < (*this).getWidth(); ++col) {
   //         pixels[row][col] = other.pixels[row][col];
     //   }
   // }

    return *this;
}

Image& Image::operator+=(const Image& other) {
    *this =*this + other; 
     return *this;
}





std::ostream& operator<<(std::ostream& os, const Image& temp_image)
{
    
    os << "Image (" << temp_image.getWidth() << "x" << temp_image.getHeight() << "):" << std::endl;

    for (int row = 0; row < temp_image.getHeight(); ++row) {
        for (int col = 0; col < temp_image.getWidth(); ++col) {
            //need to make function to get the pixels
            //os << temp_image.pixels[row][col] << " "; 
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

             
            //Pixel pixelA = (row < H && col < W) ? pixels[row][col] : Pixel(' ');        // Get pixel from current image or default
           // Pixel pixelB = (row < other.H && col < other.W) ? other.pixels[row][col] : Pixel(' '); // Get pixel from other image or default

            // Define the union logic for combining two pixels
           // new_return.pixels[row][col] = pixelA | pixelB; // Assuming `Pixel` supports the `|` operator
        }
    }

    return new_return;
}

Image& Image::operator|=(const Image& other)  {
    *this = *this | other;
    return *this;

}

Image Image::operator&(const Image& other) const  {
    int minW = std::min(W, other.W);
    int minH = std::min(H, other.H);


    Image new_return(minW, minH, Pixel(' '));

    // Fill the resulting image
    for (int row = 0; row < minW; row++) {
        for (int col = 0; col < minH; col++) {

            //Pixel pixelA = (row < H && col < W) ? pixels[row][col] : Pixel(' ');        // Get pixel from current image or default
            // Pixel pixelB = (row < other.H && col < other.W) ? other.pixels[row][col] : Pixel(' '); // Get pixel from other image or default

            // Define the union logic for combining two pixels
           // new_return.pixels[row][col] = pixelA & pixelB; // 
        }
    }

    return new_return;

}
Image& Image::operator&=(const Image& other) {
    *this = *this & other;
    return *this;

}
Image Image::operator*(unsigned int N) const {
    Image add_images = *this;
    for (int start = 0; start < N; start++) {
        add_images += add_images;
    }


    return add_images;
}
Image& Image::operator~() {

    for (int row = 0; row < (*this).getHeight(); row++) {
        for (int col = 0; col < (*this).getWidth(); col++) {
            //need to use imageDS for the arrey
              if(pixel[row][col] == Pixel ::WHITE){
                 pixel[row][col] = Pixel::BLACK;
             
              }
              else if(pixel[row][col] == Pixel::BLACK) {
                    pixel[row][col] = Pixel::WHITE;
                 
               }
            
        }
    
    } 
    
}
const Pixel& Image::operator()(unsigned int X, unsigned int Y) const {
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
 

