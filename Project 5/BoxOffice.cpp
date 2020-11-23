#include <iostream>
#include <string>
#include "Ticket.h"
#include "BoxOffice.h"
#include "Project5Helper.h"
using namespace std;

BoxOffice::BoxOffice()
{
    // Doesn't do anything other than creating an object of the BoxOffice class.
}

Ticket BoxOffice::buyTicket(string row, int seat, string event, string venue, Ticket::KIND kind, string daytime)
{
    // mprice is set to 0, the driver code can use the setPrice() function to alter its value.
    Ticket t(row, seat, event, venue, 0, kind, daytime);
    return(t);
}

// We don't test for bad input because the project specification doesn't demand us to do so. So, as far as the following three member methods are concerned, we assume that row can only begin with either Orchestra or Balcony, while daytime can only end with AM or PM.

Ticket BoxOffice::buyRoyceHallStudentTicket(string row, int seat, string event, Ticket::KIND kind, string daytime)
{
    double price = 0;
    
    Project5Helper phelp; // We create a dummy object of the Project5Helper class to be able to access its functions, since the startsWithOrchestra() and endsWithPM() methods don't belong to the string class, we can't directly call them on row.
    
    // Applying the pricing algorithm, first by KIND, then by AM/PM (if applicable), then Orchestra/ Balcony, and ultimately discount schemes (if any).
    
    // Pricing scheme for KIND ATHLETICGAME.
    if(kind == Ticket::KIND::ATHLETICGAME)
    {
        price = 75; // Base price independent of daytime ending in AM or PM.
        if(phelp.startsWithOrchestra(row))
        {
            price*=2; // Orchestra seats cost twice as much than Balcony seats.
        }
    }
    
    // Pricing scheme for KIND CONCERT.
    else if(kind == Ticket::KIND::CONCERT)
    {
        price = 50; // Base price if daytime ends with AM.
        if(phelp.endsWithPM(daytime))
        {
            price = 65; // Different base price if daytime ends with PM.
        }
        if(phelp.startsWithOrchestra(row))
        {
            price*=2; // Orchestra seats cost twice as much than Balcony seats.
        }
    }
    
    // Pricing scheme for KIND MOVIE.
    else if(kind == Ticket::KIND::MOVIE)
    {
        price = 12.5; // Base price is independent of AM or PM.
        if(phelp.startsWithOrchestra(row))
        {
            price*=2;  // Orchestra seats cost twice as much than Balcony seats.
        }
    }
    
    // Pricing scheme for KIND OTHER.
    else
    {
        price = 40; // Base price if daytime ends in AM.
        if(phelp.endsWithPM(daytime))
        {
            price = 55; // Different base price if daytime ends with PM.
        }
        if(phelp.startsWithOrchestra(row))
        {
            price*=2; // Orchestra seats cost twice as much than Balcony seats.
        }
    }
    
    // Discount scheme for students
    
    if(price>=40)
    {
        price-=30;
    }
    
    else
    {
        price*=0.8;
    }
    
    Ticket t(row, seat, event, "Royce Hall", price, kind, daytime); // mvenue initialized to "Royce Hall"
    return(t);
}

Ticket BoxOffice::buyRoyceHallStaffTicket(string row, int seat, string event, Ticket::KIND kind, string daytime)
{
    
    double price = 0;
    Project5Helper phelp; // Dummy object of Project5Helper class.
    
    // Applying the pricing algorithm, first by KIND, then by AM/PM (if applicable), then Orchestra/ Balcony, and ultimately discount schemes (if any).
    
    // Pricing scheme for KIND ATHLETICGAME.
    
    if(kind == Ticket::KIND::ATHLETICGAME)
    {
        price = 75; // Base price independent of daytime ending in AM or PM.
        if(phelp.startsWithOrchestra(row))
        {
            price*=2; // Orchestra seats cost twice as much than Balcony seats.
        }
    }
    
    // Pricing scheme for KIND CONCERT.
    
    else if(kind == Ticket::KIND::CONCERT)
    {
        price = 50; // Base price for AM.
        if(phelp.endsWithPM(daytime))
        {
            price = 65; // Update base price if daytime ends in PM.
        }
        if(phelp.startsWithOrchestra(row))
        {
            price*=2; // Orchestra seats cost twice as much than Balcony seats.
        }
    }
    
    // Pricing scheme for KIND MOVIE.
    
    else if(kind == Ticket::KIND::MOVIE)
    {
        price = 12.5;  // Base price independent of AM or PM.
        if(phelp.startsWithOrchestra(row))
        {
            price*=2; // Orchestra seats cost twice as much than Balcony seats.
        }
    }
    
    // Pricing scheme for KIND OTHER.
    
    else
    {
        price = 40; // Base price for AM.
        if(phelp.endsWithPM(daytime))
        {
            price = 55; // Base price for PM.
        }
        if(phelp.startsWithOrchestra(row))
        {
            price*=2; // Orchestra seats cost twice as much than Balcony seats.
        }
    }
    
    // Discount scheme for staff.
    
    if(price>=40)
    {
        price-=20;
    }
    
    else
    {
        price*=0.9;
    }
    
    Ticket t(row, seat, event, "Royce Hall", price, kind, daytime); // mvenue initialzied to "Royce Hall".
    return(t);
}

Ticket BoxOffice::buyRoyceHallTicket(string row, int seat, string event, Ticket::KIND kind, string daytime)
{
    
    double price = 0;
    Project5Helper phelp; // Project5Helper class's dummy object.
    
    // Applying the pricing algorithm, first by KIND, then by AM/PM (if applicable), then Orchestra/ Balcony, and ultimately discount schemes (if any).
    
    // Pricing scheme for KIND ATHLETICGAME.
    
    if(kind == Ticket::KIND::ATHLETICGAME)
    {
        price = 75; // Base price irrespective of AM or PM.
        if(phelp.startsWithOrchestra(row))
        {
            price*=2;  // Orchestra seats cost twice as much than Balcony seats.
        }
    }
    
    // Pricing scheme for KIND CONCERT.
    
    else if(kind == Ticket::KIND::CONCERT)
    {
        price = 50; // Base price for AM.
        if(phelp.endsWithPM(daytime))
        {
            price = 65; // Updated base price for PM.
        }
        if(phelp.startsWithOrchestra(row))
        {
            price*=2; // Orchestra seats cost twice as much than Balcony seats.
        }
    }
    
    // Pricing scheme for KIND MOVIE.
    
    else if(kind == Ticket::KIND::MOVIE)
    {
        price = 12.5; // Base price independent of AM or PM.
        if(phelp.startsWithOrchestra(row))
        {
            price*=2; // Orchestra seats cost twice as much than Balcony seats.
        }
    }
    
    // Pricing scheme for KIND OTHER.
    
    else
    {
        price = 40; // Base price for AM.
        if(phelp.endsWithPM(daytime))
        {
            price = 55; // Base price for PM.
        }
        if(phelp.startsWithOrchestra(row))
        {
            price*=2; // Orchestra seats cost twice as much than Balcony seats.
        }
    }
    
    // No discount schemes for regular customers.
    
    Ticket t(row, seat, event, "Royce Hall", price, kind, daytime); // mvenue initialized to "Royce Hall".
    return(t);
}

