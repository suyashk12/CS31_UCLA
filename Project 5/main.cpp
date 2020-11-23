#include <iostream>
#include <string>
#include <cassert>

#include "Ticket.h"
#include "BoxOffice.h"

using namespace std;

int main()
{
    
    BoxOffice b;
    
    // buyTicket() test cases.
    
    Ticket t = b.buyTicket("Pavillion Row 13", 45, "Dodgers vs. Brewers", "Dodger Stadium", Ticket::KIND::ATHLETICGAME, "August 1, 7:30PM" );
    t.setPrice(150);
    assert( std::to_string( t.getPrice() ) == "150.000000" );
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME );
    assert( t.getRow() == "Pavillion Row 13" );
    assert( t.getSeat() == 45 );
    assert( t.getVenue() == "Dodger Stadium" );
    assert( t.getEvent() == "Dodgers vs. Brewers" );
    assert( t.getDayTime() == "August 1, 7:30PM" );
    
    t = b.buyTicket("Pauley Row 15", 32, "Dodgers vs. Brewers", "Pauley Pavillion", Ticket::KIND::MOVIE, "September 3, 9:30PM" );
    t.setPrice(300);
    assert( std::to_string( t.getPrice() ) == "300.000000" );
    assert( t.getKind() == Ticket::KIND::MOVIE);
    assert( t.getRow() == "Pauley Row 15" );
    assert( t.getSeat() == 32 );
    assert( t.getVenue() == "Pauley Pavillion" );
    assert( t.getEvent() == "Dodgers vs. Brewers" );
    assert( t.getDayTime() == "September 3, 9:30PM" );

    // ATHLETICGAME Orchestra seats (Student/ Staff/ Regular).
    
    t = b.buyRoyceHallStudentTicket("Orchestra Row 10", 15, "Basketball", Ticket::KIND::ATHLETICGAME, "January 10, 7:30AM");
    assert( std::to_string( t.getPrice() ) == "120.000000" );
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME);
    assert( t.getRow() == "Orchestra Row 10" );
    assert( t.getSeat() == 15 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Basketball" );
    assert( t.getDayTime() == "January 10, 7:30AM" );
    
    t = b.buyRoyceHallStaffTicket("Orchestra Row 10", 15, "Basketball", Ticket::KIND::ATHLETICGAME, "January 10, 7:30AM");
    assert( std::to_string( t.getPrice() ) == "130.000000" );
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME);
    assert( t.getRow() == "Orchestra Row 10" );
    assert( t.getSeat() == 15 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Basketball" );
    assert( t.getDayTime() == "January 10, 7:30AM" );
    
    t = b.buyRoyceHallTicket("Orchestra Row 10", 15, "Basketball", Ticket::KIND::ATHLETICGAME, "January 10, 7:30AM");
    assert( std::to_string( t.getPrice() ) == "150.000000" );
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME);
    assert( t.getRow() == "Orchestra Row 10" );
    assert( t.getSeat() == 15 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Basketball" );
    assert( t.getDayTime() == "January 10, 7:30AM" );
    
    // ATHLETICGAME Balcony seats (Student/ Staff/ Regular).
    
    t = b.buyRoyceHallStudentTicket("Balcony Row 10", 15, "Basketball", Ticket::KIND::ATHLETICGAME, "January 10, 7:30PM");
    assert( std::to_string( t.getPrice() ) == "45.000000" );
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME);
    assert( t.getRow() == "Balcony Row 10" );
    assert( t.getSeat() == 15 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Basketball" );
    assert( t.getDayTime() == "January 10, 7:30PM" );
    
    t = b.buyRoyceHallStaffTicket("Balcony Row 10", 15, "Basketball", Ticket::KIND::ATHLETICGAME, "January 10, 7:30PM");
    assert( std::to_string( t.getPrice() ) == "55.000000" );
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME);
    assert( t.getRow() == "Balcony Row 10" );
    assert( t.getSeat() == 15 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Basketball" );
    assert( t.getDayTime() == "January 10, 7:30PM" );
    
    t = b.buyRoyceHallTicket("Balcony Row 10", 15, "Basketball", Ticket::KIND::ATHLETICGAME, "January 10, 7:30PM");
    assert( std::to_string( t.getPrice() ) == "75.000000" );
    assert( t.getKind() == Ticket::KIND::ATHLETICGAME);
    assert( t.getRow() == "Balcony Row 10" );
    assert( t.getSeat() == 15 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Basketball" );
    assert( t.getDayTime() == "January 10, 7:30PM" );
    
    // MOVIE Orchestra seats (Student/ Staff/ Regular).
    
    t = b.buyRoyceHallStudentTicket("Orchestra Row 15", 40, "Sherlock", Ticket::KIND::MOVIE, "November 15, 9:50AM");
    assert( std::to_string( t.getPrice() ) == "20.000000" );
    assert( t.getKind() == Ticket::KIND::MOVIE);
    assert( t.getRow() == "Orchestra Row 15" );
    assert( t.getSeat() == 40 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Sherlock" );
    assert( t.getDayTime() == "November 15, 9:50AM" );
    
    t = b.buyRoyceHallStaffTicket("Orchestra Row 15", 40, "Sherlock", Ticket::KIND::MOVIE, "November 15, 9:50AM");
    assert( std::to_string( t.getPrice() ) == "22.500000" );
    assert( t.getKind() == Ticket::KIND::MOVIE);
    assert( t.getRow() == "Orchestra Row 15" );
    assert( t.getSeat() == 40 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Sherlock" );
    assert( t.getDayTime() == "November 15, 9:50AM" );
    
    t = b.buyRoyceHallTicket("Orchestra Row 15", 40, "Sherlock", Ticket::KIND::MOVIE, "November 15, 9:50AM");
    assert( std::to_string( t.getPrice() ) == "25.000000" );
    assert( t.getKind() == Ticket::KIND::MOVIE);
    assert( t.getRow() == "Orchestra Row 15" );
    assert( t.getSeat() == 40 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Sherlock" );
    assert( t.getDayTime() == "November 15, 9:50AM" );
    
    // MOVIE Balcony seats (Student/ Staff/ Regular).
    
    t = b.buyRoyceHallStudentTicket("Balcony Row 20", 40, "Sherlock", Ticket::KIND::MOVIE, "November 15, 9:50PM");
    assert( std::to_string( t.getPrice() ) == "10.000000" );
    assert( t.getKind() == Ticket::KIND::MOVIE);
    assert( t.getRow() == "Balcony Row 20" );
    assert( t.getSeat() == 40 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Sherlock" );
    assert( t.getDayTime() == "November 15, 9:50PM" );
    
    t = b.buyRoyceHallStaffTicket("Balcony Row 20", 40, "Sherlock", Ticket::KIND::MOVIE, "November 15, 9:50PM");
    assert( std::to_string( t.getPrice() ) == "11.250000" );
    assert( t.getKind() == Ticket::KIND::MOVIE);
    assert( t.getRow() == "Balcony Row 20" );
    assert( t.getSeat() == 40 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Sherlock" );
    assert( t.getDayTime() == "November 15, 9:50PM" );
    
    t = b.buyRoyceHallTicket("Balcony Row 20", 40, "Sherlock", Ticket::KIND::MOVIE, "November 15, 9:50PM");
    assert( std::to_string( t.getPrice() ) == "12.500000" );
    assert( t.getKind() == Ticket::KIND::MOVIE);
    assert( t.getRow() == "Balcony Row 20" );
    assert( t.getSeat() == 40 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Sherlock" );
    assert( t.getDayTime() == "November 15, 9:50PM" );
    
    // CONCERT AM Orchestra seats (Student/ Staff/ Regular).
    
    t = b.buyRoyceHallStudentTicket("Orchestra Row 32", 45, "Mozart", Ticket::KIND::CONCERT, "July 20, 10:50AM");
    assert( std::to_string( t.getPrice() ) == "70.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT);
    assert( t.getRow() == "Orchestra Row 32" );
    assert( t.getSeat() == 45 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Mozart" );
    assert( t.getDayTime() == "July 20, 10:50AM" );
    
    t = b.buyRoyceHallStaffTicket("Orchestra Row 32", 45, "Mozart", Ticket::KIND::CONCERT, "July 20, 10:50AM");
    assert( std::to_string( t.getPrice() ) == "80.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT);
    assert( t.getRow() == "Orchestra Row 32" );
    assert( t.getSeat() == 45 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Mozart" );
    assert( t.getDayTime() == "July 20, 10:50AM" );
    
    t = b.buyRoyceHallTicket("Orchestra Row 32", 45, "Mozart", Ticket::KIND::CONCERT, "July 20, 10:50AM");
    assert( std::to_string( t.getPrice() ) == "100.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT);
    assert( t.getRow() == "Orchestra Row 32" );
    assert( t.getSeat() == 45 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Mozart" );
    assert( t.getDayTime() == "July 20, 10:50AM" );
    
    // CONCERT PM Orchestra seats (Student/ Staff/ Regular).
    
    t = b.buyRoyceHallStudentTicket("Orchestra Row 35", 45, "Mozart", Ticket::KIND::CONCERT, "June 21, 10:50PM");
    assert( std::to_string( t.getPrice() ) == "100.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT);
    assert( t.getRow() == "Orchestra Row 35" );
    assert( t.getSeat() == 45 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Mozart" );
    assert( t.getDayTime() == "June 21, 10:50PM" );
    
    t = b.buyRoyceHallStaffTicket("Orchestra Row 35", 45, "Mozart", Ticket::KIND::CONCERT, "June 21, 10:50PM");
    assert( std::to_string( t.getPrice() ) == "110.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT);
    assert( t.getRow() == "Orchestra Row 35" );
    assert( t.getSeat() == 45 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Mozart" );
    assert( t.getDayTime() == "June 21, 10:50PM" );
    
    t = b.buyRoyceHallTicket("Orchestra Row 35", 45, "Mozart", Ticket::KIND::CONCERT, "June 21, 10:50PM");
    assert( std::to_string( t.getPrice() ) == "130.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT);
    assert( t.getRow() == "Orchestra Row 35" );
    assert( t.getSeat() == 45 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Mozart" );
    assert( t.getDayTime() == "June 21, 10:50PM" );
    
    // CONCERT AM Balcony seats (Student/ Staff/ Regular)
    
    t = b.buyRoyceHallStudentTicket("Balcony Row 40", 20, "Mozart", Ticket::KIND::CONCERT, "February 20, 10:30AM");
    assert( std::to_string( t.getPrice() ) == "20.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT);
    assert( t.getRow() == "Balcony Row 40" );
    assert( t.getSeat() == 20 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Mozart" );
    assert( t.getDayTime() == "February 20, 10:30AM" );
    
    t = b.buyRoyceHallStaffTicket("Balcony Row 40", 20, "Mozart", Ticket::KIND::CONCERT, "February 20, 10:30AM");
    assert( std::to_string( t.getPrice() ) == "30.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT);
    assert( t.getRow() == "Balcony Row 40" );
    assert( t.getSeat() == 20 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Mozart" );
    assert( t.getDayTime() == "February 20, 10:30AM" );
    
    t = b.buyRoyceHallTicket("Balcony Row 40", 20, "Mozart", Ticket::KIND::CONCERT, "February 20, 10:30AM");
    assert( std::to_string( t.getPrice() ) == "50.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT);
    assert( t.getRow() == "Balcony Row 40" );
    assert( t.getSeat() == 20 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Mozart" );
    assert( t.getDayTime() == "February 20, 10:30AM" );
    
    // CONCERT PM Balcony seats (Student/ Staff/ Regular).
    
    t = b.buyRoyceHallStudentTicket("Balcony Row 30", 35, "Mozart", Ticket::KIND::CONCERT, "January 19, 8:00PM");
    assert( std::to_string( t.getPrice() ) == "35.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT);
    assert( t.getRow() == "Balcony Row 30" );
    assert( t.getSeat() == 35 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Mozart" );
    assert( t.getDayTime() == "January 19, 8:00PM" );
    
    t = b.buyRoyceHallStaffTicket("Balcony Row 30", 35, "Mozart", Ticket::KIND::CONCERT, "January 19, 8:00PM");
    assert( std::to_string( t.getPrice() ) == "45.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT);
    assert( t.getRow() == "Balcony Row 30" );
    assert( t.getSeat() == 35 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Mozart" );
    assert( t.getDayTime() == "January 19, 8:00PM" );
    
    t = b.buyRoyceHallTicket("Balcony Row 30", 35, "Mozart", Ticket::KIND::CONCERT, "January 19, 8:00PM");
    assert( std::to_string( t.getPrice() ) == "65.000000" );
    assert( t.getKind() == Ticket::KIND::CONCERT);
    assert( t.getRow() == "Balcony Row 30" );
    assert( t.getSeat() == 35 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Mozart" );
    assert( t.getDayTime() == "January 19, 8:00PM" );
    
    // OTHER AM Orchestra seats (Student/ Staff/ Regular).
    
    t = b.buyRoyceHallStudentTicket("Orchestra Row 65", 100, "Batman", Ticket::KIND::OTHER, "August 15, 11:50AM");
    assert( std::to_string( t.getPrice() ) == "50.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER);
    assert( t.getRow() == "Orchestra Row 65" );
    assert( t.getSeat() == 100 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Batman" );
    assert( t.getDayTime() == "August 15, 11:50AM" );
    
    t = b.buyRoyceHallStaffTicket("Orchestra Row 32", 100, "Batman", Ticket::KIND::OTHER, "August 15, 11:50AM");
    assert( std::to_string( t.getPrice() ) == "60.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER);
    assert( t.getRow() == "Orchestra Row 32" );
    assert( t.getSeat() == 100 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Batman" );
    assert( t.getDayTime() == "August 15, 11:50AM" );
    
    t = b.buyRoyceHallTicket("Orchestra Row 65", 100, "Batman", Ticket::KIND::OTHER, "August 15, 11:50AM");
    assert( std::to_string( t.getPrice() ) == "80.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER);
    assert( t.getRow() == "Orchestra Row 65" );
    assert( t.getSeat() == 100 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Batman" );
    assert( t.getDayTime() == "August 15, 11:50AM" );
    
    // OTHER PM Orchestra seats (Student/ Staff/ Regular).
    
    t = b.buyRoyceHallStudentTicket("Orchestra Row 85", 85, "Batman", Ticket::KIND::OTHER, "May 19, 7:50PM");
    assert( std::to_string( t.getPrice() ) == "80.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER);
    assert( t.getRow() == "Orchestra Row 85" );
    assert( t.getSeat() == 85 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Batman" );
    assert( t.getDayTime() == "May 19, 7:50PM" );
    
    t = b.buyRoyceHallStaffTicket("Orchestra Row 85", 85, "Batman", Ticket::KIND::OTHER, "May 19, 7:50PM");
    assert( std::to_string( t.getPrice() ) == "90.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER);
    assert( t.getRow() == "Orchestra Row 85" );
    assert( t.getSeat() == 85 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Batman" );
    assert( t.getDayTime() == "May 19, 7:50PM" );
    
    t = b.buyRoyceHallTicket("Orchestra Row 85", 85, "Batman", Ticket::KIND::OTHER, "May 19, 7:50PM");
    assert( std::to_string( t.getPrice() ) == "110.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER);
    assert( t.getRow() == "Orchestra Row 85" );
    assert( t.getSeat() == 85 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Batman" );
    assert( t.getDayTime() == "May 19, 7:50PM" );
    
    // OTHER AM Balcony seats (Student/ Staff/ Regular).
    
    t = b.buyRoyceHallStudentTicket("Balcony Row 72", 35, "Batman", Ticket::KIND::OTHER, "September 19, 9:45AM");
    assert( std::to_string( t.getPrice() ) == "10.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER);
    assert( t.getRow() == "Balcony Row 72" );
    assert( t.getSeat() == 35 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Batman" );
    assert( t.getDayTime() == "September 19, 9:45AM" );
    
    t = b.buyRoyceHallStaffTicket("Balcony Row 72", 35, "Batman", Ticket::KIND::OTHER, "September 19, 9:45AM");
    assert( std::to_string( t.getPrice() ) == "20.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER);
    assert( t.getRow() == "Balcony Row 72" );
    assert( t.getSeat() == 35 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Batman" );
    assert( t.getDayTime() == "September 19, 9:45AM" );
    
    t = b.buyRoyceHallTicket("Balcony Row 72", 35, "Batman", Ticket::KIND::OTHER, "September 19, 9:45AM");
    assert( std::to_string( t.getPrice() ) == "40.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER);
    assert( t.getRow() == "Balcony Row 72" );
    assert( t.getSeat() == 35 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Batman" );
    assert( t.getDayTime() == "September 19, 9:45AM" );
    
    // OTHER PM Balcony seats (Student/ Staff/ Regular).
    
    t = b.buyRoyceHallStudentTicket("Balcony Row 30", 25, "Batman", Ticket::KIND::OTHER, "December 20, 8:30PM");
    assert( std::to_string( t.getPrice() ) == "25.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER);
    assert( t.getRow() == "Balcony Row 30" );
    assert( t.getSeat() == 25 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Batman" );
    assert( t.getDayTime() == "December 20, 8:30PM" );
    
    t = b.buyRoyceHallStaffTicket("Balcony Row 30", 25, "Batman", Ticket::KIND::OTHER, "December 20, 8:30PM");
    assert( std::to_string( t.getPrice() ) == "35.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER);
    assert( t.getRow() == "Balcony Row 30" );
    assert( t.getSeat() == 25 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Batman" );
    assert( t.getDayTime() == "December 20, 8:30PM" );
    
    t = b.buyRoyceHallTicket("Balcony Row 30", 25, "Batman", Ticket::KIND::OTHER, "December 20, 8:30PM");
    assert( std::to_string( t.getPrice() ) == "55.000000" );
    assert( t.getKind() == Ticket::KIND::OTHER);
    assert( t.getRow() == "Balcony Row 30" );
    assert( t.getSeat() == 25 );
    assert( t.getVenue() == "Royce Hall" );
    assert( t.getEvent() == "Batman" );
    assert( t.getDayTime() == "December 20, 8:30PM" );

    cout << "all tests passed!" << endl ;
    
    return 0;
    
    }
