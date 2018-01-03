comments

easy to read
good spacing
explains code function well

cons: doesnt check for duplicates in the output vector

/*******************************************************************************************
Author: Marisa Rea
Date: 11/7/2016
Description: Assignment 7
This program finds the mode (most frequent) value from an array of integers.
*******************************************************************************************/

// COMMENT OUT MAIN BEFORE SUBMITTING!!!

//#include "stdafx.h" //COMMENT OUT
#include <algorithm>    
#include <vector>       
#include <iostream>
#include <string>
#define MAXNUMBEROFINTS 300

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;

vector<int> result;

int arrayInt, numOfInt;
int arrayOfInts[MAXNUMBEROFINTS];
int currentIndex = 0,
	mostFrequent = 1;
string userInput;

vector<int> findMode(int[], int);

/*
int main() {

	while (currentIndex < MAXNUMBEROFINTS)
	{
		cout << "Please enter an integer. Enter \" q \" when you have finished inputting integers. ";

		cin >> userInput;

		// see if user has entered "q" to finish inputting integers
		if (userInput != "q")
		{
			arrayInt = atoi(userInput.c_str());
			arrayOfInts[currentIndex++] = arrayInt;
			numOfInt++;
		}

		else // user entered "q" so quit input process
			break;

		if (currentIndex >= MAXNUMBEROFINTS) // user reached maximum number
			cout << "You have reached the max number of integers that you can enter." << endl;
	}

	vector<int> modes = findMode(arrayOfInts, numOfInt);

	cout << result[0] << "  ";
	cout << result[1] << "  ";
	//cout << result[2] << "  ";

	cin.get();
	cin.get();

	return 0;
}
*/

/**************************************************************
*Function: findMode
*This function finds the mode (most frequently occuring) integers 
and collects them into a vector. It sorts the values from smallest 
to largest.
************************************************************/

vector<int> findMode(int numbers[], int size) {

	//compare the first value
	for (int valueA = 0; valueA < size; valueA++)
	{
		int frequency = 1;	//count how frequently value occurs

		//compare the second value
		for (int valueB = valueA + 1; valueB < size; valueB++)
		{

			//if the values match increase frequency
			if (numbers[valueA] == numbers[valueB]) 
			{
				frequency++;
			}
		}

				//if frequency matches mostFrequent then add value to vector
				if (frequency == mostFrequent) 
				{
					result.push_back(numbers[valueA]);
				}

				/*if a value is more frequent than the previous most frequent value, erase previous value and
				replace with new value. */
				if (frequency > mostFrequent) 
				{							 
					mostFrequent = frequency;
					result.clear();
					result.push_back(numbers[valueA]);
				}
		}
	

	sort(result.begin(), result.end());

	return result;
}