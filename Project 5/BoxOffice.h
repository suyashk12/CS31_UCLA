#include <iostream>
#include <string>
#include "Ticket.h"
#include "Project5Helper.h"
using namespace std;

#ifndef BOXOFFICE_HPP
#define BOXOFFICE_HPP

// The class BoxOffice is used to create objects of the Ticket class. This interaction between classes is called "Creational Pattern".

class BoxOffice
{
public:
    BoxOffice();  // Default constructor
    // All the public member functions below have a return type Ticket, meaning that they must return an object of the Ticket class.
    // buyTicket function initializes mprice to 0. The driver code can call .setPrice() function to alter the value of mprice for the returned object.
    Ticket buyTicket(string row, int seat, string event, string venue, Ticket::KIND kind, string daytime);
    // The following functions won't accept a venue parameter, and the value of the mvenue private member variable of the return object will be set to "Royce Hall". mprice will be decided according to the pricing algorithm.
    Ticket buyRoyceHallStudentTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);
    Ticket buyRoyceHallStaffTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);
    Ticket buyRoyceHallTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);
};

#endif
