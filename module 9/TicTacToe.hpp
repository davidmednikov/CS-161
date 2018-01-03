/*********************************************************************
** Author: David Mednikov
** Date: 11/22/2016
** Description: This TicTacToe class specification file contains two
** member variables, an object of the Board class and a character that
** keeps track of whose turn it is (X or O). The class contains 3 methods:
** a constructor that takes the first turn as a paramter, a play() method 
** which begins the game and loops through it until its over, and a setTurn() 
** method which switches whose turn it is after a player makes a successful move.
*********************************************************************/
// TicTacToe.hpp is the TicTacToe class specification file

#include "Board.hpp" // Include Board header file

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

class TicTacToe
{
    private:
        Board tBoard; // Object of Board class
        char whoseTurn; // Keeps track of whose turn it is
    
    public:
        TicTacToe(char firstMove); // Constructor that creates a game of TicTacToe and sets the first move
        void play(); // Method that starts the game and loops through it until there is a winner
        void setTurn(); // Method that changes whose turn it is after a successful move is made
};
#endif