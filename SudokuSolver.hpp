#ifndef SUDOKUSOLVER_HPP
#define SUDOKUSOLVER_HPP

#include "SudokuBoard.hpp"
class SudokuSolver 
{

public:
    SudokuSolver();
    bool solve(SudokuBoard& board);

};

#endif
