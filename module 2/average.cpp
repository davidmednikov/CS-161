/*********************************************************************
** Author: David Mednikov
** Date: 10/03/2016
** Description: This program asks the user for 5 numbers, then computes
** the average and returns it to the user.
*********************************************************************/
#include<iostream>

using namespace std;

int main()
{
    double numOne,
           numTwo,
           numThree,
           numFour,
           numFive,
           sum,
           average;
    
    // Ask the user to input 5 numbers
    cout << "Please enter five numbers." << endl;
    cin >> numOne;
    cin >> numTwo;
    cin >> numThree;
    cin >> numFour;
    cin >> numFive;
    
    // Find the sum of the 5 numbers
    sum = numOne + numTwo + numThree + numFour + numFive;
    
    // Divide the sum by 5 to get the average
    average = sum/5.0;
    
    cout << "The average of those numbers is:\n" << average << endl;
    
    return 0;
}