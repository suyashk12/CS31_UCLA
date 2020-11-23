//
//  Player.cpp
//  Pig
//
//

#include "Player.h"
#include <iostream>

namespace cs31
{
    
    Player::Player() : mDie( 6 ), mScore( 0 ), mTotal( 0 )
    {
        
    }
    
    // defining the roll() function
    int Player::roll( int amount )
    {
        if(amount == 0) // in event of random roll.
        {
            mDie.roll();
            int rolledValue = mDie.getValue(); // instructing mDie member object to roll and storing its value in rolledValue
            if(rolledValue == 1) // in event of 1 being randomly rolled.
            {
                mScore = 0; // mScore must be set to 0 if 1 is rolled.
            }
            else
            {
                mScore = mScore + rolledValue; // in the event of random roll value not being 1, mScore must be updated accordingly.
            }
            return(rolledValue); // returns the randomly rolled value
        }
        
        else // handling forced roll value (amount!=0). No handling for out of bound values.
        {
            if(amount==1)
            {
                mScore = 0; // if the forced roll value is 1, mScore must be set to 0.
            }
            else
            {
                mScore = mScore + amount; // in the event of forced roll value not being 1, mScore must be appropriately updated.
            }
            return(amount); // returns amount (!=0) as the forced roll value.
        }
    }
    
    // defining the endTurn() function.
    void Player::endTurn()
    {
        mTotal = mTotal + mScore; // mTotal is updated by adding mScore whenever turn is ended, or endTurn() is invoked.
        mScore = 0; // after updating mTotal, mScore must be set to 0 to be updated again from scratch in the next turn.
    }
    
    // defining the getTotal() function.
    int Player::getTotal( ) const
    {
        return( mTotal ); // returns the present value of mTotal.
    }
    
    // defining the getScore() function.
    int  Player::getScore( ) const
    {
        return( mScore ); // returns the present value of mScore.
    }
    
}


