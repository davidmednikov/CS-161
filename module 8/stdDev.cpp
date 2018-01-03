/***************************************************************************
** Author: David Mednikov
** Date: 11/14/2016
** Description: This function takes two parameters, an array of pointers
to Student objects and the size of the array, and returns the standard
deviation of the scores contained in the student objects.
***************************************************************************/

#include "Student.hpp" // Include Student header file
#include <math.h> // Include math header for power and square root functions

/* Commenting out code related to the main function used for testing
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
*/

/***************************************************************************
Description: This function takes an array of pointers to students and the array
size as parameters and returns the standard deviation of the students' scores.
***************************************************************************/
double stdDev(Student* students[], int arraySize)
{
    double avg; // Double to store average
    double total = 0; // Running total to find sum of all student scores
    double score; // Double to hold score from each Student object
    
    // Loop through array to find sum of all student scores
    for (int i = 0; i < arraySize; i++)
    {
        score = (*students[i]).getScore();
        total += score;
    }
    
    // Calculate average score
    avg = total/arraySize;
    
    double sigma = 0; // Double to store sum of all variances
    double variance; // Double to store variance ( (score-mean)^2 )
    
    // Loop through array to find variance of each score and find sum of all variances
    for (int i = 0; i < arraySize; i++)
    {
        variance = pow(((*students[i]).getScore()-avg), 2);
        
        sigma += variance;
    }
    
    // Calculate and return standard deviation
    return sqrt(sigma/arraySize);
}

/* Commenting out main function
int main()
{
    int arraySize;
    string nm;
    double scr;
    double standardDev;
    
    cout << "How many students?" << endl;
    cin >> arraySize;
    
    Student* array[arraySize];
    
    for (int i = 0; i < arraySize; i++)
    {
        cout << "What's student #" << i+1 << "'s name?" << endl;
        cin >> nm;
        cout << "What's student #" << i+1 << "'s score?" << endl;
        cin >> scr;
        
        array[i] = new Student(nm, scr);
    }
    
    standardDev = stdDev(array, arraySize);
    
    cout << "The standard deviation is: " << standardDev << endl;
}
*/