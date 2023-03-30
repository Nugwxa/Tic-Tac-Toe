#include "mainClasses.h"

// NEXT: Error Handling

/*
* 
* KNOWN BUGS
* Player can play a move that has already been played;
* Game breaks if player doesn't enter their move correctly;
* 
*/


int main() {
    Game gameBoard;

    User player1('x');
    User player2('o');

    std::string name;

    // Get Player1's Details
    std::cout<<"<Player 1> Enter your name: ";
    std::cin >> name;
    player1.setName(name);

    // Get Player2's Details
    std::cout << "<Player 2> Enter your name: ";
    std::cin >> name;
    player2.setName(name);

    // Clear screen
    system("cls");

    std::cout << "Welcome " << player1.getName() << " & " << player2.getName() << std::endl;
    //std::string temp;
    std::cout << "Press Enter to start" << std::endl;
    std::cin.ignore();
    std::cin.get();

    bool player1Won = false;
    bool player2Won = false;

    int rounds = 1;
    // Game Loop
    while (!player1Won && !player2Won) {
        system("cls");
        gameBoard.showBoard();

        int row;
        int column;

        // Player 1's turn;
        std::cout << player1.getName() <<"\n's turn" <<std::endl;
        std::cout << "Enter row and column you want to make move.\ne.g. to fill the first row/column enter: 1 1" << std::endl;
        // Prompt player to enter move and validate it.
        while (true) {
            std::cout << "Enter Move: ";
            std::cin >> row >> column;

            if (std::cin.fail()) {
                std::cout << "Invalid point. Please enter a valid point." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                break;
            }
        }
        player1.makeMove(gameBoard, row, column);

        gameBoard.checkBoard(player1Won, player2Won);

        if (player1Won || player2Won) {
            break;
        }



        system("cls");

        gameBoard.showBoard();

        //Player 2's turn;
        std::cout << player2.getName() << "\n's turn" << std::endl;
        std::cout << "Enter row and column you want to make move.\ne.g. to fill the first row/column enter: 1 1" << std::endl;
        
        //Prompt player to enter move and validate it.
        while (true) {
            std::cout << "Enter Move: ";
            std::cin >> row >> column;

            if (std::cin.fail()) {
                std::cout << "Invalid point. Please enter a valid point." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                break;
            }
        }
        player2.makeMove(gameBoard, row, column);

        gameBoard.checkBoard(player1Won, player2Won);

        if (rounds == 8) {
            break;
        }
        rounds++;

    }
    
    if (player1Won) {
        std::cout << player1.getName()<< " Won!" << std::endl;
    }
    else if (player2Won) {
        std::cout << player2.getName() << " Won!" << std::endl;
    }
    else {
        std::cout << "Nobody Won :(" << std::endl;
    }
}
