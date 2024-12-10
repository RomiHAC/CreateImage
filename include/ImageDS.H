#pragma once
#include "Pixel.h"

class ImageDS {
public:
    ImageDS();                                  
    ImageDS(int width, int height);            
    ImageDS(int width, int height, Pixel pixel); 
    ImageDS(const ImageDS& other);           
    ~ImageDS();                                

    ImageDS& operator=(const ImageDS& other);  

    Pixel getPixel(int x, int y) const;       
    Pixel& getPixel(int x, int y);             
    void setPixel(int x, int y, const Pixel& pixel); 

    int GetWidth() const;                     
    int GetHeight() const;                    

private:
    int width;                              
    int height;                              
    Pixel** pixels;                       

    void allocatePixels(int width, int height); 
    void deallocatePixels();                   
};
