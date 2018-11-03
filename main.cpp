#include <iostream>
#include <vector>
#include <bits/stdc++.h>
//math.h has the pow function
#include <math.h>
using namespace std;

/*
This program has the following rules:
-The inputs are not limited.
-The outputs are sorted alphabetically.
-The output set has no duplicates.
-
*/

//inputString is the user given input.
//subsetIndex is the index of the current subset (currentSubset)
//currentSubset stores the current subset
void subset(vector <char> &inputSting, int subsetIndex = -1, string currentSubset = "")
{
    int n = inputSting.size();

    //Terminate the program if the
    if (subsetIndex == n)
        return;
    //Print the subset

    cout << currentSubset << endl;
    //sort the output alphabetically
    sort(inputSting.begin(), inputSting.end()-1);

        //the minus 1 is to remove the termination character from the output, so the loop only check up to the next to last element
        //this loop runs once per element of the vector
       for(int i = subsetIndex + 1; i < n-1; i++)
    {
        currentSubset += inputSting[i];
        subset(inputSting, i, currentSubset);

        currentSubset.erase(currentSubset.size()-1);
    }
    return;
}

char totalElements;

int main()
{
    vector <char> inputString;
    cout << "Enter characters, press '`' then the Enter key to terminate ";
    do{
        //Get input, then put it in the vector
        cin >> totalElements;
        inputString.push_back(totalElements);

    }
    //This loop runs until the user presses "`".
   while(totalElements != '`');{
        cout << "The input has " << int(inputString.size()-1) << " elements, here is the ordered subsequence:";

    }

    //Use the inputString function to print out the results
    subset(inputString);

    //Number of subsets is calculated based off of the formula (n^2)-1, the first -1 is to account for the terminating character.
    cout << "The given input has: " << int (pow (inputString.size()-1, 2)-1) <<" subsets";
    return 0;


}


