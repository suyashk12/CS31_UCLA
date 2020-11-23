#include <iostream>
#include <string>
#include "Ticket.h"
using namespace std;

Ticket::Ticket(string row, int seat, string event, string venue, double price, KIND kind, string daytime)
{
    // Initializing private member variables of the created Ticket object with parameters given to the constructor.
    mRow = row;
    mSeat = seat;
    mEvent = event;
    mVenue = venue;
    mPrice = price;
    mKind = kind;
    mDayTime = daytime;
}

// Creating accessor functions.

string Ticket::getRow()
{
    return(mRow);
}

int Ticket::getSeat()
{
    return(mSeat);
}

string Ticket::getEvent()
{
    return(mEvent);
}

string Ticket::getVenue()
{
    return(mVenue);
}

double Ticket::getPrice()
{
    return(mPrice);
}

Ticket::KIND Ticket::getKind()
{
    return(mKind);
}

string Ticket::getDayTime()
{
    return(mDayTime);
}

// Creating mutator function.

void Ticket::setPrice(double price)
{
    mPrice = price;
}
