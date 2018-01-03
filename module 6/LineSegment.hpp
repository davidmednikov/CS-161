/***************************************************************************
** Author: David Mednikov
** Date: 10/31/2016
** Description: This LineSegment class specification has two member variables,
** one for each endpoint of the line segment. It also contains a two-parameter
** constructor, get and set methods for both endpoints, and methods that
** calculate the length and slope of the line segment.
***************************************************************************/
    
// LineSegment.hpp is the LineSegment class specification file

#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP

#include "Point.hpp" // Include Point specification file
    
class LineSegment // Declare LineSegment class
{
    private:
        Point endpoint1, endpoint2; // Two member variables - both point objets
     
    public:
        void setEnd1(Point point1); // Method to set first endpoint
        void setEnd2(Point point2); // Method to set second endpoint
        
        Point getEnd1(); // Method to get first endpoint
        Point getEnd2(); // Method to set second endpoint
        
        // Two-parameter constructor that sets the endpoints of the line segment
        LineSegment(Point point1, Point point2);
        
        double length(); // Method to calculate length of line segment
        double slope(); // Method to calculate slope of line segment
        
};
#endif