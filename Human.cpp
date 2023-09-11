#include "Human.h"
#include "Board.h"
#include <iostream>
using namespace std;
Human::Human(Board *board, string name, char colour)
{
    if (!SetBoard(board))
    {
        cout << "There was error setting the board for human" << endl;
    }
    if (!SetName(name))
    {
        cout << "There was error setting the name for human" << endl;
    }
    if (!SetColour(colour))
    {
        cout << "There was error setting the color for human" << endl;
    }
}
bool Human::MakeMove(int row, int column)
{
    try
    {
        Board *board = GetBoard();
        char colour = GetColour();
        if(colour == 'W'){
            if(SetFirstMoveMaker()){
                cout << "Internal Server error in human::MakeMove" << endl;
                return false;
            }
        }
        string position = AskForPosition();
        if (!Move(row, column, colour))
        {
            cout << "Could not move the piece to position " << position << endl;
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
string Human::AskForPosition()
{
    string position;
    cout << "Where do you want to move you Piece ?" << endl;
    cin >> position;
    string capitalPosition = "";
    for (char &c : position)
    {
        capitalPosition += toupper(c);
    }
    return position;
}
