/*********************************************************************
** Author: David Mednikov
** Date: 10/18/2016
** Description: This function takes an amount of time as an argument
** and returns the number of meters that an object falls within that
** time. This program assumes no forces acting upon the object as it
** falls - i.e. freefall. The main function has been commented out.
*********************************************************************/

#include<iostream>
#include<cmath>


using std::cout;
using std::cin;
using std::endl;

double fallDistance(double timeFallen)
{
    const double GRAVITY_ACC = 9.8;
    
    return (0.5)*(GRAVITY_ACC)*pow(timeFallen, 2.0);
}

int main()
{    
    double timeFallen;
    double fallenDistance;
    
    cout << "How many seconds?\n";
    cin >> timeFallen;
    
    while (timeFallen < 0)
    {
        cout << "Time cannot be negative. Please enter a number greater than or equal to 0." << endl;
        cin >> timeFallen;
    }
    
    fallenDistance = fallDistance(timeFallen);
    cout << "The object falls " << fallenDistance << " meters" << endl;
}