#ifndef ROUND_H
#define ROUND_H
#include "Board.h"
class Round{
public:
    Round(Board* board){
        this->board = board;
    }
    // this function takes the recent position and determies if the board has the more points near to it
    // if there is four in a row then there is one point
    // if there is 5 in a row then its a win
    int CalculatePoint(int row, int column, char colour);

    bool isWinner();
    int TotalRightDiagonalPieces(int row, int column, char colour);
    int TotalLeftDiagonalPieces(int row, int column, char colour);
    int TotalHorizontalPieces(int row, int column, char colour);
    int TotalVerticalPieces(int row, int column, char colour);
    
    int CheckMoreDownLeft(int row, int column, int count, char colour);
    int CheckMoreDownRight(int row, int column, int count, char colour);
    int CheckMoreUpLeft(int row, int column, int count, char colour);
    int CheckMoreUpRight(int row, int column, int count, char colour);
    int CheckMoreUp(int row, int column, int count, char colour);
    int CheckMoreDown(int row, int column, int count, char colour);
    int CheckMoreRight(int row, int column, int count, char colour);
    int CheckMoreLeft(int row, int column, int count, char colour);

    int GetPoints();

private:
    Board* board;
    int points;
    bool HasWon = false;
};
#endif //ROUND_H
