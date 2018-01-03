Comments

comment blocks at the top of functions are too long, with not enough comments throughout the actual code. not sure each function does

comments need to be more concise and explain functions simpler with less words

pros: good organization
sorting the array first was smart

/******************************************************************************************************************
 ** Author: Adam Mercado
 ** Date: 11/9/16
 ** Description: This program returns the mode(s) of a user define array in ascending order
 ******************************************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*********************************************************************
 ** Description: The function findMode() processes an array to find
 ** the mode value(s) in that array. Several intermediate steps are executed
 ** in the function in order to find the mode. These steps include sorting
 ** the array that is passed ascendingly, finding the frequency of each value,
 ** finding the highest frequency for any element and obtaining each 
 ** individual element from the array.
 *********************************************************************/
vector<int> findMode(int array[], int size)
{
    /*********************************************************************
     ** Sort the array in ascending order. This allows the function to 
     ** obtain the individual values of the array. This also allows the 
     ** results vector to return multiple values in ascending order if 
     ** there is more than one mode.
     *********************************************************************/
    sort(array, array + size);
    
    /*********************************************************************
     ** Get the highest frequency value for any integer in the array. This
     ** is accomplished by declaring count to keep track of elements that
     ** repeat themselves in the for loop and comparing it to the highest 
     ** encountered count value. The array value with the highest count has 
     ** its frequency stored in the variable highest. Highest will be used
     ** later in the function in comparison with the frequency of each value.
     *********************************************************************/
    int count;
    //The variable highest is initialized to 0
    int highest = 0;
    for (int i = 0; i < size; i++)
    {
        //Count is reset after each iteration
        count = 0;
        
        for (int j = 0; j < size; j++)
        {
            if (array[i] == array[j])
                count++;
        }
        if (count > highest)
            highest = count;
    }
    
    /*********************************************************************
     ** Get the individual values that appear in the array and store in 
     ** the vector individuals. Since the array is sorted, we can iterate 
     ** through each element starting at index 0. If the starting element 
     ** isn't of equivalent value to the value to its right, push that
     ** non-recurring element into the individuals vector. We need the 
     ** individuals to find the frequency of each element.
     *********************************************************************/
    vector<int> individuals;
    
    for (int i = 0; i < size; i++)
    {
        if (array[i] != array[i+1])
            individuals.push_back(array[i]);
    }
    
    /*********************************************************************
     ** Get the frequency of each individual and store in the vector 
     ** frequencies. This is accomplished by using a counter variable
     ** and using the individuals as our outer loop while comparing them
     ** to each value in the array (the inner loop). The count variable keeps
     ** track of the number of times an individual is encountered in the
     ** array. At the end of each outer loop iteration, that individuals
     ** frequency is pushed to the vector frequencies.
     *********************************************************************/
    vector<int> frequencies;
    
    for (int i = 0; i < individuals.size(); i++)
    {
        //Count is reset after each iteration
        count = 0;
        for (int j = 0; j < size; j++)
        {
            if (individuals[i] == array[j])
                count++;
        }
        frequencies.push_back(count);
    }
    
    /*********************************************************************
     ** Get the highest frequency individual(s) and push into the results
     ** vector. This is accomplished by iterating through the entire
     ** frequency vector (whose indexes correspond to that of the individuals). 
     ** If an element in that vector corresponds to having the highest value 
     ** for count which was found earlier, push the individual value with the
     ** highest count into results. The value(s) that are in results correspond
     ** to the mode(s).
     *********************************************************************/
    vector<int> results;
    
    for (int i = 0; i < frequencies.size(); i++)
    {
        if (frequencies[i] == highest)
            results.push_back(individuals[i]);
    }
    
    return results;
}

//Main method for tesing purposes

/*int main()
{
    int nums[20] = {9, 8, 9, 8, 7, 1, 18, 11, 14, 2, 8, 7, 7, 2, 9, 2, 4, 18, 4, 18};
    vector<int> high = findMode(nums, 20);
    for (int i = 0; i<high.size(); i++)
        cout << high[i] << " ";
    cout << endl;
    
    return 0;
}
 */





