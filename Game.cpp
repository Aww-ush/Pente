#include <iostream>
#include "Game.h"

using namespace std;
Game::Game(Player *human, Player *computer, Board *board, Round* round)
{
    this->human = human;
    this->computer = computer;
    this->board = board;
    this->round = round;
}
bool Game::PlayRound()
{
    try
    {
        bool playRound = true;
        // set who goes first

        if (human->GetColour() == 'W')
        {
            string position = AskForPosition();
            pair<int, int> numericalPosition = ConvertMoveToRowCol(position);

            while (!human->MakeMove(numericalPosition.first, numericalPosition.second))
            {
                cout << "Failed to make first move, you can only insert in center 'J10'" << endl;
                position = AskForPosition();

            }

            totalHumanRoundPoints += round->CalculatePoint(numericalPosition.first, numericalPosition.second, human->GetColour());
            totalHumanPoints += totalHumanRoundPoints;
            SetNextMover(COMPUTER_CHARACTER);
        }
        else
        {
            pair<int, int> numericalPosition = board->GetCenterOfBoard();

            while (!computer->MakeMove(numericalPosition.first, numericalPosition.second))
            {
                cout << "Failed to move computer" << endl;
            }
        }
        while (playRound)
        {
            if (nextMover == HUMAN_CHARACTER)
            {
                // MOVE human
                string position = AskForPosition();
                pair<int, int> numericalPosition = ConvertMoveToRowCol(position);
                SetNextMover(COMPUTER_CHARACTER);
                
                while (!human->MakeMove(numericalPosition.first, numericalPosition.second))
                {
                    position = AskForPosition();
                }
                totalHumanRoundPoints += round->CalculatePoint(numericalPosition.first, numericalPosition.second, human->GetColour());
                totalHumanPoints += totalHumanRoundPoints;
                cout << "total Human Points in this round = " << totalHumanRoundPoints;
            }
            if(nextMover == COMPUTER_CHARACTER)
            {
                // MOVE human
                cout << "Comupters turn" << endl;
                int row = rand() % 19;
                int column = rand() % 19;

                SetNextMover(HUMAN_CHARACTER);
                while (!computer->MakeMove(row, column))
                {
                    cout << "Internal Server Error: Computer failed to make a move" << endl;
                }
                totalComputerRoundPoints += round->CalculatePoint(row, column, computer->GetColour());
                totalComputerPoints += totalHumanRoundPoints;
                cout << "total Computer Points in this round = " << totalHumanRoundPoints;
            }

            //GameOver
            if (!Continue()){
                return false;
            }
            cout << "The board becomes" << endl;
            board->PrintBoard();
        }
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

bool Game::AnnounceRoundWinner()
{

    try
    {
        string name = "Dummy Name";
        cout << WinnerRoundMessage(name) << endl;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

bool Game::AnnounceTournamentWinner()
{
    try
    {
        string name = "Dummy Name";
        cout << WinnerRoundMessage(name) << endl;
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

string Game::WinnerRoundMessage(string playerName)
{
    string message = playerName + " has won this match!!!";
    return message;
}

bool Game::Continue()
{
    try
    {
        char result;
        cout << "Do you want to continue? Y or N" << endl;
        cin >> result;
        return result == 'Y' ? true : false;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        cout << "Internal Server Error";
        return false;
    }
}

void Game::SetNextMover(char player)
{
    nextMover = player;

}
pair<int, int> Game::ConvertMoveToRowCol(string position)
{
        // suppose the input is A10
        char alphaRow = position.at(0);
        string alphaCol = position.substr(1);
        int row = alphaRow - 'A';
        int col = stoi(alphaCol) - 1;
        return pair<int, int>{row, col};
    
}
string Game::AskForPosition()
{
    string position;
    cout << "Where do you want to move you Piece ?" << endl;
    cin >> position;
    string capitalPosition = "";
    for (char &c : position)
    {
        capitalPosition += toupper(c);
    }
    return capitalPosition;
}

