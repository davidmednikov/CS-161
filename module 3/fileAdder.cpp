/*********************************************************************
** Author: David Mednikov
** Date: 10/11/2016
** Description: This program asks the user for a file name, opens the
** text file, calculates the sum of all numbers in the text file,
** and saves the value of the sum to a new file called "sum.txt".
*********************************************************************/

#include<fstream>
#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

int main()
{
    string fileName; // File name entered by user
    int line, sum = 0; // Line in text file; sum of lines
    ifstream inputFile; // File input stream object
    ofstream outputFile; // File output stream object
    
    // Get file name from user
    cout << "Please enter the file name: ";
    cin >> fileName;
    
    // Open text file in input object stream
    inputFile.open(fileName);
    
    if (inputFile) // Read file if input object can open it
    {        
        while (inputFile >> line) // Read each line until end of document
        {
            sum += line; // Add line to sum
        }
        
        inputFile.close(); // Close input file stream
        outputFile.open("sum.txt"); // Create file from output stream object
        outputFile << sum; // Write sum to new text file
        outputFile.close(); // Close output file stream
    }
    else // When program cannot open file name
    {
        cout << "could not access file" << endl;
    }
    
    return 0;
}