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

void fixBackTwoNumbers(int* num1, int* num2, int* num3);

void smallSort2(int* firstNum, int* secondNum, int* thirdNum)
{
    if (*firstNum <= *secondNum)
    {
        fixBackTwoNumbers(firstNum, secondNum, thirdNum);
    }
    else
    {
        int temp = *secondNum;
        *secondNum = *firstNum;
        *firstNum = temp;
        
        fixBackTwoNumbers(firstNum, secondNum, thirdNum);
    }
    return;
}

void fixBackTwoNumbers(int* num1, int* num2, int* num3)
{
    if (*num2 <= *num3)
        return;
    else
    {
        
        if (*num1 > *num3)
        {
            int temp = *num3;
            *num3 = *num2;
            *num2 = *num1;
            *num1 = temp;
            return;
        }
        else
        {
            int temp = *num3;
            *num3 = *num2;
            *num2 = temp;
            return;
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