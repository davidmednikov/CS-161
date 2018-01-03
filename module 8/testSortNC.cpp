/*********************************************************************
** Author: David Mednikov
** Date: 11/14/2016
** Description: This function takes the addresses of three int variables
** and sorts the ints at those addresses into order from least to greatest.
*********************************************************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// Parameter for method to sort 2nd and 3rd inputted numbers
void fixBackTwoNumbers(int* num1, int* num2, int* num3);

/***************************************************************************
Description: This method takes the address of 3 integers and sorts them
from least to greatest. It does not sort them by address but rather by the
value in the address they point to.
***************************************************************************/
void smallSort2(int* firstNum, int* secondNum, int* thirdNum)
{
    // If first two numbers are in order, use fixBackTwoNumbers function to sort last 2
    if (*firstNum <= *secondNum)
    {
        // Sort 2nd and 3rd numbers, 1st is already sorted
        fixBackTwoNumbers(firstNum, secondNum, thirdNum);
    }
    else // This else code runs when the 1st input is greater than the 2nd
    {
        // Swap the 1st and 2nd input so that only the 2nd and 3rd need to be sorted
        int temp = *secondNum;
        *secondNum = *firstNum;
        *firstNum = temp;
        
        // Sort 2nd and 3rd numbers, 1st is already sorted
        fixBackTwoNumbers(firstNum, secondNum, thirdNum);
    }
    return; // Return to calling function when numbers are sorted
}

/***************************************************************************
Description: This method sorts the 2nd and 3rd inputted numbers. It assumes
that the 1st inputted number is already <= the 2nd inputted number. This
function is only called by the smallSort2 function if the 1st input <= 2nd.
***************************************************************************/
void fixBackTwoNumbers(int* num1, int* num2, int* num3)
{
    // If variable that num2 is pointing to is <= variable that num3 is pointing to:
    if (*num2 <= *num3)
        return; // All inputs are in order, return to calling function
    
    else // This else code runs when the 3rd input is greater than the 2nd input
    {
        // If 1st input is greater than 3rd input
        if (*num1 > *num3)
        {
            // Move 3rd input to 1st input, move 1st input to 2nd, move 2nd to 3rd
            int temp = *num3;
            *num3 = *num2;
            *num2 = *num1;
            *num1 = temp;
            return; // Inputs in order, return to calling function
        }
        else // This else code runs when the 1st input is <= 3rd input
        {
            // All that needs to be done is swap the 3rd and 2nd inputs
            int temp = *num3;
            *num3 = *num2;
            *num2 = temp;
            return; // Inputs in order, return to calling function
        }
    }
}

int main ()
{

    int firstNum, secondNum, thirdNum;

    cout << "First number: ";
    cin >> firstNum;
    cout << "Second number: ";
    cin >> secondNum;
    cout << "Third number: ";
    cin >> thirdNum;
    
    smallSort2(&firstNum, &secondNum, &thirdNum);
    
    cout << "Sorted: " << firstNum << ", " << secondNum << ", " << thirdNum << endl;
             
}