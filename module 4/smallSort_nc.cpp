/*********************************************************************
** Author: David Mednikov
** Date: 10/18/2016
** Description: This function takes three int parameters by reference
** and sorts them into order from least to greatest.
*********************************************************************/

#include<iostream>

using std::cout;
using std::cin;
using std::endl;
    
void smallSort(int &firstNum, int &secondNum, int &thirdNum)
{
    bool sorted = false;
    
    while (!sorted)    
    {
        if (firstNum > secondNum)
        {
            int holdValue = firstNum;
            firstNum = secondNum;
            secondNum = holdValue;
        }
        
        if (firstNum > thirdNum)
        {
            int holdValue = firstNum;
            firstNum = thirdNum;
            thirdNum = holdValue;
        }
        
        if (secondNum > thirdNum)
        {
            int holdValue = secondNum;
            secondNum = thirdNum;
            thirdNum = holdValue;
        }
        
        if (firstNum == secondNum)
        {
            if (firstNum > thirdNum)
            {
                int holdValue = firstNum;
                firstNum = thirdNum;
                thirdNum = holdValue;
                sorted = true;
            }
            else
                sorted = true;

        }
        
        if (secondNum == thirdNum)
        {
            if (firstNum > thirdNum)
            {
                int holdValue = firstNum;
                firstNum = thirdNum;
                thirdNum = holdValue;
                sorted = true;
            }
            else
                sorted = true;

        }
            
        if (firstNum == thirdNum)
        {
            if (firstNum > secondNum)
            {
                int holdValue = firstNum;
                firstNum = secondNum;
                secondNum = holdValue;
                sorted = true;
            }
            
            else if (firstNum < secondNum)
            {
                int holdValue = thirdNum;
                thirdNum = secondNum;
                secondNum = holdValue;
                sorted = true;
            }
            
            else
                sorted = true;

        }
        
        if (firstNum < secondNum && secondNum < thirdNum)
            sorted = true;
    }

    return;
}

int main()
{
    int intOne, intTwo, intThree;
    
    cout << "Please enter 3 integers." << endl;
    cin >> intOne >> intTwo >> intThree;
    smallSort(intOne, intTwo, intThree);
    cout << intOne << " " << intTwo << " " << intThree << endl;
}