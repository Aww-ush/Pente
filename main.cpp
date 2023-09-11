#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Coin.h"
#include "Human.h"
#include "Computer.h"
#include "Game.h"
using namespace std;
const char WHITE_PIECE = 'W';
const char BLACK_PIECE = 'B';
int main()
{

    Board *boardPtr = new Board();
    boardPtr->PrintBoard();
    string name = "Default Name";
    // cout << "Enter your name" << endl;
    // cin >> name;
    
    
    
    cout << "The first player is decided by coin toss. Guess the side of coin H OR T!" << endl;
    char userChoice;
    cin >> userChoice;
    Coin *coin = new Coin;
    char humanColour, computerColour;
    if (coin->Toss())
    {
        if(coin->WinOrLose(userChoice)){
            cout << "You have won the toss please go first" << endl;
            humanColour = WHITE_PIECE;
            computerColour = BLACK_PIECE;
        }
        else{
            cout << "Coumputer has won the toss you will go second" << endl;
            humanColour = BLACK_PIECE;
            computerColour = WHITE_PIECE;
        }
    }
    Player *humanPlayer = new Human(boardPtr, name, 'W');
    Player *computerPlayer = new Computer(boardPtr, 'B');
    Game* game = new Game(humanPlayer, computerPlayer, boardPtr);
    if(!game->PlayRound()){
        cout << "Do you want to save the game?" << endl;
    }
    return 0;
}
// coin toss game
// if they win coin toss they can go first
// they can only place in the white square
// repeat the message
// print the board