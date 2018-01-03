/***************************************************************************
** Author: David Mednikov
** Date: 10/24/2016
** Description: This Box class specification contains three double fields 
** (height, width, and length), as well as set methods for each field. 
** There is a three-parameter constructor that takes three doubles and 
** uses the set methods to save them to the member variables. If no parameters 
** are passed the constructor should set all fields to 1. The class has methods
** that calculate and return the volume and the surface area of the box.
***************************************************************************/

// Box.hpp is the Box class specification file
#ifndef BOX_HPP
#define BOX_HPP

class Box // Declare Box class
{
    private:
    double height, width, length; // Three member variables
    
    public:
        
    Box(double h, double w, double len); // Constructor prototypes
    Box(); // Default constructor prototype
        
    void setHeight(double h); // These methods are all defined in Box.cpp
    void setWidth(double w);
    void setLength(double len);
    double getVolume();
    double getSurfaceArea();
    
};
#endif