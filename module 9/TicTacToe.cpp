/*********************************************************************
** Author: David Mednikov
** Date: 11/22/2016
** Description: This TicTacToe class implementation file defines the
** TicTacToe constructor, which takes whoever goes first as a parameter.
** It defines the setTurn() function, which changes whose turn it is after
** a successful move id made. It also defines the play function, which
** asks the user who goes first and loops through the game until there
** is a winner or a draw. Last, this file defines the main method, which
** is how the user interacts with the program so that they can play the game.
*********************************************************************/
// TicTacToe.cpp is the TicTacToe class implementation file

#include "TicTacToe.hpp" // Include TicTacToe header file
#include <iostream> // Necessary for handling user input
using std::cin;
using std::cout;
using std::endl;

/**********************************************************************
This function is the constructor, it creates a new game of TicTacToe
(which in turn initializes a new game board) and sets who goes first.
**********************************************************************/
TicTacToe::TicTacToe(char firstMove)
{
    whoseTurn = firstMove; // Set whoseTurn variable of TicTacToe object
}

/**********************************************************************
This function changes whose turn it is after a successful move. Runs
once at the end of each successful move.
**********************************************************************/
void TicTacToe::setTurn()
{
    if (whoseTurn == 'X') // If X just went, switch to O
        whoseTurn = 'O';
    else // O just went, so switch turn to X
        whoseTurn = 'X';
}

/**********************************************************************
This function begins the game of TicTacToe and loops over and over again
until there is a winner or draw. It asks the player whose turn it is for 
the coordinates of the square they want to occupy, makes sure those are
valid, then sends them to the makeMove() function, which tells the program
whether or not the move was successful. If the move could not be made
because the square was already occupied, the program tells the user to try
a different square. After making a successful move, the program checks
the game board to find the status of the game - whether there is a winner,
draw, or if it is still in progress. After checking the game state, this
function switches whose turn it is so that the other player can make a move.
**********************************************************************/
void TicTacToe::play()
{
    int xC, yC; // Coordinates of square that the player wants to take
    bool gameFinished = false; // Bool to make program loop through game until there is a final outcome
    bool validMove; // Bool that checks whether or not the move made by the player is valid. Uses makeMove() method
    
    // Loop until gameFinished is changed to true
    while (!gameFinished) 
    {
        tBoard.print(); // Print out current state of board
        
        cout << "Player " << whoseTurn << ": please enter your move." << endl; // Prompt player for their turn
        
        cin >> xC >> yC; // Assign coordinates to input variables
        
        // Make sure that variables fall within the acceptable range (between 0 and 2)
        while (xC < 0 || xC > 2 || yC < 0 || yC > 2)
        {
            cout << "You did not enter a valid square. Please enter the coordinates of a square on the board." << endl;
            
            cin >> xC >> yC;
        }
        
        validMove = tBoard.makeMove(whoseTurn, xC, yC); // Send variables and whoseTurn to makeMove function, which returns a bool
        
        // If makeMove() returns false, tell the user that the square was occupied so they need to enter another square
        while (!validMove)
        {
            cout << "That space is occupied. Please enter a different move." << endl;
            
            cin >> xC >> yC;
            
            // Validate user input like before
            while (xC < 0 || xC > 2 || yC < 0 || yC > 2)
            {
                cout << "You did not enter a valid square. Please enter the coordinates of a square on the board." << endl;
                
                cin >> xC >> yC;
            }
            
            // Try makeMove() function again with new inputs. If it fails, go back to top of while loop, if it is successful, move on to checking game state
            validMove = tBoard.makeMove(whoseTurn, xC, yC);
        }
        
        // If gameState() returns X_WON, tell users that X is the winner
        if (tBoard.gameState() == X_WON)
        {
            tBoard.print(); // Print current game board
            cout << "Congratulations Player X, you have won the game!" << endl;
            gameFinished = true; // Break out of while loop that keeps game going
        }
        // If gameState() returns O_WON, tell users that O is the winner
        else if (tBoard.gameState() == O_WON)
        {
            tBoard.print(); // Print current game board
            cout << "Congratulations Player O, you have won the game!" << endl;
            gameFinished = true; // Break out of while loop that keeps game going
        }
        // If gamestate() returns DRAW, tell users that there is no winner
        else if (tBoard.gameState() == DRAW)
        {
            tBoard.print(); // Print current game board
            cout << "Looks like this one's a tie! Better luck next game!" << endl;
            gameFinished = true; // Break out of while loop that keeps game going
        }
        
        setTurn(); // If the gameState() method returns UNFINISHED, change whose turn it is and loop back up to the top
        
    }
       
}

/**********************************************************************
This is the main function, it allows the user to interact with the program
and play a game of TicTacToe. It first asks the user who's going first,
validates the input, then initializes an object of the TicTacToe class,
sending over whoever goes first as a parameter. It then runs the play()
function, which begins a game of TicTacToe.
**********************************************************************/
int main()
{
    char first; // char variable containing who goes first
    cout << "Who's going first? X or O?" << endl; // Ask user who should go first
    cin >> first; // Assign input to first variable
    
    if (first=='x') // Capitalize lowercase x to X
        first = 'X';
    else if (first=='o')// Capitalize lowercase o to O
        first='O';
    
    // If input is not X or O, ask user for another input. Loop until inputs are valid
    while (first !='X' && first != 'O')
    {
        cout << "You didn't enter a valid input. Who's going first?" << endl;
        
        cin >> first;
    
        // Capitalize inputs
        if (first=='x')
            first = 'X';
        else if (first=='o')
            first='O';
    }
    
    // Create object of TicTacToe called game, send first as a paramter to the constructor
    TicTacToe game = TicTacToe(first);
    
    game.play(); // Play a game of TicTacToe
    
    return 0;
} 