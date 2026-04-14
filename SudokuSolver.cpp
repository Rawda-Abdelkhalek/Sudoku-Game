#include "SudokuSolver.hpp"

SudokuSolver::SudokuSolver(){};

 bool SudokuSolver::solve(SudokuBoard& board)
    {
        // find an empty squares
        for (int r = 0; r < 9; ++r)
        {
            for (int c = 0; c < 9; ++c)
            {
                if (board.getValue(r, c) == 0)
                {
                    // loop through all legal value of the square
                    for (int v = 1; v < 10; ++v)
                    {
                        if (board.isValidForSolver(r, c, v))
                        {
                            board.setValue(r,c,v);
                            // check if we found the right values by  recursivly calling solve
                            if (solve(board))
                                return true;

                            // if we didnt find right value for the square then backtrack
                            board.setValue(r,c,0);

                        }
                    }
                    return false;
                }
            }
        }

        // if there is no empty squares then the board is solved
        return true;
    }

