/*********************************************************************
** Author: David Mednikov
** Date: 11/14/2016
** Description: This Student class specification file contains two member
variables, a string containing the student's name and a double containing
the student's score. It has get methods for both member variables and a
constructor that takes the student's name and score as its 2 arguments.
*********************************************************************/
// Student.hpp is the Student class specification file

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
using std::string;

class Student
{
    private: // Member variables of Student class
        string name;
        double score;
        
    public:
        Student(string nm, double scr); // Two-parameter constructor that sets member variables
        string getName(); // Method that returns student's name
        double getScore(); // Method that returns student's score
};
#endif