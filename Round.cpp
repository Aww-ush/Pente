#include <iostream>
#include "Round.h"
using namespace std;

int Round::GetPoints(){
    return this->points;
}
int Round::CalculatePoint(int row, int column, char colour)
{
    try
    {
        int totalPoint = 0;
        int rtDiagonalSequence = TotalRightDiagonalPieces(row, column, colour);
        int ltDiagonalSequence = TotalLeftDiagonalPieces(row, column, colour);
        int horizontalSequence = TotalHorizontalPieces(row, column, colour);
        int verticalSequence = TotalVerticalPieces(row, column, colour);
        vector<int> sequences{rtDiagonalSequence, ltDiagonalSequence, horizontalSequence, verticalSequence};
        for (int i : sequences)
        {
            if (i >= 4)
            {
                if (i >= 5)
                {
                    if (!(i % 5))
                    {
                        totalPoint += i;
                    }
                    else
                    {
                        totalPoint += (i - 5) / 4;
                    }
                    HasWon = true;
                }
                else
                {
                    cout << "Congratulations you scored a point!" << endl;
                    totalPoint++;
                }
            }
        }
        if (HasWon)
        {    cout << "Congratulations you have won the game!!" << endl;
        }
        return totalPoint;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}
bool Round::isWinner(){
    return HasWon;
}
// find all diagonal points
//       w
//     w
//   w
// w
int Round::TotalRightDiagonalPieces(int row, int column, char colour)
{
    try
    {
        int totalCount = 1;
        totalCount += CheckMoreDownLeft(++row, --column, totalCount, colour);
        totalCount += CheckMoreUpRight(--row, ++column, totalCount, colour);
        return totalCount;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
}
int Round::TotalLeftDiagonalPieces(int row, int column, char colour)
{
    try
    {
        int totalCount = 1;
        totalCount += CheckMoreUpLeft(--row, --column, totalCount, colour);
        totalCount += CheckMoreDownRight(++row, ++column, totalCount, colour);
        return totalCount;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
}
int Round::TotalHorizontalPieces(int row, int column, char colour)
{
    try
    {
        int totalCount = 1;
        totalCount += CheckMoreLeft(row, --column, totalCount, colour);
        totalCount += CheckMoreRight(row, ++column, totalCount, colour);
        return totalCount;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
}
int Round::TotalVerticalPieces(int row, int column, char colour)
{
    try
    {
        int totalCount = 1;
        totalCount += CheckMoreUp(--row, column, totalCount, colour);
        totalCount += CheckMoreDown(++row, column, totalCount, colour);
        return totalCount;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
}
int Round::CheckMoreUpRight(int row, int column, int count, char colour)
{
    if (!board->isWithInBoard(row))
    {
        return count;
    }
    if (!board->isWithInBoard(column))
    {
        return count;
    }
    if (colour != this->board->ReturnPiece(row, column))
    {
        return count;
    }

    // find the right
    return CheckMoreUpRight(++row, ++column, ++count, colour);
}
int Round::CheckMoreDownLeft(int row, int column, int count, char colour)
{
    if (!board->isWithInBoard(row))
    {
        return count;
    }
    if (!board->isWithInBoard(column))
    {
        return count;
    }
    if (colour != this->board->ReturnPiece(row, column))
    {
        return count;
    }
    // find the right
    return CheckMoreDownLeft(++row, --column, ++count, colour);
}
int Round::CheckMoreDownRight(int row, int column, int count, char colour)
{
    if (!board->isWithInBoard(row))
    {
        return count;
    }
    if (!board->isWithInBoard(column))
    {
        return count;
    }
    if (colour != this->board->ReturnPiece(row, column))
    {
        return count;
    }
    return CheckMoreDownLeft(++row, ++column, ++count, colour);
}
int Round::CheckMoreUpLeft(int row, int column, int count, char colour)
{
    if (!board->isWithInBoard(row))
    {
        return count;
    }
    if (!board->isWithInBoard(column))
    {
        return count;
    }
    if (colour != this->board->ReturnPiece(row, column))
    {
        return count;
    }
    // find the right
    return CheckMoreUpLeft(++row, --column, ++count, colour);
}

int Round::CheckMoreUp(int row, int column, int count, char colour)
{
    if (!board->isWithInBoard(row))
    {
        return count;
    }
    if (!board->isWithInBoard(column))
    {
        return count;
    }
    if (colour != this->board->ReturnPiece(row, column))
    {
        return count;
    }
    // find the right
    return CheckMoreUp(--row, column, ++count, colour);
}
int Round::CheckMoreDown(int row, int column, int count, char colour)
{
    if (!board->isWithInBoard(row))
    {
        return count;
    }
    if (!board->isWithInBoard(column))
    {
        return count;
    }
    if (colour != this->board->ReturnPiece(row, column))
    {
        return count;
    }
    // find the right
    return CheckMoreDown(++row, column, ++count, colour);
}

int Round::CheckMoreLeft(int row, int column, int count, char colour)
{
    if (!board->isWithInBoard(row))
    {
        return count;
    }
    if (!board->isWithInBoard(column))
    {
        return count;
    }
    if (colour != this->board->ReturnPiece(row, column))
    {
        return count;
    }

    // find the right
    return CheckMoreDown(row, --column, ++count, colour);
}
int Round::CheckMoreRight(int row, int column, int count, char colour)
{
    if (!board->isWithInBoard(row))
    {
        return count;
    }
    if (!board->isWithInBoard(column))
    {
        return count;
    }
    if (colour != this->board->ReturnPiece(row, column))
    {
        return count;
    }

    // find the right
    return CheckMoreDown(row, ++column, ++count, colour);
}
