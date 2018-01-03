/***************************************************************************
** Author: David Mednikov
** Date: 10/24/2016
** Description: This Box implementation file defines the setHeight, setHeight,
** and setLength methods, as well as the getVolume and getSurfaceArea methods.
***************************************************************************/

// Box.cpp is the Box class implementation file
#include "Box.hpp"

Box::Box() // Default constructor with no arguments, sets member variables to 1
    {
        setHeight(1);
        setWidth(1);
        setLength(1);
    }

Box::Box(double h, double w, double len) // Constructor with 3 arguments
    {
        setHeight(h);
        setWidth(w);
        setLength(len);
    }

// Set Height of box
void Box::setHeight(double h)
{
    height = h;
}

// Set Width of box
void Box::setWidth(double w)
{
    width = w;
}

// Set Length of box
void Box::setLength(double len)
{
    length = len;
}

// Calculate and return volume of box
double Box::getVolume()
{
    return height * width * length;
}

// Calculate and return surface area of box
double Box::getSurfaceArea()
{
    return 2*(height*width) + 2*(width*length) + 2*(height*length);
}