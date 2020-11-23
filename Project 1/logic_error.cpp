// Code for Project 1
// Congress results

#include <iostream>
using namespace std;   // pp. 37-38 in Savitch book explain this line

int main()
{
    int republicanSeats;
    int democraticSeats;
    int independentSeats;
    
    cout << "How many seats are held by Democrats? ";
    cin >> democraticSeats;
    cout << "How many seats are held by Republicans? ";
    cin >> republicanSeats;
    cout << "How many seats are held by Independents? ";
    cin >> independentSeats; 
    
    int total = republicanSeats + democraticSeats + independentSeats;
    
    double pctRep = 100.0 * republicanSeats / (total+7); //Incorrect formula, uses total+7 instead of total
    double pctDem = 50.0 * democraticSeats / total;      //Incorrect formula, multiplies by 50.0 instead of 100.0
    double pctInd = 100.0 * (independentSeats+19) / total; //Incorrect formula, uses independentSeats+19 instead of independentSeats
    
    cout.setf(ios::fixed);       // see pp. 30-31 in Savitch book
    cout.precision(1);
    cout << endl << endl;
    cout << pctRep << "% Republicans" << endl;
    cout << pctDem << "% Democrats" << endl;
    cout << pctInd  << "% Independents" << endl;
    
    if (pctRep < pctDem)      //Incorrect comparison, uses pctRep<pctDem instead of pctRep>pctDem
    {
        cout << "Looks like control goes to the Republicans." << endl;
        
    }
    else
    {
        cout << "Looks like control goes to the Democrats." << endl;
        
    }
    return(0);
    
}
