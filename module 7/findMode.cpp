/***************************************************************************
** Author: David Mednikov
** Date: 11/07/2016
** Description: This function takes an array and an integer (representing the
** size of the array), finds the most common numbers in the array (the modes),
** sorts the modes from least to greatest, and returns a vector containing 
** the modes to the code that called the function.
***************************************************************************/

#include <vector> // Needed to use vectors
#include <algorithm> // Needed to sort the vector at the end
// #include <iostream> (Used for debugging and testing, commented out)

/* Commenting out the std class objects used in the main program
using std::cin;
using std::cout;
using std::endl;
*/
using std::vector;

// Prototype of findMode
vector<int> findMode(int data[], int arraySize);

// Prototype of function to find the number of times the most common number appears
int getHighestTally(int data[], int arraySize); 

// Prototype of function that creates vector based on the most frequent numbers
vector<int> createVector(int data[], int arraySize, int highestTally);

/* Commenting out the main function
int main()
{
    cout << "Enter number of integers: ";
    int arrayLength;
    cin >> arrayLength;
    
    vector<int> sorted;
    
    int inputArray[1000];
    
    for (int numbers = 0; numbers < arrayLength; numbers++)
    {
        cout << "Enter number #" << numbers+1 << ": ";
        cin >> inputArray[numbers];
    }
    
    sorted = findMode(inputArray, arrayLength);
    
    cout << "Modes: ";
    for (int index = 0; index < sorted.size(); index++)
    {
        if (index == sorted.size() - 1)
            cout << sorted[index] << endl; // Last mode to be printed
        else
            cout << sorted[index] << ", ";
    }
}
*/

/***************************************************************************
Description: This function takes two parameters (an array and the array size),
creates a vector, finds the most common numbers (modes) of the inputted array, 
pushes the modes to the vector, sorts the vector, and returns it.
***************************************************************************/
vector<int> findMode(int data[], int arraySize)
{   
    vector<int> modes; // Create vector to contain modes
    
    int highestTally = getHighestTally(data, arraySize); // Find tally of most common number(s)
        
    modes = createVector(data, arraySize, highestTally); // Create vector of modes
    
    std::sort(modes.begin(), modes.end()); // Sort vector of modes
    
    return modes;
}

/***************************************************************************
Description: This function takes two parameters (an array and the array size)
and finds the number of times that the most frequent number(s) appear.
***************************************************************************/
int getHighestTally(int data[], int arraySize)
{
    int mostFrequent = 0; // Initialize most frequent tally to 0
    
    // Loop through vector to tally each number one at a time
    for (int index = 0; index < arraySize; index++)
    {
        int numRead = data[index];
        int tally = 0;
        
        // Nested loop to tally each number
        for (int ind = 0; ind < arraySize; ind++) 
        { 
            // Increment tally by 1 each time the number being tallied is encountered
            if (numRead == data[ind]) 
                tally++;
        }
        
        // If current tally is greater than previous most frequent tally, replace most frequent tally with current tally
        if (tally > mostFrequent)
            mostFrequent = tally;
        
    }
    
    return mostFrequent; // Return int containing most frequent tally
}

/***************************************************************************
Description: This function takes three parameters (an array, the array size,
and the most frequent tally), loops through the array to find numbers whose
tally equals the most frequent tally passed to the function. It checks to
make sure that the numbers to be added have not already been added (avoids 
duplicates) then writes non-duplicate modes to a vector and returns the vector.
***************************************************************************/
vector<int> createVector(int data[], int arraySize, int highestTally)
{
    vector<int> modes; // Create vector to be returned
    
    // Loop through array again, taking tally of each number
    for (int index = 0; index < arraySize; index++)
    {
        int numRead = data[index];
        int tally = 0;
        
        bool duplicate = false;
        
        for (int ind = 0; ind < arraySize; ind++)
        { 
            if (numRead == data[ind])
                tally++;
        }
        
        // Loop through vector to make sure mode being added has not already been added
        for (int i = 0; i < modes.size(); i++)
        {
            if (modes.at(i) == numRead)
                duplicate = true;
        }
        
        // If tally equals most frequent tally and the number is not duplicate, add it to the vector
        if (tally == highestTally && duplicate == false)
        {
            modes.push_back(numRead);
        }
    }
    
    return modes; // Return vector to findMode
}