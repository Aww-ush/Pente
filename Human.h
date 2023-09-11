#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"
#include "Board.h"

class Human : public Player
{
private:

public:
    Human(Board *board, std::string name, char color);
    bool MakeMove(int row, int column) override;
    bool AskForHelp();
    std::string AskForPosition();
};

#endif // HUMAN_H
