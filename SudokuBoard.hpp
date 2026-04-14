#ifndef SUDOKUBOARD_HPP
#define SUDOKUBOARD_HPP


#include <iostream>
#include <fstream>
#include <vector>

using std::vector;
using namespace std;

namespace colors
{
    static const char *GRAY = "\033[38;2;130;130;130m";
    static const char *GREEN = "\033[38;2;80;220;120m";
    static const char *WHITE = "\033[1;37m";
    static const char *RESET = "\033[0m";
}
class SudokuBoard
{

protected:
    // int board[9][9]; we can not use this method this creat new copy of board  when the construct work but the values in orignial not changed , also i can not just remove int from construct and use equal not accpetable
    std::vector<std::vector<int>> board;
    std::vector<std::vector<int>> locked;

public:
    SudokuBoard();
    SudokuBoard(const std::vector<std::vector<int>> &initial) ;
    void getCell();
    // fn to check if the move is legal
    bool isvalid(int r, int c, int value);
    bool setboard(int r, int c, int value);
    int getValue(int r, int c) const;
    void setValue(int r, int c, int value);

      // fn to save a game
    bool save(const string &filename);

    bool loadFromFile(const string &filename);

};


#endif