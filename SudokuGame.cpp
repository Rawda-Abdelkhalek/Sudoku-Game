#include "SudokuGame.hpp"
#include <iostream>

using namespace std;

SudokuGame::SudokuGame() : running(true) {}

void SudokuGame::run()
{
    while (running)
    {
        board.getCell();
        displayMenu();
        handleInput();
    }
}

void SudokuGame::displayMenu()
{
    cout << "\n1) Enter a move\n";
    cout << "2) Solve automatically\n";
    cout << "3) Load\n";
    cout << "4) Save\n";
    cout << "5) Exit\n";
    cout << "Choice: ";
}

void SudokuGame::handleInput()
{
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1: enterMove(); break;
    case 2: solvePuzzle(); break;
    case 3: loadGame(); break;
    case 4: saveGame(); break;
    case 5: running = false; break;
    default: cout << "Invalid choice\n";
    }
}

void SudokuGame::enterMove()
{
    int r, c, v;
    cout << "Enter row col value: ";
    cin >> r >> c >> v;

    if (!board.setboard(r - 1, c - 1, v))
        cout << "Invalid move!\n";
}

void SudokuGame::solvePuzzle()
{
    if (solver.solve(board))
        cout << "Solved!\n";
    else
        cout << "No solution!\n";
}

void SudokuGame::loadGame()
{
    string file;
    cout << "Filename: ";
    cin >> file;

    if (!board.loadFromFile(file))
        cout << "Failed to load\n";
}

void SudokuGame::saveGame()
{
    string file;
    cout << "Filename: ";
    cin >> file;

    board.save(file);
}
