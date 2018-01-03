/***************************************************************************
** Author: David Mednikov
** Date: 10/31/2016
** Description: This LineSegment class implementation file defines the
** two-parameter constructor that sets the endpoints, the get and set methods
** for each endpoint, and the methods that calculate the length and slope
** of the line segment.
***************************************************************************/
    
// LineSegment.cpp is the LineSegment class implementation file

#include "LineSegment.hpp"  // Include LineSegment specification file

// Two-parameter constructor that sets endpoints of line segment
LineSegment::LineSegment(Point p1, Point p2)
{  
    setEnd1(p1);
    setEnd2(p2);
}

void LineSegment::setEnd1(Point p1) // Set endpoint1 of line segment
{
    endpoint1 = p1;
}

void LineSegment::setEnd2(Point p2) // Set endpoint2 of line segment
{
    endpoint2 = p2;
}

Point LineSegment::getEnd1() // Get endpoint1 of line segment
{
    return endpoint1;
}

Point LineSegment::getEnd2() // Get endpoint2 of line segment
{
    return endpoint2;
}

// Calculate length of line segment (distance between two endpoints)
double LineSegment::length()
{
    return endpoint1.distanceTo(endpoint2);
}

// Calculate slope of line segment using formula slope = (Y2 - Y1)/(X2 - X1)
double LineSegment::slope()
{
    return ((endpoint2.getYCoord() - endpoint1.getYCoord())/(endpoint2.getXCoord() - endpoint1.getXCoord()));
}



    
    