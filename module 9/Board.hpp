/*********************************************************************
** Author: David Mednikov
** Date: 11/22/2016
** Description: This Board class specification file contains two member
** variables: a 3x3 two-dimensional array representing the game board
** and an int counter that keeps track of how many unoccupied squares 
** are left on the board. It includes a default constructor that initializes
** the 3x3 array and fills each element with a '.' character. It includes
** a method that attempts the move that the user inputted and returns a 
** boolean - true if the move was made, false if the square was already 
** occupied. It also includes a method that checks the state of the game 
** after each turn and returns one of 4 game states, which are  stated 
** in the enum line. Last, the Board class contains a print() method, 
** which prints out the current state of the Tic-Tac-Toe board.
*********************************************************************/
// Board.hpp is the Board class specification file

#ifndef BOARD_HPP
#define BOARD_HPP

enum gameStates {X_WON, O_WON, DRAW, UNFINISHED}; // Declare enum game states

class Board
{
    private:
        char gameBoard[3][3]; // Two-dimensional 3x3 array representing game board
        int squaresLeft; // Int counter variable that keeps track of how many squares are unoccupied
        
    public:
        Board(); // Default constructor, initializes array and squaresLeft variable
        bool makeMove(char whoseTurn, int xCoord, int yCoord); // Method that attempts to make the move and tells the user if it was successful
        gameStates gameState(); // Method that finds and returns the current game state
        void print(); // Method that prints the current game board to the terminal
};
#endif