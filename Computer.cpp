#include "Computer.h"
#include "Board.h"
#include <iostream>
using namespace std;
Computer::Computer(Board *board, char colour)
{
    if (!SetBoard(board))
    {
        cout << "There was error setting the board for human" << endl;
    }
    if (!SetName("Computer"))
    {
        cout << "There was error setting the name for human" << endl;
    }
    if (!SetColour(colour))
    {
        cout << "There was error setting the color for human" << endl;
    }
}
bool Computer::MakeMove(int row, int column)
{
    try
    {
        Board *board = GetBoard();
        char colour = GetColour();
        if (colour == 'W')
        {
            if (SetFirstMoveMaker())
            {
                cout << "Internal Server error in Computer::SetFirstMoveMaker" << endl;
                return false;
            }
        }

        if (!Move(row ,column, colour))
        {
            cout << "Could not move the piece to position " << row << " " << column << endl;
            return false;
        }
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}