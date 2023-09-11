#ifndef Player_H
#define Player_H
#include <iostream>
#include "Board.h"
class Player
{
private:
    int totalPoints = 0;
    int totalMoves = 0;
    char _colour = '0';
    std::string _playerName;
    std::string _computerName = "Computer";
    Board *_board;
    bool isFirstMover = false;
    bool isTurnToMove = false;

public:
    //count the total points position are A10 where A is row abd 10 is column
    bool Move(int row, int column, char colour);
    int GetTotalPoints();
    bool isFirstMoveMaker();
    bool SetTotalMoves();
    bool IncreasePoint(int points);
    int GetTotalMoves();
    bool SetBoard(Board *board);
    Board *GetBoard();
    bool SetColour(char colour);
    char GetColour();
    bool SetFirstMoveMaker();
    bool SetName(std::string name);
    virtual bool MakeMove(int row, int column) = 0;
};
#endif // Player_H
