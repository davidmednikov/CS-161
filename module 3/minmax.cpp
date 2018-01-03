/*********************************************************************
** Author: David Mednikov
** Date: 10/08/2016
** Description: This program will calculate the maximum and minimum of
** a series of numbers entered by the user. The program will first ask
** the user how many integers they would like to enter, then asks the
** user to input each integer one at a time. After each integer is 
** entered, the program will compare the entered number to the current
** maximum and minumum numbers and overwrite them if necessary. The
** program will then return the maximum and minumum numbers to the user.
*********************************************************************/


#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int totalIntegers, // number of integers user wants to enter
        input,         // most recently entered integer
        currentMax,
        currentMin;
        
    // Ask user for number of integers they want to enter
    cout << "How many integers would you like to enter?" << endl;
    cin >> totalIntegers;
        
    // Ask user to enter each integer one at a time
    cout << "Please enter " << totalIntegers << " integers.\n";
    
    // Flag to assign first input as the max and min
    bool firstRun = true;
    
    // Ask user to enter integers one at a time until reaching number entered by user
    // At end of each for loop iteration compare the most recently inputted number with max and min
    
    for (int num = 1; num <= totalIntegers; num++)
    {
        cin >> input;
        
        // only runs once to set first input as the max and min
        if (firstRun == true)
        {
            currentMax = currentMin = input;
            firstRun = false;
        }
        
        // If input is less than min replace value stored in currentMin with input
        if (input < currentMin)
            currentMin = input;
        
        // If input is more than max replace value stored in currentMax with input
        if (input > currentMax)
            currentMax = input;
    }
    
    // Return max and min to user
    cout << "min: " << currentMin << endl;
    cout << "max: " << currentMax << endl;
    
    return 0;
    
}
        
        
    
    