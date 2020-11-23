//
//  main.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "Die.h"
#include "Player.h"
#include "Pig.h"


void clearScreen( );
bool handleComputerPlay( cs31::Pig & game );
void display( cs31::Pig & game, std::string message="", bool checkForGameOver=false );


int main()
{
    using namespace cs31;
    using namespace std;
    
    // test code starts
    
    // test code for Die class
    
    Die d;
    
    for (int i = 1; i <= 100; i++ )
    {
        d.roll();
        int value = d.getValue();
        assert( value >=1 && value <= 6 ); // getValue() must return something between 1 and 6, both inclusive.
    }

    // test code for Player class
    
    Player p;
    
    // ensuring that mScore and mTotal are initialized to 0
    assert(p.getScore( ) == 0 );
    assert(p.getTotal( ) == 0 );
    
    // mScore is updated everytime the roll() function is called, except when roll() returns 1. mTotal isn't updated until endTurn() function is called.
    assert( p.roll( 6 ) == 6 );
    assert( p.getScore() == 6 );
    assert( p.roll( 5 )  == 5 );
    assert( p.getScore() == 11 );
    
    // after endTurn() function is called, mTotal should be updated and mScore should be set to 0.
    
    p.endTurn();
    assert( p.getScore() == 0 );
    assert( p.getTotal() == 11 );
    
    // as we call roll() function again after calling endTurn(), mScore begins getting updated from 0.
    
    assert( p.roll( 4 )  == 4 );
    assert( p.getScore() == 4 );
    assert( p.roll( 5 ) == 5 );
    assert( p.getScore() == 9 );
    assert( p.roll( 6 )  == 6 );
    assert( p.getScore() == 15 );
    
    // again, when endTurn() is called, mTotal is updated from its previous value, and mScore is set to 0.
    p.endTurn();
    assert( p.getScore() == 0 );
    assert( p.getTotal() == 26 );
    
    // when we call roll(), mScore starts getting updated from 0 again.
    assert( p.roll( 4 ) == 4 );
    assert( p.getScore() == 4 );
    assert( p.roll( 5 ) == 5 );
    assert( p.getScore() == 9 );
    
    // as soon as roll() function returns 1, mScore is set to 0 and no changes are made to mTotal. This is like endTurn() with no changes to mTotal.
    assert( p.roll( 1 ) == 1 );
    assert( p.getScore() == 0 );
    assert( p.getTotal() == 26 );
    
    // test code for Board class
    
    Board board; // using board object to test all legal operations.
    
    // ensuring that all the member variables related to Board class are appropriately initialized.
    assert( board.getComputerTotal() == 0 );
    assert( board.getHumanTotal() == 0);
    assert( board.getRolledValue() == 0);
    assert( board.getComputerScore() == 0 );
    assert( board.getHumanScore() == 0);
    assert( board.isHumanWinner() == false );
    assert( board.isHumanTurn() == true );  // first turn must always go to the human.
    assert( board.isGameOver() == false );
    
    // one can make changes to mComputerScore and mComputerTotal only if mIsHumanTurn is false.
    board.setComputerTurn(); // sets mHumanTurn to false.
    board.setComputerTotal(1);
    board.setComputerScore(2);
    
    // similarly, changes to mHumanScore and mHumanTotal are allowed only if mHumanTurn is true.
    board.setHumanTurn(); // sets mHumanTurn to true.
    board.setHumanScore(3);
    board.setHumanTotal(4);
    board.setRolledValue(7);
    
    // using asserts on accessor functions for testing whether mutator functions appropriately changed member variables.
    assert( board.getComputerTotal() == 1 );
    assert( board.getHumanTotal() == 4);
    assert( board.getRolledValue() == 7);
    assert( board.getComputerScore() == 2 );
    assert( board.getHumanScore() == 3);
    assert( board.isHumanWinner() == false );
    assert( board.isHumanTurn() == true );
    assert( board.isGameOver() == false );
    
    Board b1; // using object b1 to ensure that Board class can handle all kinds of illegal operations.
    
    // legally setting mComputerTotal and mComputerScore to some values before attempting to alter them illegally
    
    b1.setComputerTurn();
    b1.setComputerTotal(21);
    b1.setComputerScore(22);
    
    // computer trying to make changes in a human turn
    
    b1.setHumanTurn();
    b1.setComputerTotal( 50 );
    b1.setComputerScore( 50 );
    assert( b1.getComputerTotal() == 21 ); // no changes were made to mComputerTotal
    assert( b1.getComputerScore() == 22 ); // no changes were made to mComputerScore
    
    // legally setting mHumanTotal and mHumanScore (since mIsHumanTurn is already true) before attempting to alter them illegally
    b1.setHumanScore(23);
    b1.setHumanTotal(30);
    b1.markHumanAsWinner();
    
    // human trying to make changes in a computer turn
    
    b1.setComputerTurn();
    b1.setHumanScore(100);
    b1.setHumanTotal(150);
    
    assert( b1.getHumanScore() == 23 );
    assert( b1.getHumanTotal() == 30 );
    
    // computer trying to make changes after game is over
    b1.setGameOver(true);
    b1.setComputerTurn();
    b1.setComputerScore(10000);
    b1.setComputerTotal(15000);
    
    assert( b1.getComputerTotal() == 21 ); // no changes were made to mComputerTotal
    assert( b1.getComputerScore() == 22 ); // no changes were made to mComputerScore
    assert( b1.isHumanWinner() == true ); // human still remains the winner
    
    // human trying to make changes after game is over, to no avail.
    b1.setHumanTurn();
    b1.setHumanScore(10);
    b1.setHumanTotal(20);
    
    assert( b1.getHumanScore() == 23 );
    assert( b1.getHumanTotal() == 30 );
    
    // test code for Pig class
    
    // simulating first game
    
    Pig game1;
    assert( game1.isGameOver() == false ); // game has not yet started
    assert( game1.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER );
    
    // setting human's turn and playing.
    game1.humanPlay( 5 );
    game1.humanEndTurn( );
    // human played 5 and ended turn, human's total is 5.
    
    // setting computer's turn and playing.
    game1.computerPlay( 5 );
    game1.computerEndTurn( );
    // computer played 5 and ended turn, computer's total is 5.
    
    assert( game1.isGameOver() == false ); // game still in progress.
    assert( game1.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER );
    
    // setting human's turn and playing 15.
    game1.humanPlay( 5 );
    game1.humanPlay( 5 );
    game1.humanPlay( 5 );
    game1.humanEndTurn( );
    // human played 15 and ended turn, human's total is 20.
    
    assert( game1.isGameOver() == false ); // game still in progress.
    assert( game1.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER );
    
    // setting computer's turn and rolling 15.
    game1.computerPlay( 5 );
    game1.computerPlay( 5 );
    game1.computerPlay( 5 );
    game1.computerEndTurn();
    // computer played 15 and ended turn, computer's total is 20.
    
    assert( game1.isGameOver() == false ); // game still in progress.
    assert( game1.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER );
    
    // setting human turn and playing 11.
    game1.humanPlay( 5 );
    game1.humanPlay( 6 );
    game1.humanEndTurn( );
    // human played 11 and ended turn, human's total is 31. Game must end now and human must be declared winner.
    
    assert( game1.isGameOver() == true ); // game has now ended.
    assert( game1.determineGameOutcome() == Pig::GAMEOUTCOME::HUMANWONGAME ); // human is the winner.
    
    // once the game is over, scores can't be changed
    game1.computerPlay( 6 );
    game1.computerPlay( 6 );
    game1.computerPlay( 6 );
    game1.computerEndTurn( );
    assert( game1.isGameOver() == true ); // the game is still over.
    assert( game1.determineGameOutcome() == Pig::GAMEOUTCOME::HUMANWONGAME ); // the human is still the winner.
    
    // simulating second game
    
    Pig game2;
    
    assert( game2.isGameOver() == false ); // game has not yet started
    assert( game2.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER );
    
    // setting human's turn and playing.
    game2.humanPlay( 53 ); // we should accept whatever value is coerced, legal or not.
    game2.humanEndTurn( );
    // human played 53 and ended turn, human's total is 53. Game must end now and human must be declared winner.
    
    assert( game2.isGameOver() == true ); // game has now ended.
    assert( game2.determineGameOutcome() == Pig::GAMEOUTCOME::HUMANWONGAME ); // human is the winner.
    
    // simulating third game
    
    Pig game3;
    
    assert( game3.isGameOver() == false ); // game has not yet started
    assert( game3.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER );
    
    // human starts playing and rolls a score of 16.
    game3.humanPlay(5);
    game3.humanPlay(6);
    game3.humanPlay(5);
    game3.humanEndTurn();
    // human ends turn and updates total to 16.
    
    // computer starts playing and rolls a score of 12.
    game3.computerPlay(5);
    game3.computerPlay(5);
    game3.computerPlay(2);
    game3.computerEndTurn();
    // computer ends turn and updates total to 12.
    
    // human starts playing and ends up rolling 1.
    game3.humanPlay(3);
    game3.humanPlay(1);
    game3.humanEndTurn();
    // due to rolling 1, human's score is dropped to 0, and total stays 16.
    
    // computer starts playing and rolls a score of 20.
    game3.computerPlay(5);
    game3.computerPlay(5);
    game3.computerPlay(5);
    game3.computerPlay(5);
    game3.computerEndTurn();
    // computer ends turn and updates total to 32 and wins.
    
    assert( game3.isGameOver() == true ); // game has now ended.
    assert( game3.determineGameOutcome() == Pig::GAMEOUTCOME::COMPUTERWONGAME ); // computer is the winner.
    
    // simulating fourth game
    
    Pig game4;
    
    assert( game4.isGameOver() == false ); // game has not yet started
    assert( game4.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER );
    
    // computer starts playing and rolls a score of 5. Computer starts playing here first, for the sake of uniqueness.
    game4.computerPlay(2);
    game4.computerPlay(5);
    game4.computerEndTurn();
    // computer ends turn and updates total to 5.
    
    // human starts playing and rolls a score of 10.
    game4.humanPlay(2);
    game4.humanPlay(3);
    game4.humanPlay(5);
    game4.humanEndTurn();
    // human ends turn and updates total to 10.
    
    // although it is illegal, human plays again and rolls a score of 3.
    game4.humanPlay(3);
    game4.humanEndTurn();
    // human ends turn and updates total to 13.
    
    // computer plays and rolls a score of 15 in one go, although it is illegal.
    game4.computerPlay(15);
    game4.computerEndTurn();
    // computer ends turn and updates total to 20.
    
    // human plays and ends up rolling a 1.
    game4.humanPlay(6);
    game4.humanPlay(4);
    game4.humanPlay(1);
    game4.humanEndTurn();
    // due to rolling 1, human's score is dropped to 0 and total remains 13.
    
    // computer plays and rolls a 15 and wins.
    game4.computerPlay(5);
    game4.computerPlay(5);
    game4.computerPlay(5);
    game4.computerEndTurn();
    // computer ends turn and updates total to 35 and wins.
    
    assert( game4.isGameOver() == true ); // game has now ended.
    assert( game4.determineGameOutcome() == Pig::GAMEOUTCOME::COMPUTERWONGAME ); // computer is the winner.
    
    // although the human tries to update their total, that doesn't happen since the game has ended.
    game4.humanPlay(6);
    game4.humanPlay(6);
    game4.humanPlay(6);
    game4.humanEndTurn();
    
    assert( game4.isGameOver() == true ); // the game is still over.
    assert( game4.determineGameOutcome() == Pig::GAMEOUTCOME::COMPUTERWONGAME ); // computer is still the winner.

    cout << "all tests passed!" << endl;
    
    // test code ends

    
    clearScreen();
    
    Pig game;
    int human;
    std::string action, message = "(r)oll (e)ndturn (q)uit: ";
    display( game, message, false );

    
    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                return 0;
            case 'r':
            case 'R':
                human = game.humanPlay();
                cout << "human rolled:" << human << endl;
                if (human == 1)
                {
                    game.humanEndTurn();
                    display( game );
                    do
                    {
                        if (handleComputerPlay( game ))
                            break;
                    } while (game.computerKeepRolling());
                    game.computerEndTurn();
                    display( game, message, true );
                }
                break;
            case 'e':
            case 'E':
                game.humanEndTurn();
                cout << game.display(  ) << endl;
                do
                {
                    if (handleComputerPlay( game ))
                        break;
                }
                while( game.computerKeepRolling());
                game.computerEndTurn();
                display( game, message, true );
                break;
        }
        
    } while( !game.isGameOver() );
    
    return( 0 );
}



bool handleComputerPlay( cs31::Pig & game )
{
    using namespace std;
    bool result( false );
    if (!game.isGameOver())
    {
        int computer = game.computerPlay();
        cout << "computer rolled:" << computer << endl;
        if (computer == 1)
        {
            result = true;
        }
    }
    return( result );
}


void display( cs31::Pig & game, std::string message, bool checkForGameOver )
{
    using namespace std;
    // add this if statement...
    if (!game.isGameOver() || game.determineGameOutcome()== cs31::Pig::COMPUTERWONGAME)
    {
        cout << game.display( message ) << endl;
    }
    
    if (checkForGameOver)
    {
        game.isGameOver();
    }
}


///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif

