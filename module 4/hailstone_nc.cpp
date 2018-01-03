/*********************************************************************
** Author: David Mednikov
** Date: 10/18/2016
** Description: This function takes a positive integer parameter, and
** creates a hailstone sequence out of it. Even numbers are divided by
** 2, odd numbers are multiplied by 3 and then incremented by 1. The
** function will return the total number of steps it takes for the
** hailstone sequence to reach 1.
*********************************************************************/

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int hailstone(int startingNum)
{
    int steps = 0;
    bool reachedOne = false;
    
    while (reachedOne == false)
    {
        if (startingNum == 1)
        {    
            return steps;
        }
        else if (startingNum % 2 == 1)
        {
            startingNum = (startingNum*3) + 1;
        }
        else
        {
            startingNum /= 2;
        }
        
        steps++;
    }
    
}

int main()
{
    int startingNum;
    
    cout << "Which number do you want to start with?" << endl;
    cin >> startingNum;
    
    while (startingNum < 1)
    {
        cout << "Please enter a positive integer." << endl;
        cin >> startingNum;
    }
    
    int steps = hailstone(startingNum);
    
    cout << "The hailstone sequence took a total of " << steps;
    cout << " steps to reach 1." << endl;
}