#include <iostream>
#include <string>
using namespace std;

int number(string s, int & startingposition);
bool isValidRowerString(string rowerString);
int elapsedMinutes(string rowerString);
int elapsedSeconds(string rowerString);
int strokesPerMinute(string rowerString);
int totalDistance(string rowerString);
int heartRate(string rowerString);

int main()
{
    string s;
    cout.setf( ios::boolalpha ); // prints bool values as "true" or "false"
    for(;;)
    {
        cout << "Enter rower string: ";
        getline(cin, s);
        
        if (s == "quit")
            break;
        
        cout << "isValidRowerString returns ";
        cout << isValidRowerString(s) << endl;
        
        cout << "elapsedMinutes(s) returns ";
        cout << elapsedMinutes(s) << endl;
        
        cout << "elapsedSeconds(s) returns ";
        cout << elapsedSeconds(s) << endl;
        
        cout << "strokesPerMinute(s) returns ";
        cout << strokesPerMinute(s) << endl;
        
        cout << "totalDistance(s) returns ";
        cout << totalDistance(s) << endl;
        
        cout << "heartRate(s) returns ";
        cout << heartRate(s) << endl;
        
        
    }
    return 0;
}


// Defining the number function, the backbone of the isValidString function

int number(string s, int & startingposition) // Passing startingposition by reference allows us to keep track of the cursor every time we call this function
{
    int result = 0;
    
    while(startingposition<s.length() && s[startingposition]==' ')     // This loop eats up any leading spaces
    {
        startingposition+=1;
    }
    
    if(startingposition<s.length() && s[startingposition]>='1' && s[startingposition]<='9')  // Doesn't allow leading zeros
    {
        result+=s[startingposition]-'0';         // Conversion of an integer in character type to int type using ASCII table
        startingposition+=1;
        
        while(startingposition<s.length() && s[startingposition]>='0' && s[startingposition]<='9')
        {
            result=(result*10)+(s[startingposition]-'0');
            startingposition+=1;
        }
    }
    
    
    else
    {
        return(-1);
    }
    
    return(result);
}

// Defining the isValidString function, the backbone of other functions

bool isValidRowerString (string rowerString)
{
    int counter=0; // To keep track of the cursor's position
    int minutes = number(rowerString,counter);  // Will obtain the minutes value and will place the cursor at ':' character
    if((minutes>=1 && minutes<=59) || (minutes==-1 && rowerString[counter]==':'))  // The second condition corresponds to zero minutes
    {
        counter+=1; // To move beyond the ':' character
        
        int seconds;
        
        if(rowerString[counter]=='0' && (rowerString[counter+1]>='0' && rowerString[counter+1]<='9') && rowerString[counter+2]==' ')    // Handling seconds >= 0 and <= 9
        {
            counter+=1; // To move beyond the first '0' character in the seconds field
            seconds = rowerString[counter]-'0'; // Obtains the integer value of the seconds field
        }
        else
        {
            seconds = number(rowerString,counter); // If executed, obtains seconds and places the cursor just after the seconds field
        }
        
        if((seconds>=0 && seconds<=9 && rowerString[counter-1]=='0') || (seconds>=10 && seconds<=59)) // We have counter-1 in the first condition since we'll be at the second character of the seconds field shall the seconds lie in the range on 0 to 9
        {
            counter+=1; // The cursor will either be one (if the seconds lie between 0 and 9) or two (if the seconds lie between 10 and 59) positions after the seconds field
            
            int strokeRate = number(rowerString, counter); // Obtains the strokerate and places the cursor at the space between the the strokeRate value and "s/m" string
            
            if(strokeRate>=1 && strokeRate<=999 && rowerString[counter]==' ' && rowerString[counter+1]=='s' && rowerString[counter+2]=='/' && rowerString[counter+3]=='m') // Checking if the strokes field has been defined in an appropriate manner
            {
                counter+=4; // Places the cursor just after the character 'm' of "s/m" string belonging to the strokerate field
                int distance = number(rowerString,counter); //
        
                if(distance>=1 && rowerString[counter]==' ' && rowerString[counter+1]=='m') // Checking if the distance field is properly formed
                {
                    counter+=2; // Places the cursor right after the character 'm' of the distance field
                    
                    int heartRate = number(rowerString,counter); // Obtains heartrate and places cursor at the end of the string
                    
                    if(heartRate>=1 && heartRate<=999 && counter==rowerString.length()) // The second condition ensures that the rowerString ends exactly where the heartrate description ends
                    {
                        
                        return(true);  // After checking that all fields are properly formed, the rowerString is confirmed to be good
                    
                    }
                    
                    else
                    {
                        return(false); // Handles the case of a bad heartrate field in a rowerString
                        
                    }
                    
                
                }
                
                else
                {
                    return(false); // Handles a bad distance field
                }
            }
            
            else
            {
                return(false); // Handles a bad strokeRate
                
            }
            
            
        }
        
        else
        {
            return(false); // Handles a bad seconds field
        }
        
    }
    else
    {
        return(false); // Handles a bad minutes field
    }
}


// Defining the elapsedMinutes function.

int elapsedMinutes(string rowerString)
{
    if(isValidRowerString(rowerString))  // Goes ahead only for valid rowerStrings
    {
        int counter = 0; // To keep track of the cursor's position
        int minutes = number(rowerString,counter);
        
        if(minutes==-1) // Since we have already checked if the rowerString is a good one or not, we know that a -1 value for minutes corresponds to an empty minutes field, or zero minutes
        {
            return(0);
        }
        
        else
        {
            return(minutes);
        }
        
    }
    else
    {
        return(-1); // In case the rowerString is a bad one
    }
}

// Defining elapsedSeconds function.

int elapsedSeconds(string rowerString)
{
    if(isValidRowerString(rowerString))  // Goes ahead only for valid rowerStrings
    {
        int counter = 0;
        number(rowerString, counter); // Will make the cursor move beyond the minutes field, placing it at the ':'
        int seconds;
        
        counter+=1; // Moves the cursor right at the beginning of the seconds field
        
        if(rowerString[counter]=='0' && (rowerString[counter+1]>='0' && rowerString[counter+1]<='9')) // Handles seconds between 0 and 9
        {
            seconds = rowerString[counter+1]-'0';
            return(seconds);
        }
        else
        {
            seconds = number(rowerString,counter);
            return(seconds);
        }
        
    }
    
    else
    {
        return(-1);
    }
}

// Defining strokesPerMinute function.

int strokesPerMinute(string rowerString)
{
    if(isValidRowerString(rowerString))  // Goes ahead only for valid rowerStrings
    {
        int counter = 0;
        number(rowerString,counter); // Makes the cursor move beyond the minutes field, placing it at the ':' character
        int strokeRate;
        counter+=1; // Moves the cursor right into the seconds field
        
        if(rowerString[counter]=='0') // In case the seconds lie between 0 and 9
        {
            counter+=2; // Moves the cursor to the space just after the seconds field
            strokeRate = number(rowerString,counter);
            return(strokeRate);
        }
        
        else
        {
            number(rowerString,counter); // Moves the cursor to the space just after the seconds field
            strokeRate = number(rowerString,counter);
            return(strokeRate);
        }
        
    }
    
    else
    {
        return(-1);
    }
    
}

// Defining totalDistance function.

int totalDistance(string rowerString)
{
    if(isValidRowerString(rowerString))  // Goes ahead only for valid rowerStrings
    {
        int counter = 0;
        int distance;
        number(rowerString, counter); // Moves the cursor beyond the minutes field, places it at the ':' character
        
        counter+=1;
        
        if(rowerString[counter]=='0') // If seconds lie between 0 and 9
        {
            counter+=2; // Moves the cursor to the space just after the seconds field
            number(rowerString,counter); // Moves the cursor to the space between the strokeRate value and "s/m" string
            counter+=4; // Moves the cursor beyond the strokeRate field's 'm' character
            distance = number(rowerString,counter);
            return(distance);
        }
        
        else
        {
            number(rowerString,counter); // Moves the cursor to the space just after the seconds field
            number(rowerString,counter);  // Moves the cursor to the space between the strokeRate value and "s/m" string
            counter+=4; // Moves the cursor beyond the strokeRate field's 'm' character
            distance = number(rowerString,counter);
            return(distance);
        }
        
    }
    
    else
    {
        return(-1);
    }
}

// Defining heartRate function.

int heartRate (string rowerString)
{
    if(isValidRowerString(rowerString))  // Goes ahead only for valid rowerStrings
    {
        int counter = 0;
        int heartrate;
        number(rowerString,counter); // Moves the cursor beyond the minutes field, places it at the ':' character
        counter+=1;
        
        if(rowerString[counter]=='0') // Handles seconds lying between 0 and 9
        {
            counter+=2;  // Moves the cursor to the space just after the seconds field
            number(rowerString,counter); // Moves the cursor to the space between the strokeRate value and "s/m" string
            counter+=4;  // Moves the cursor beyond the strokeRate field's 'm' character
            number(rowerString,counter);  // Moves the cursor to the space between distance field's value and the 'm' character
            counter+=2; // Moves the cursor beyond distance field's 'm' character
            heartrate = number(rowerString,counter);
            return(heartrate);
            
        }
        
        else
        {
            number(rowerString,counter); // Moves the cursor to the space just after the seconds field
            number(rowerString,counter);  // Moves the cursor to the space between the strokeRate value and "s/m" string
            counter+=4;  // Moves the cursor beyond the strokeRate field's 'm' character
            number(rowerString,counter);  // Moves the cursor to the space between distance field's value and the 'm' character
            counter+=2; // Moves the cursor beyond distance field's 'm' character
            heartrate = number(rowerString,counter);
            return(heartrate);
            
        }
        
    }
    
    else
    {
        return(-1);
    }
    
}
