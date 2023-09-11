#include "Board.h"
#include <iostream>
#include <string>

// constructor
using namespace std;

// insert a piece with colour colur at specific row and column
bool Board::InsertPiece(int row, int column, char pieceType)
{
    try
    {
        if (!isWithInBoard(row))
        {
            cout << "the row is not within the board" << endl;
            return false;
        }
        if (!isWithInBoard(column))
        {
            cout << "the column is not within the board " << endl;
            return false;
        }
        if (!IsPieceValid(pieceType))
        {
            cout << "the piece is not of valid colour" << endl;
            return false;
        }

        _board[row][column] = pieceType;
        
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        cout << "Could not enter the piece" << endl;
        return false;
    }
}
// return the current board
std::vector<std::vector<char>> Board::GetBoard()
{
    return _board;
}
// print the current status of the board
bool Board::PrintBoard()
{
    try
    {
        for (int row = 0; row < BOARD_SIZE; row++)
        {
            for (int column = 0; column < BOARD_SIZE; column++)
            {
                cout << _board[row][column];
            }
            cout << endl;
        }
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}
bool Board::isWithInBoard(int position)
{
    try
    {
        return (position < BOARD_SIZE) ? true : false;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}
bool Board::IsPieceValid(char input)
{
    if (input != WHITE_PIECE && input != BLACK_PIECE)
    {
        return false;
    }
    return true;
}
bool Board::IsPosiitonEmpty(int row, int cloumn)
{

    return (_board[row][cloumn] != INITIAL_BOARD_PIECE) ? true : false;
}
bool Board::InsertFirstPiece(char colour)
{
    // check if the colour is valid                                     
    int middle = (BOARD_SIZE + 1) / 2;
    return InsertPiece(middle, middle, colour);
}
bool Board::IsSecondPieceValid(int row, int column)
{
    // first check if ther is already the piece in the place they are tyna put
    try
    {
        if (IsPosiitonEmpty(row, column))
        {
            cout << "the position is not empty" << endl;
            return false;
        }
        pair<int, int>
            center = GetCenterOfBoard();
        // since it it at the center which is (10, 10)
        // and they want to pu the new piece at (10, 11)
        int dx = abs(row - center.first);
        int dy = abs(column - center.second);

        if ((dx >= 3 && dy >= 0) ||
            (dx >= 0 && dy >= 3) ||
            (dx >= 3 && dy >= 3))
        {
            return true;
        }
        else
        {
            cout << " the piece must be kept three intersection away" << endl;
            return false;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        cout << "Failed to remove the piece" << endl;
        return false;
    }
}
bool Board::removePiece(int row, int column)
{
    try
    {
        if (IsPosiitonEmpty(row, column))
        {
            cout << "The position is empty so no pieve to remove" << endl;
            return false;
        }
        _board[row][column] = INITIAL_BOARD_PIECE;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        cout << "Failed to remove the piece" << endl;
        return false;
    }
}
pair<int, int> Board::GetCenterOfBoard()
{
    try
    {
        int middle = (BOARD_SIZE + 1) / 2;
        return pair<int, int>(middle, middle);
    }
    catch (const std::exception &e)
    {
        cout << "there was erro while getting center of the board";
        std::cerr << e.what() << '\n';
    }
}
bool Board::ResetBoard(){
    try
    {
        for (int row = 0; row < BOARD_SIZE; row++)
        {
            for (int column = 0; column < BOARD_SIZE; column++)
            {
                _board[row][column] = INITIAL_BOARD_PIECE;
            }
        }
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        cout << "There was error while resetting the board" << endl;
        return false;
    }
}
