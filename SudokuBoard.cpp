
#include <iostream>
#include <fstream>
#include <vector>
#include "SudokuBoard.hpp"

using std::vector;
using namespace std;


//  Constructors
SudokuBoard::SudokuBoard(){
    // Resize both grids to 9 x 9, filled with 0
    board.resize(9, vector<int>(9, 0));
    locked.resize(9, vector<int>(9, 0));
};
SudokuBoard::SudokuBoard(const std::vector<std::vector<int>> &initial) 
    {
            board.resize(9, vector<int>(9, 0));
            locked.resize(9, vector<int>(9, 0));
        for (int r = 0; r < 9; r++)
            for (int c = 0; c < 9; c++)
            {
                board[r][c] = initial[r][c];
                locked[r][c] = (initial[r][c] != 0) ? 1 : 0;
            }
    };

void SudokuBoard::getCell()
    {

        cout << colors::GRAY;
        cout << "   1 2 3    4 5 6    7 8 9   " << endl
             << endl
             << colors::RESET;
        // removeCells output (display a sudoku board)
        for (int y = 0; y < 9; ++y)
        {
            if (y == 3 || y == 6)
                cout << colors::GRAY << "----------+--------+-------" << colors::RESET << endl;
            cout << colors::GRAY << char('A' + y) << "  " << colors::RESET;
            for (int x = 0; x < 9; ++x)
            {
                if (x == 3 || x == 6)
                    cout << colors ::GRAY << " | " << colors ::RESET;
                if (board[y][x] != 0)
                    cout << colors::GREEN << board[y][x] << " " << colors ::RESET;
                else
                    cout << colors::WHITE << ". " << colors::RESET;
            }
            cout << endl;
        }
        cout << colors::RESET << endl
             << "enter acommad : ";
    }



bool SudokuBoard::isvalid(int r, int c, int value)
    {

        // make sure we are on the board
        if (r < 0 || r >= 9 || c < 0 || c >= 9)
        {
            // cout << " Please make sure your index within the board " << endl;
            return false;
        }
        // make sure the square not locked

        if (locked[r][c] == 1)
        {
            //  cout << "sorry locked number " << endl ;
            return false;
        }

        // make sure the value is valid
        if (value < 1 || value > 9)
        {
            //  cout << " Please enter avalue between 0 - 9 " << endl ;
            return false;
        }

        // check rows and colomns
        for (int l = 0; l < 9; ++l)
            if (board[l][c] == value)
            {
                // cout << "there is the same value in this Row" << endl ;
                return false;
            }

        for (int i = 0; i < 9; ++i)
            if (board[r][i] == value)
            {
                // cout << "There is the same value in this column" << endl ;
                return false;
            }

        // check subgdrid
        int subgrid_x = (c / 3) * 3;
        int subgrid_y = (r / 3) * 3;

        for (int r2 = subgrid_y; r2 < subgrid_y + 3; ++r2)
            for (int c2 = subgrid_x; c2 < subgrid_x + 3; ++c2)
                if (board[r2][c2] == value)
                {
                    // cout << "there is the same value in this box " <<endl ;
                    return false;
                }

        return true;
    };


bool SudokuBoard::setboard(int r, int c, int value)
{
    if (isvalid(r, c, value))
    {
        board[r][c] = value;
        return true;
    };
    return false;
}


   bool  SudokuBoard::save(const string &filename)
    {

        // output file stream opject
        ofstream file{string(filename)};
        // make sure file is open
        if (!file.is_open())
            return false;

        // write the file state to the file
        for (int r = 0; r < 9; ++r)
        {
            for (int c = 0; c < 9; ++c)
            {
                file << board[r][c];
                if (c < 8)
                    file << " ";
            }
            file << endl;
        }
        // close the file and retrun true
        return true;
    }

 bool SudokuBoard::loadFromFile(const string &filename)
    {
        ifstream file{filename};
        // open a file
        if (!file.is_open())
            return false;

        for (int r = 0; r < 9; ++r)
        {
            for (int c = 0; c < 9; ++c)
            {
                int val = 0;
                if (!(file >> val))
                    return false;
                if (val < 0 || val > 9)
                    return false;
                board[r][c] = val;
                locked[r][c] = (val != 0) ? 1 : 0;
            }
        }
        return true;
    }
int SudokuBoard::getValue(int r, int c) const
{
    return board[r][c];
}

void SudokuBoard::setValue(int r, int c, int value)
{
    board[r][c] = value;
}
