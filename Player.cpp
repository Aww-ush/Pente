#include <iostream>
#include "Player.h"
#include "Board.h"
using namespace std;

// count the total points position are A10 where A is row abd 10 is column
bool Player::Move(int row, int column, char colour)
{
    // i want this fucntion to be overloaded in human calss
    try
    {
        
        // first move
        if (isFirstMoveMaker() && GetTotalMoves() == 0)
        {
            if (!_board->InsertFirstPiece(colour))
            {
                cout << "There was error setting first piece" << endl;
                return false;
            }
        }
        else if (isFirstMoveMaker() && GetTotalMoves() == 1)
        {
            if (!_board->IsSecondPieceValid(row, column))
            {
                cout << "Could not place the second piece to that position " << endl;
                cout << "The piece must be place on the 3 intersections away from the center" << endl;
                return false;
            }
            if (!_board->InsertPiece(row, column, colour))
            {
                cout << "Something went wrong while moving the piece" << endl;
                return false;
            }
        }
        else
        {
            if (!_board->InsertPiece(row, column, colour))
            {
                cout << "Something went wrong while moving the piece" << endl;
                return false;
            }
        }
        totalMoves++;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}



int Player::GetTotalPoints()
{
    return totalPoints;
}

bool Player::IncreasePoint(int points)
{
    try
    {
        totalPoints += totalPoints;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

bool Player::SetTotalMoves()
{
    try
    {
        totalMoves++;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

bool Player::SetBoard(Board *board)
{
    try
    {
        _board = board;
        totalMoves++;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

Board *Player::GetBoard()
{
    return _board;
}

bool Player::SetColour(char colour)
{
    try
    {
        _colour = colour;
        cout << "Set the color for " << _playerName << " as " << _colour << endl;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

bool Player::SetName(string name)
{
    try
    {
        _playerName = name;
        cout << "Set the player name to " << _playerName << endl;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

bool Player::SetFirstMoveMaker()
{
    try
    {
        isFirstMover = true;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

bool Player::isFirstMoveMaker()
{
    return isFirstMover;
}