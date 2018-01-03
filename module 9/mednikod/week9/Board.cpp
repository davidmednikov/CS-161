/*********************************************************************
** Author: David Mednikov
** Date: 11/22/2016
** Description: This Board class implementation file defines the default
** constructor of the Board class. It also defines the makeMove() method
** (which attempts to make a move that the user inputted and returns a
** boolean that tells the program whether or not it was successful),
** the gameStates() method which checks the current status of the game
** board after each turn and returns an enumerated value to the program,
** and the print() method which prints the current state of the game
** board to the terminal window.
*********************************************************************/
// Board.cpp is the Board class implementation file

#include "Board.hpp" // Include Board header file
#include <iostream> // Necessary for handling user input
using std::cin;
using std::cout;
using std::endl;

/**********************************************************************
This function is the default constructor, it initializes the 3x3 game board
array and sets each value to '.' . It also initializes the value of the
squaresLeft variable (used to determine when the game is a draw) to 9.
**********************************************************************/
Board::Board()
{
    for (int row = 0; row < 3; row++) // Loop through rows
    {
        for (int col = 0; col < 3; col++) // Loop through columns
        {
            gameBoard[row][col] = '.'; // Fill each square with a '.' character
        }
    }
    
    squaresLeft = 9; // Initialize squaresLeft counter to 9
}

/**********************************************************************
This function attempts to make a move (inputted by the user) and returns
a boolean that tells the program whether or not it was successful. Its
three parameters are (1) whose turn it currently is and (2) the 2 coordinates
of the square that the player wants to occupy. If the square that the user
wants to fill already contains an 'x' or an 'o', the function will return 
false and the program will instruct the user to enter another coordinate. If 
the square that the user inputs is blank, the function will fill that 
square with the character of whose turn it is, decrease the squaresLeft
counter by 1, and return true to the program so that it knows to go to
the other player's turn.
**********************************************************************/
bool Board::makeMove(char whoseTurn, int xCoord, int yCoord)
{
    if (gameBoard[xCoord][yCoord] == 'X' || gameBoard[xCoord][yCoord]=='O') // If square already contains an X or O, move cannot be made
        return false; // Tell program that the move was not made because the square is already occupied
    else // If square is not occupied, program can make move
    {
        gameBoard[xCoord][yCoord] = whoseTurn; // Fill square on game board with X or O, depending on whose turn it is
        squaresLeft--; // Decrease squaresLeft counter by 1 after successful turn
        return true; // Tell program that the move was made successfully.
    }
}

/**********************************************************************
This function checks the current state of the game after each successful
move. It first checks to see if there are any diagonal winning combinations.
It then checks to see if there are any 3-in-a-row winning combinations.
It then checks to see if there are any 3-in-a-column winning combinations.
If there are no winning combinations, the function checks how many squares
are left on the board. If there is no winner and the board is completely
filled, the function tels the program that the game is a draw. If there
are still squares left the function tells the program that the game is unfinished.
**********************************************************************/
gameStates Board::gameState()
{
    // Check the game for diagonal winning combinations and return the winner
    if (gameBoard[0][0] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][2] == 'X')
        return X_WON;
    if (gameBoard[0][0] == 'O' && gameBoard[1][1] == 'O' && gameBoard[2][2] == 'O')
        return O_WON;
    if (gameBoard[2][0] == 'X' && gameBoard[1][1] == 'X' && gameBoard[0][2] == 'X')
        return X_WON;
    if (gameBoard[2][0] == 'O' && gameBoard[1][1] == 'O' && gameBoard[0][2] == 'O')
        return O_WON;
    
    // Check the game for any 3-in-a-row winning combinations and return the winner
    for (int row = 0; row < 3; row++)
    {
        if (gameBoard[row][0] == 'X' && gameBoard[row][1] == 'X' && gameBoard[row][2] == 'X')
            return X_WON;
        if (gameBoard[row][0] == 'O' && gameBoard[row][1] == 'O' && gameBoard[row][2] == 'O')
            return O_WON;
    }
    
    // Check the game for any 3-in-a-column winning combinations and return the winner
    for (int col = 0; col < 3; col++)
    {
        if (gameBoard[0][col] == 'X' && gameBoard[1][col] == 'X' && gameBoard[2][col] == 'X')
            return X_WON;
        if (gameBoard[0][col] == 'O' && gameBoard[1][col] == 'O' && gameBoard[2][col] == 'O')
            return O_WON;
    }
    
    // If there are no winning combinations, check to see how many squares are left
    if (squaresLeft == 0) // If there are 0 squares left, the game is a draw. Return DRAW to program
        return DRAW;
    else // There are still squares left on the game, but no winner, so the game is unfinished
        return UNFINISHED;
}

/**********************************************************************
This function prints the current state of the game board to the terminal
window. It first prints the header line, then loops through each row,
printing out the row number and the 3 values in that row of the array.
**********************************************************************/
void Board::print()
{
    cout << "\n   0  1  2\n" << endl; // Print game board header
    
    for (int row = 0; row < 3; row++) // Loop through rows
    {
        cout << row << "  "; // Print row number
        
        for (int col = 0; col < 3; col++) // Loop through columns
        {
            cout << gameBoard[row][col] << "  "; // Print each element in each row
        }
        
        cout << endl << endl; // Skip a line for neatness
    }
}
