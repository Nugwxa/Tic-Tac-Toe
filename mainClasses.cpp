#include "mainClasses.h"

// DIVIDE INTO TWO CLASSES

Game::Game() {

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            gameBoard[i][j] = '-';
        }
    }
}

void Game::fillBoard(int row, int column, char mark) {
    gameBoard[row][column] = mark;
}

void Game::showBoard() {
    //Row 1
    std::cout << "[" << gameBoard[0][0] << "," << gameBoard[0][1] << ","
        << gameBoard[0][2] << "," << "" << gameBoard[0][3] << "]" << std::endl;

    //Row 2
    std::cout << "[" << gameBoard[1][0] << "," << gameBoard[1][1] << ","
        << gameBoard[1][2] << "," << "" << gameBoard[1][3] << "]" << std::endl;

    //Row 3
    std::cout << "[" << gameBoard[2][0] << "," << gameBoard[2][1] << ","
        << gameBoard[2][2] << "," << "" << gameBoard[2][3] << "]" << std::endl;

    //Row 4
    std::cout << "[" << gameBoard[3][0] << "," << gameBoard[3][1] << ","
        << gameBoard[3][2] << "," << "" << gameBoard[3][3] << "]" << std::endl;
}

void Game::checkWinner(int xCount, int oCount, bool &xWin, bool &oWin) {
    if (xCount == 4) {
        xWin = true;
    }
    else if (oCount == 4) {
        oWin = true;
    }
}

void Game::checkBoard(bool &xWin, bool &oWin) {
    
    // Check Diagonally
    int x_Count1 = 0, o_Count1 = 0, x_Count2 = 0, o_Count2 = 0;
    for (int i = 0; i < 4; i++) {
        if (gameBoard[i][i] == 'x') {
            x_Count1 += 1;
        }
        else if (gameBoard[i][i] == 'o') {
            o_Count1 += 1;
        }
        if (gameBoard[i][3 - i] == 'x') {
            x_Count2 += 1;
        }
        else if (gameBoard[i][3 - i] == 'o') {
            o_Count2 += 1;
        }
    }
    checkWinner(x_Count1, o_Count1, xWin, oWin);
    checkWinner(x_Count2, o_Count2, xWin, oWin);
    
    if (oWin || xWin) {
        return;
    }

    // Exit if either player has won
    if (oWin || xWin) {
        return;
    }

    // Check Vertically 
    for (int i = 0; i < 4; i++) {
        int x_Count = 0;
        int o_Count = 0;

        for (int j = 0; j < 4; j++) {
            if (gameBoard[j][i] == 'x') {
                x_Count += 1;
            }

            if (gameBoard[j][i] == 'o') {
                o_Count += 1;
            }

            checkWinner(x_Count, o_Count, xWin, oWin);
        }

        
    }

    // Exit if either player has won
    if (oWin || xWin) {
        return;
    }

    // Check horizontaly
    for (int i = 0; i < 4; i++) {
        int x_Count = 0;
        int o_Count = 0;

         
        for (int j = 0; j < 4; j++) {

            if (gameBoard[i][j] == 'x') {
                x_Count += 1;
            }

            if (gameBoard[i][j] == 'o') {
                o_Count += 1;
            }
            checkWinner(x_Count, o_Count, xWin, oWin);
        }

        
    }

    // Exit if either player has won
    if (oWin || xWin) {
        return;
    }

}


User::User(char mark) {
    marker = mark;
}

void User::setName(std::string uName) {
    name = uName;
}

std::string User::getName() {
    return name;
}

void User::makeMove(Game& gameBoard, int row, int column) {
    // Remove 1 from each variable to fit it into the array
    row -= 1;
    column -= 1;
    gameBoard.fillBoard(row, column, marker);
}


// FOR PERSONAL REFERENCE
// [x, -, o, -]
// [-, x, o, o]
// [-, o, x, -]
// [-, -, -, x]

