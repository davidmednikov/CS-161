/*********************************************************************
** Author: David Mednikov
** Date: 10/03/2016
** Description: This program asks the user for a temperature in
** Celsius, converts it to Fahrenheit, and then returns it to the user.
*********************************************************************/
#include<iostream>

using namespace std;

int main()
{
    double celsius,
           fahrenheit;
           
    // Ask the user to input a temperature in Celsius
    cout << "Please enter a Celsius temperature.\n";
    cin >> celsius;
    
    // Convert the Celsius temperature to Fahrenheit
    fahrenheit = 1.8 * celsius + 32;
    
    // Return the temperature in Fahrenheit to the user
    cout << "The equivalent Fahrenheit temperature is:\n" << fahrenheit << endl;
    
    return 0;
}