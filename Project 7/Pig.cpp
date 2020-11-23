//
//  Pig.cpp
//  Pig
//
//

#include "Pig.h"
#include <iostream>

namespace cs31
{
    Pig::Pig()
    {
        
    }
    
    // stringify this Game by stringifying this Game's Board
    std::string Pig::display( std::string msg )
    {
        using namespace std;
        std::string s = mBoard.display();
        s = s + msg;
        
        if (isGameOver())
        {
            if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Pig!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Pig!\n";
            }
        }
        return( s );
    }
    
    // defining humanPlay() function.
    int Pig::humanPlay( int amount )
    {
        int amountrolled = mHuman.roll(amount); // instructs mHuman object to roll by invoking its roll() function and stores the returned value in amountrolled. The amount parameter of roll() handles the necessity of random or forced rolls.
        mBoard.setHumanTurn(); // informs the board that it is the human's turn.
        mBoard.setRolledValue(amountrolled); // sets mRolledValue member variable of mBoard to amountrolled.
        mBoard.setHumanScore(mHuman.getScore()); // since the roll() function of mHuman updates its mScore member variable, mBoard's mHumanScore is updated by using the return value of mHuman's getScore() function, which is the updated value of its mScore member variable.
        return( amountrolled );
    }
    
    // inform the human Player that their turn has ended
    // update the board's human total
    void Pig::humanEndTurn()
    {
        mHuman.endTurn();
        mBoard.setHumanTotal( mHuman.getTotal() );
    }
    
    // defining computerPlay() function.
    int Pig::computerPlay( int amount )
    {
        int amountrolled = mComputer.roll(amount); // instructs mComputer object to roll by invoking its roll() function and stores the returned value in amountrolled. The amount parameter of roll() handles the necessity of random or forced rolls.
        mBoard.setComputerTurn(); // informs the board that it is the computer's turn.
        mBoard.setRolledValue(amountrolled); // sets mRolledValue member variable of mBoard to amountrolled.
        mBoard.setComputerScore(mComputer.getScore()); // since the roll() function of mComputer updates its mScore member variable, mBoard's mComputerScore is updated by using the return value of mComputer's getScore() function, which is the updated value of its mScore member variable.
        return( amountrolled );
    }
    
    // when keeprolling returns true, the computer will keep rolling
    // this method implements a 60% chance to keep rolling...
    // unless the score plus the existing total >= SCORENECESSARYTOWIN
    bool Pig::computerKeepRolling() const
    {
        bool result( false );
        Die d( 5 );
        d.roll();
        if (d.getValue() >= 3)
        {
            result = true;
        }
        if (mComputer.getScore() + mComputer.getTotal() >= SCORENECESSARYTOWIN)
        {
            // stop...
            result = false;
        }
        return( result );
    }
    
    // inform the computer Player that their turn has ended
    // update the board's computer total
    void Pig::computerEndTurn()
    {
        mComputer.endTurn();
        mBoard.setComputerTotal( mComputer.getTotal() );
    }
    
    // defining the determinGameOutcome() function.
    Pig::GAMEOUTCOME  Pig::determineGameOutcome( ) const
    {
        GAMEOUTCOME result = GAMEOUTCOME::GAMENOTOVER; // assuming initially that the game isn't over.
        if(mBoard.getHumanTotal()>=SCORENECESSARYTOWIN) // if mHumanTotal of mBoard is equal to or exceeds SCORENECCESSARYTOWIN, set result to HUMANWONGAME.
        {
            result = GAMEOUTCOME::HUMANWONGAME;
            
        }
        else if(mBoard.getComputerTotal()>=SCORENECESSARYTOWIN) // if mComputerTotal of mBoard is equal to or exceeds SCORENECCESSARYTOWIN, set result to COMPUTERWONGAME.
        {
            result = GAMEOUTCOME::COMPUTERWONGAME;
        }
        return( result );
    }
    
    // defining the isGameOver() function. 
    bool Pig::isGameOver()
    {
        if(determineGameOutcome()==GAMEOUTCOME::HUMANWONGAME) // in event of mHuman having won game.
        {
            mBoard.setGameOver(true); // inform mBoard that game is over by marking mGameOver true using setGameOver() function.
            mBoard.markHumanAsWinner(); // mark mHumanWon member variable of mBoard to true using markHumanAsWinner() function.
            return(true); // return true because game is over.
        }
        else if(determineGameOutcome()==GAMEOUTCOME::COMPUTERWONGAME) // in event of mComputer having won game.
        {
            mBoard.setGameOver(true); // inform mBoard that game is over by marking mGameOver true using setGameOver() function.
            mBoard.markComputerAsWinner(); // mark mHumanWon member variable of mBoard to false using markComputerAsWinner() function.
            return(true); // return true because game is over.
        }
        else
        {
            mBoard.setGameOver(false); // if the game is continuing, mark mGameOver member variable of mBoard as false.
            return( false ); // return false because game isn't yet over.
        }
    }

}

