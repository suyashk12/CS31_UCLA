//This is the program for calculating prices for eating a meal at UCLA. The prices can vary depending upon what payment method you choose, what meal of the day you want to eat, whether you are a Staff or a resident/non-resident student.

#include <iostream>
#include <string>           //It is a good idea to import the string library because we are working mostly with strings.
using namespace std;

int main()
{
    string kind; //This is the payment method, which can take either Ticket or BruinCard.
    string meal; //This is the meal type, which can either be Breakfast, Lunch, or Dinner.
    string type; //This is the customer type, which can either be Staff, or Student
    string resident; //This checks whether the student is a resident or not.
    double price = 0; //This will store the meal price.
    
    cout.setf(ios::showpoint); //These three lines will ensure representation in decimal form upto two places.
    cout.setf(ios::fixed);
    cout.precision(2);
    
    cout<<"Ticket or BruinCard? ";
    getline(cin, kind);  //It is better to use getline instead of cin to handle string inputs.
    
    if(kind!="Ticket" && kind!="BruinCard") //Handles bad inputs for kind variable, which are NOT Ticket AND NOT BruinCard.
    {
        cout<<"The kind value must either be Ticket or BruinCard."<<endl;
        return(0); //Program will exit here and not ask for further input.
    }
    
    cout<<"Breakfast, Lunch or Dinner? ";
    getline(cin, meal);
    
    if(meal!="Breakfast" && meal!="Lunch" && meal!="Dinner") //Handles bad input for meal variable, which are NOT Breakfast AND NOT Lunch AND NOT Dinner.
    {
        cout<<"The meal value must either be Breakfast, Lunch or Dinner."<<endl;
        return(0); //Program will exit here and not ask for further input.
    }
    
    if(kind=="Ticket") //Handling the case of good inputs for kind variable.
    {
        if(meal=="Breakfast") //Use of nested if-else if to further test good inputs for meal variable.
        {
            price=12.5;
        }
        else if(meal=="Lunch")
        {
            price=14.5;
        }
        else if(meal=="Dinner")
        {
            price=17;
        }
    }
    
    else if (kind=="BruinCard"){
        
        cout<<"Student or Staff? ";
        getline(cin, type);
        
        //We use nested if-else if to further handle inputs for type variable.
        
        if(type!="Student" && type!="Staff") // Bad input for type variable would be NOT Student AND NOT Staff.
        {
            cout<<"The type value must either be Student or Staff."<<endl;
            return(0); //Program will exit here and not ask for further input.
        }
        
        else if (type == "Staff")  //Code for handling good input for type variable.
        {
            if(meal=="Breakfast")  //Further handling good values for meal variable using nested if-else if.
            {
                price=11.25;
            }
            else if(meal=="Lunch")
            {
                price=12.75;
            }
            else if(meal=="Dinner")
            {
                price=14.75;
            }
        }
        
        else if (type == "Student")
        {
            cout<<"Resident? ";
            getline(cin, resident);
            
            if(resident!="Yes" && resident!="No") //Handles bad input for resident variable, which would be NOT Yes AND NOT No.
            {
                cout<<"The resident value must either be Yes or No."<<endl;
                return(0); //Program will exit here and not ask for further input.
            }
            
            else if(resident == "Yes")  //Handling good inputs for resident variable.
            {
                if(meal=="Breakfast")  //Further handling good inputs for meal variable.
                {
                    price=9.75;
                }
                else if(meal=="Lunch")
                {
                    price=11.25;
                }
                else if(meal=="Dinner")
                {
                    price=12.25;
                }
            }
            
            else if(resident == "No")
            {
                if(meal=="Breakfast")
                {
                    price=10;
                }
                else if(meal=="Lunch")
                {
                    price=11.75;
                }
                else if(meal=="Dinner")
                {
                    price=12.75;
                }
            }
        }
    }
    
    cout<<"Thank you for eating at UCLA today.  Your meal cost is "<<"$"<<price<<"."<<endl; //Prints a success statement only after verifying that all variables received good inputs.
    
    return(0);
}
