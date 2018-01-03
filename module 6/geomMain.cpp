/***************************************************************************
** Author: David Mednikov
** Date: 10/31/2016
** Description: 
***************************************************************************/
    
// LineSegmentMain.cpp is the Point class implementation file

#include "LineSegment.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    double xC1, xC2, yC1, yC2;
    
    cout << "Enter X-Coordinate of endpoint 1: ";
    cin >> xC1;
    cout << "Enter Y-Coordinate of endpoint 1: ";
    cin >> yC1;
    
    cout << "Enter X-Coordinate of endpoint 2: ";
    cin >> xC2;
    cout << "Enter Y-Coordinate of endpoint 2: ";
    cin >> yC2;
    
    Point point1(xC1, yC1);
    Point point2(xC2, yC2);
    
    LineSegment segment(point1, point2);
    
    cout << "The length of the line segment is " << segment.length() << endl;
    cout << "The slope of the line segment is " << segment.slope() << endl;

    return 0;
}