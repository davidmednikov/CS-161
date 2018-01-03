/*********************************************************************
** Author: David Mednikov
** Date: 10/05/2016
** Description: This program will ask the user for a number which
** another user will attempt to guess. The program will tell the 2nd
** user if their guess is too high or too low and instruct them to
** guess again. When the 2nd user guesses the correct number, the
** program will tell them how many guesses it took.
*********************************************************************/

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
        int target, // Number to be guessed, entered by 1st user
            guess, // Number guessed by 2nd user
            totalGuesses = 0; // Number of guesses so far, starts at 0
        
        bool rightGuess = false; // Condition so that while loop runs until user enters correct number
        
        cout << "Enter the number for the player to guess." << endl; // Ask 1st user for number
        cin >> target; // Number to be guessed by 2nd user
        
        cout << "Enter your guess." << endl; // Ask 2nd user to guess
        
        // Tell user if guess is too high or too low
        // If guess is correct tell user how many total guesses they took
        while (rightGuess == false)
        {
            cin >> guess; // Read guess from 2nd user
            
            if (guess == target)
                rightGuess = true; // Makes while loop's test condition false
            if (guess > target)
                cout << "Too high - try again." << endl;
            if (guess < target)
                cout << "Too low - try again." << endl;
            
            totalGuesses++; // Increment number of guesses by 1
        }
        
        cout << "You guessed it in " << totalGuesses << " tries." << endl;
        
        return 0;
        
}