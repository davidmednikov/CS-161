/***************************************************************************
** Author: David Mednikov
** Date: 10/31/2016
** Description: This Point class implementation defines the default constructor,
** a two-parameter constructor, the get and set methods for the X and Y
** coordinates, and the method that calculates the distance between two points.
***************************************************************************/
    
// Point.cpp is the Point class implementation file

#include "Point.hpp" // Include Point header file
#include <cmath>

Point::Point() // Default constructor sets coordinates to (0,0)
{
    setXCoord(0);
    setYCoord(0);
}

Point::Point(double xC, double yC) // Two-parameter constructor to set coordinates
{
    setXCoord(xC);
    setYCoord(yC);
}

void Point::setXCoord(double xC) // Set X-Coordinate method
{
    xCoord = xC;
}

void Point::setYCoord(double yC) // Set Y-Coordinate method
{
    yCoord = yC;
}

double Point::getXCoord() // Get X-Coordinate method
{
    return xCoord;
}

double Point::getYCoord() // Get Y-Coordinate method
{
    return yCoord;
}

// Calculate distance between two points. 2nd point passed by constant reference
double Point::distanceTo(const Point& p2)
{
    double xDist = p2.xCoord - xCoord;
    double yDist = p2.yCoord - yCoord;
    
    return sqrt(xDist*xDist + yDist*yDist);
}