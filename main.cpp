// #include <iostream>
// #include <vector>
// #include <array>
// #include <string>
// #include <fstream>
// #include <chrono>
// #include <iomanip>
// #include <sstream>
// #include <optional>

// #include "SudokuBoard.hpp"
// #include "SudokuSolver.hpp"

// using std::vector;
    

// int main(){

#include "SudokuGame.hpp"

int main()
{
    SudokuGame game;
    game.run();


//     vector<vector< int >> board = {
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 1, 0, 2, 3, 4},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0, 0, 0}};
//    SudokuBoard myGame(board);
//    SudokuSolver solver;


   
//     bool running = true;
//     while (running)
//     {

//         myGame.getCell();

//         // get urser input
//         string command;
//         getline(cin, command);

//         // process user input

//         if (command.substr(0, 3) == "set")
//         {
//             int y = command[4] - 'a';
//             int x = command[5] - '1';
//             int value = command[7] - '0';

//             myGame.setValue(x,y,value);

//         };

//         if (command == "exit")
//         {
//             running = false;
//         }
//         if (command.substr(0, 4) == "save")
//         {
//             string filename;
//             if (command.length() > 5)
//             {
//                 filename = command.substr(5);
//             }
//             else
//             {
//                 time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
//                 stringstream ss;
//                 ss << "save_" << put_time(localtime(&now), "%m-%d_%H-%M-%S") << ".txt";
//                 filename = ss.str();
//             }
//             myGame.save(filename);
//         };
//         if (command.substr(0, 4) == "load")
//         {
//             string filename = command.substr(5);
//             if (myGame.loadFromFile(filename))
//             {
//                 cout << "Game loaded successfully!" << endl;
//             }
//             else
//             {
//                 cout << "Failed to load file!" << endl;
//             }
//         }


//         if (command == "solve")
//         {

//            if (solver.solve(myGame))
// {
//     cout << colors::GREEN << "Solved!" << colors::RESET << endl;
// }
//             else
//             {
//                 cout << "No solution found." << endl;
//             }
//         }
    
//     }
//     return 0;
}