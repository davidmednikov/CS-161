/***************************************************************************
** Author: David Mednikov
** Date: 10/31/2016
** Description: This Point class specification file has two member variables
** for the coordinates of the point, a default constructor which sets the
** coordinates to (0,0), a two-parameter constructor which sets the coordinates
** to the parameters, methods to get and set the x and y coordinates, and abort
** method that calculates the distance between the two points.
***************************************************************************/
    
// Point.hpp is the Point class specification file

#ifndef POINT_HPP
#define POINT_HPP
    
class Point // Declare Box class
{
    private:
        double xCoord, yCoord; // Member variables for coordinates
        
    public:
        Point(double xC, double yC); // Two-parameter constructor prototype
        Point(); // Default constructor prototype
        
        void setXCoord(double xC); // Set X-Coordinate prototype
        void setYCoord(double yC); // Set Y-Coordinate prototype
        
        double getXCoord(); // Get X-Coordinate prototype
        double getYCoord(); // Get Y-Coordinate prototype
        
        // Calculate distance from point to second point (passed as a reference parameter)
        double distanceTo(const Point& p2);
};
#endif