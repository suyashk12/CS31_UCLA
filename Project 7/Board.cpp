//
//  Board.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Board.h"


namespace cs31
{
    Board::Board() : mHumanScore( 0 ), mHumanTotal(0), mComputerScore(0), mComputerTotal(0),
                     mRolledValue(0), mIsHumanTurn(true), mGameOver(false), mHumanWon(false)
    {

    }
    
    // mutator for the gameOver boolean member
    void Board::setGameOver( bool value )
    {
        mGameOver = value;
    }
    
    // accessor for the gameOver boolean member
    bool Board::isGameOver( ) const
    {
        return( mGameOver );
    }

    // mutator for the humanWon boolean member
    void Board::markHumanAsWinner()
    {
        mHumanWon = true;
    }
    
    // mutator for the computerWon boolean member
    void Board::markComputerAsWinner()
    {
        mHumanWon = false;
    }
    
    // accessor for the humanWon boolean member
    bool Board::isHumanWinner() const
    {
        return( mHumanWon );
    }
    
    // defining the setHumanScore() function.
    void Board::setHumanScore( int score )
    {
        if(isHumanTurn() && !isGameOver()) // the following condition ensures that changes should be made to mHumanScore if and only if it is the human's turn and the game is not over.
        {
            mHumanScore = score; // sets mHumanScore to score, which is the value fed to the setHumanScore() function.
        }
    }
    
    // defining the getHumanScore() function.
    int  Board::getHumanScore() const
    {
        return( mHumanScore ); // returns the present value of mHumanScore member variable of a Board object.
    }
    
    // defining the setComputerScore() function.
    void Board::setComputerScore( int score )
    {
        if(!isHumanTurn() && !isGameOver()) // the following condition ensures that changes should be made to mComputerScore if and only if it is the computer's turn and the game is not over.
        {
            mComputerScore = score; // sets mComputerScore to score, which is the value fed to the setComputerScore() function.
        }
    }
    
    // defining the getComputerScore() function.
    int  Board::getComputerScore() const
    {
        return( mComputerScore ); // returns the present value of mComputerScore member variable of a Board object.
    }
    
    // mutator for the rolledValue data member
    void Board::setRolledValue( int amount )
    {
        if (!mGameOver)
            mRolledValue = amount;
    }
    
    // accessor for the rolledValue data member
    int  Board::getRolledValue() const
    {
        return( mRolledValue );
    }
    
    // mutator for the humanTurn member
    void Board::setHumanTurn( )
    {
        // it becomes the human's turn but only if the game isn't over
        if (!mGameOver)
            mIsHumanTurn = true;
    }
    
    // mutator for the computerTurn member
    void Board::setComputerTurn( )
    {
        // it become the computer's turn but only if the game isn't over
        if (!mGameOver)
            mIsHumanTurn = false;
    }
    
    // accessor for the humanTurn boolean member
    bool Board::isHumanTurn() const
    {
        return( mIsHumanTurn );
    }

    // defining the setHumanTotal() function.
    void Board::setHumanTotal( int total )
    {
        if(isHumanTurn() && !isGameOver()) // the following condition ensures that changes should be made to mHumanTotal if and only if it is the human's turn and the game is not over.
        {
            mHumanTotal = total; // sets mHumanTotal to total, which is the value fed to the setHumanTotal() function.
        }
    }
    
    // defining the getHumanTotal() function.
    int  Board::getHumanTotal() const
    {
        return( mHumanTotal ); // returns the present value of mHumanTotal member variable of a Board object.
    }
    
    // defining the setComputerTotal() function.
    void Board::setComputerTotal( int total ) 
    {
        if(!isHumanTurn() && !isGameOver()) // the following condition ensures that changes should be made to mComputerTotal if and only if it is the computer's turn and the game is not over.
        {
            mComputerTotal = total; // sets mComputerTotal to total, which is the value fed to the setComputerTotal function.
        }
    }
    
    // defining the getComputerTotal() function.
    int  Board::getComputerTotal() const
    {
        return( mComputerTotal ); // returns the present value of mComputerTotal member variable of a Board object.
    }
    
    // stringify the Board
    std::string Board::display( ) const
    {
        std::string s = "\t\t  --Pig Game-- \n\tHuman:\t";
        s += std::to_string( mHumanTotal );
        s += "\t\tComputer:\t";
        s += std::to_string( mComputerTotal );
        s += "\n";
        
        return( s );
    }
    


    
}
