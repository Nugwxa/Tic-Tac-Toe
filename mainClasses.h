#pragma once

#include <iostream>
#ifndef MAINCLASSES_H
#define MAINCLASSES_H

// Header file code here




class Game {
    char gameBoard[4][4];
public:
    Game(); // Initialise Points
    void showBoard();
    void fillBoard(int row, int column, char mark);
    void CheckBoard();
};


class User {

    std::string name;
    char marker;
public:
    User(char mark);
    void setName(std::string uName);
    void makeMove(Game& gameBoard, int row, int column);
};



// [0, 1, 2, 3]
// [0, 1, 2, 3]
// [0, 1, 2, 3]
// [0, 1, 2, 3]


#endif
