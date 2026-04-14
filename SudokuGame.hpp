#ifndef SUDOKUGAME_HPP
#define SUDOKUGAME_HPP

#include "SudokuBoard.hpp"
#include "SudokuSolver.hpp"

class SudokuGame
{
private:
    SudokuBoard board;
    SudokuSolver solver;
    bool running;

public:
    SudokuGame();
    void run();

private:
    void displayMenu();
    void handleInput();
    void enterMove();
    void solvePuzzle();
    void loadGame();
    void saveGame();
};

#endif
