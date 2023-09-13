#ifndef GAME_H
#define GAME_H
#include "Human.h"
#include "Computer.h"
#include "Board.h"
#include "Player.h"
#include "Round.h"
class Game
{
private:
    char nextMover;
    void SetNextMover(char player);
    bool isGameOver = false;
    std::string WinnerRoundMessage(std::string playerName);
    static constexpr const char HUMAN_CHARACTER = 'H';
    static constexpr const char COMPUTER_CHARACTER = 'C';
    char First;
    Player *human;
    Player *computer;
    Board *board;
    Round *round;
    int totalHumanPoints = 0;
    int totalComputerPoints = 0;
    int totalHumanRoundPoints = 0;
    int totalComputerRoundPoints = 0;

public:
    Game(Player *human, Player *computer, Board *board, Round *round);
    bool PlayRound();
    bool AnnounceRoundWinner();
    bool AnnounceTournamentWinner();
    bool ResetRound();
    bool CheckForPoints();
    bool Continue();
    std::string AskForPosition();
    std::pair<int, int> ConvertMoveToRowCol(std::string position);
};
#endif // GAME_H
