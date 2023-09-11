#ifndef COMPUTER_H
#define COMPUTER_H
#include "Player.h"
class Computer : public Player
{
private:
    
public:
    Computer(Board *board, char colour);
    bool MakeMove(int row, int column) override;
};

#endif //COMPUTER_H
