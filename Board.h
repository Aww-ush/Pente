// board generated the board in constructor
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
class Board
{
public:
    // constructor

    Board() : _board(BOARD_SIZE, std::vector<char>(BOARD_SIZE, INITIAL_BOARD_PIECE)) {}

    // insert a piece with colour colur at place "place"
    bool InsertPiece(int row, int column, char pieceType);
    // return the current board
    std::vector<std::vector<char> > GetBoard();
    //print the current status of the board
    bool PrintBoard();
    bool isWithInBoard(int position);
    bool IsPosiitonEmpty(int row, int cloumn);
    // cmake threads to check for the multiple row instead of creating 2 for loop?-- later feature if time
    bool InsertFirstPiece(char colour);
    bool IsSecondPieceValid(int row, int column);
    bool IsPieceValid(char input);
    // remove the pievces form the board
    bool removePiece(int row, int column);
    std::pair<int, int> GetCenterOfBoard();
    bool ResetBoard();

private:
    // making it compile time
    static constexpr int BOARD_SIZE = 19;
    static constexpr char INITIAL_BOARD_PIECE = 'O';
    static constexpr char WHITE_PIECE = 'W';
    static constexpr char BLACK_PIECE = 'B';
    std::vector<std::vector<char> > _board;
};

#endif //BOARD_H
