Image and operators Project
program by: Or-Ram Atar(325004851) | and Romi Sinizkey(322311457) 

This project focuses on the creation and manipulation of images represented in
grayscale using Object-Oriented Programming principles. Key elements include 
dynamic memory allocation, operator overloading, and proper handling of 
constructors copy constructors and destructors.


Files Created:
Pixel.cpp / Pixel.h: Defines the Pixel class responsible for individual pixel operations, including color definitions and operator overloads.
Image.cpp / Image.h: Implements the Image class, managing the structure and behavior of an entire image, along with overloaded operators for image manipulation.
ImageDS.cpp / ImageDS.h: Handles dynamic memory allocation for the image data and interacts with the Image class.
main.cpp: Contains test cases and entry points for validating the project functionalities.

Data Structures and Their Roles:
Pixel: Represents a single pixel in the image with three possible colors: black, gray, and white.
Image: A grid of Pixel objects representing the entire image, capable of operations like union, intersection, and scalar multiplication.
ImageDataStructure: Encapsulates memory management for Image, ensuring safe and efficient resource handling.

Algorithms
Operator Overloading: Enables intuitive use of operators (e.g., ==, +, |, &, *) for Pixel and Image objects.
Dynamic Memory Management: Ensures robust handling of resources during image resizing, copying, and destruction.
Boundary Checks: Ensures operations are within valid dimensions and indices.

Object-Oriented Design
Encapsulation: Separates Image logic from ImageDataStructure, promoting modularity and clarity.
Abstraction: Provides a user-friendly interface for image manipulation through intuitive operations.

Known Bugs:
do not have any

Additional Notes:
Use provided test cases in tests directory for validation. (file was already provided to us) 
