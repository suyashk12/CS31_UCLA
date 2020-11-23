#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool hasDuplicates(const string array[], int size);
int countAllDigits(const string array[], int size);
bool isInDecreasingOrder(const string array[], int size);
int shiftRight(string array[], int size, int amount, string placeholder);
int find(const string array[], int size, string match);
int replaceAllCharacters(string array[], int size, char findLetter, char replaceLetter);

int main()
{
    cout.setf(ios::boolalpha);
    
    string subjects[5]={"Phy","Chem1223","Business","Algebra12","Phy"};
    
    cout<<hasDuplicates(subjects, 5)<<endl;
    cout<<hasDuplicates(subjects, -5)<<endl;
    cout<<countAllDigits(subjects, 5)<<endl;
    cout<<countAllDigits(subjects, 2)<<endl;
    cout<<countAllDigits(subjects, 0)<<endl;
    cout<<isInDecreasingOrder(subjects, 5)<<endl;
    cout<<isInDecreasingOrder(subjects, 0)<<endl;
    cout<<isInDecreasingOrder(subjects, -1)<<endl;
    cout<<shiftRight(subjects, 4, 0, "foo")<<endl;
    cout<<find(subjects, 5, "Phy")<<endl;
    cout<<replaceAllCharacters(subjects, 5, 'e', '_')<<endl;
    
    for(int i=0; i<5; i++)
    {
        cout<<subjects[i]<<endl;
    }
    
    return(0);
}

// Defining hasDuplicates function

bool hasDuplicates(const string array[], int size){
    if(size>0)
    {
        bool check = false; // Assume initially that there are no duplicates
        for(int i=0; i<size; i++)      // Looping through the array to obtain string src to which the other strings in the array have to be compared
        {
            string src = array[i];
            
            for(int j=i+1; j<size; j++)  // We loop again through to obtain various strings dest in the array to compare them with src. We begin looping here from i+1 because the previous elements would already have been tested in the previous iteration of the outer loop.
            {
                string dest = array[j];
                if(dest==src)
                {
                    check = true;  // Duplicate found, set check to true and break away from the inner loop.
                    break;
                }
            }
            if(check)  // If check was set to true in the inner loop, break out of the outer loop as well.
            {
                break;
            }
        }
        
        return(check); // Will return true if duplicates were found, and false if none were found.
        
    }
    else
    {
        return(false); // Returns false as size of the size parameter of the array was non-positive.
    }
}

// Defining countAllDigits function

int countAllDigits(const string array[], int size)
{
    if(size>0)
    {
        int tracker=0;     // To keep track of the number of digits in the array
        for(int i=0; i<size; i++)
        {
            for(int j=0; j<array[i].length(); j++)
            {
                char chardigit = array[i][j];
                int digit = chardigit - '0';  // Conversion from ASCII to integer
                if(digit>=0 && digit<=9)   // If digit is a digit, it should lie between 0 and 9
                {
                    tracker+=1;   // Updating the number of digits found so far
                }
            }
        }
        return(tracker);
    }
    else
    {
        return(-1);  // Returns false as size of the size parameter of the array was non-positive.
    }
}

// Defining isInDecreasingOrder function

bool isInDecreasingOrder(const string array[], int size)
{
    if(size>=0)
    {
        bool check = true;  // Assume initially that the strings in the array are in decreasing order.
        
        for(int i=0; i<size-1; i++)  // We index till the second-last element of the array since we are comparing elements pairwise, so we check the second last element with the last. The loop won't run for size 1 or 0, so check will remain true.
        {
            string present = array[i];
            string next = array[i+1];
            if(next>present)  // Comparing the present and the next string lexicographically. If next<present, then the array's strings are in decreasing order, however, if next>present, then the strings aren't in decreasing order.
            {
                check = false; // As next>present, the array's strings were not in decreasing order, so we set check as false
                break; // We break out of the loop the instance we recognize that the array's contents weren't in decreasing order.
            }
        }
        
        return(check); // Returns true if the array is in decreasing order (which includes the case of the size being one or zero), but false if it isn't.

    }
    
    else
    {
        return(false); // Returns false as the size parameter is negative.
    }
}

// Defining shiftRight function

int shiftRight(string array[], int size, int amount, string placeholder)
{
    if(size>0 && amount>0)     // Shifts will actually be performed only if both size and amount is positive.
    {
        if(amount<size)
        {
            string oldstr;    // First dummy variable
            string newstr;    // Second dummy variable
            
            for(int i=0; i<amount; i++)  // We place the string placeholder at the first position in each iteration of this loop, while shifting the rest of the elements one position towards the right.
            {
                for(int j=0; j<size; j++) // Inner loop to index through all contents of the array.
                {
                    if(j==0)    // When at the first element of the array.
                    {
                        oldstr = array[j];         // Storing the first string in oldstr.
                        array[j] = placeholder;    // Make the first element of the array placeholder.
                    }
                    
                    else  // For second element of the array and further.
                    {
                        newstr = array[j];      // First storing the string at position j in the array into newstr.
                        array[j] = oldstr;    // Assigning the string at the previous position, stored in oldstr, into the present position.
                        oldstr = newstr;     // Now storing the string value that the present position previously had (now stored in newstr) in oldstr, since the assignment statements for positions in the array read from oldstr.
                    }
                }
            }
            return(amount);  // As amount number of shifts occured.
        }
        
        else
        {
            for(int i=0; i<size; i++)
            {
                array[i] = placeholder; // All elements of the array are replaced with placeholder if amount>size.
            }
            return(amount);  
        }
        
    }
    
    else if((size>0 && amount==0)||(size==0 && amount>0)||(size==0 && amount==0))
    {
        return(0); // If either of size and amount are zero while the other is positive, or both of them are zero, no shifts will be performed and hence we return zero.
    }
    
    else
    {
        return(-1); // Returning -1 as either one or both of size and amount were negative.
    }
    
}

// Defining find function

int find(const string array[], int size, string match)
{
    if(size>0)
    {
        int tracker = 0; // To keep track of the position within the array.
        bool found = false; // Assuming initially that the match hasn't been found.
        while(tracker<size)  // Looping through elements of the array.
        {
            if(array[tracker]==match)  // When a match is found.
            {
                found = true;  // As a match was found.
                break;  // Breaking out of the loop as soon as a match is found.
            }
            tracker++;
        }
        
        if(found)  // If a match was found.
        {
            return(tracker);  // Returns position at which match was found.
        }
        
        else
        {
            return(-1);      // Returning -1 as no matches were found.
        }
        
    }
    else
    {
        return(-1);   // Returning -1 as the size parameter was non-positive.
    }
}

// Defining replaceAllCharacters function

int replaceAllCharacters(string array[], int size, char findLetter, char replaceLetter)
{
    if(size>0)
    {
        int occur = 0; // To keep track of how many times matching characters are replaced.
        
        for(int i=0; i<size; i++)  // Looping through elements of the array.
        {
            for(int j=0; j<array[i].length();j++)  // Looping through individual string elements
            {
                char presentchar = array[i][j];
                if(presentchar==findLetter)
                {
                    occur+=1;  // Updating number of encountered matches
                    array[i][j]=replaceLetter;  // Replacing the character of the string with replaceLetter
                }
            }
        }
        
        return(occur);  // Returning the number of replace operations that were made
        
    }
    else
    {
        return(-1);  // Returning -1 as size was non-positive.
    }
}
