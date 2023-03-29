#pragma once

#include <iostream>
#ifndef MAINCLASSES_H
#define MAINCLASSES_H

class Game {
    char gameBoard[4][4];
public:
    Game(); // Initialise Points
    void showBoard();
    void fillBoard(int row, int column, char mark);
    void checkWinner(int xCount, int oCount, bool &xWin, bool &oWin);
    void checkBoard(bool& xWin, bool& oWin);
    
};


class User {

    std::string name;
    char marker;
public:
    User(char mark);
    void setName(std::string uName);
    std::string getName();
    void makeMove(Game& gameBoard, int row, int column);
};

#endif
