/*********************************************************************
** Author: David Mednikov
** Date: 10/03/2016
** Description: This program asks the user to enter an amount of cents
** between 0 and 99. The program then calculates the minumum number of
** coins to equal that amount and returns it to the user.
*********************************************************************/
#include<iostream>

using namespace std;

int main()
{
    int cents,
           centsLeft,
           quarters,
           dimes,
           nickels,
           pennies;
     
    /* Ask the user to enter the total number of cents to be converted
        into change using the minum number of coins */
    cout << "Please enter an amount in cents less than a dollar." << endl;
    cin >> cents;
    
    /* Use the most valuable coins first to get the minumum total number of coins. So start
       with quarters, then dimes, then nickels, and lastly find the number of pennies. */
     
    /* Calculate how many quarters are given, then find the remainder of dividing
       by 25 to get the number of cents remaining after quarters. */
    quarters = cents / 25;
    centsLeft = cents % 25;
    
    /* Calculate how many dimes are given (after quarters), then find the remainder of
       dividing by 10 to get the number of cents remaining after dimes. */
    dimes = centsLeft / 10;
    centsLeft %= 10;
    
    /* Calculate how many nickels are given (after dimes), then find the remainder of
       dividing by 5 to get the number of cents remaining after nickels. */
    nickels = centsLeft / 5;
    centsLeft %= 5;
    
     // The remaining number of cents is how many pennies are given
    pennies = centsLeft;
    
    cout << "Your change will be:" << endl;
    cout << "Q: " << quarters << endl;
    cout << "D: " << dimes << endl;
    cout << "N: " << nickels << endl;
    cout << "P: " << pennies << endl;
    
    return 0;
}