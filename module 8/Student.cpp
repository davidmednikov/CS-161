/*********************************************************************
** Author: David Mednikov
** Date: 11/14/2016
** Description: This Student class implementation file defines the set
methods for the two member variables (name and score) as well as a two-
parameter constructor that takes the name and score as variables and
saves them to the member variables.
*********************************************************************/
// Student.cpp is the Student class implementation file

#include "Student.hpp" // Include Student header file

Student::Student(string nm, double scr) // Two-parameter constuctor to set member variables
{
    name = nm;
    score = scr;
}

string Student::getName() // Return student's name
{
    return name;
}

double Student::getScore() // Return student's score
{
    return score;
}