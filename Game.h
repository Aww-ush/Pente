#ifndef GAME_H
#define GAME_H
#include "Human.h"
#include "Computer.h"
#include "Board.h"
#include "Player.h"
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

public:
    Game(Player *human, Player *computer, Board *board);
    bool PlayRound();
    bool AnnounceRoundWinner();
    bool AnnounceTournamentWinner();
    bool ResetRound();
    bool CheckForPoints();
    bool Continue();
    std::pair<int, int> ConvertMoveToRowCol(std::string position);

    std::string AskForPosition();
};
#endif // GAME_H
