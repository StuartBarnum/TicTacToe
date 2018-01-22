/*simple two-player tic-tac-toe game, with the board an instance of the
 the class Square, which is defined in the header file.*/

#include "Header.h"
#include <string>

char player(bool turn);
void printBoard(Square board[][4]);
bool playerWins(Square board[][4], char player);

int main() {
    Square board[4][4];  //class Square from Header.h
    bool turn = 0; //0 for player x, 1 for player o
    int row;
    int column;
    string input;
    
    while (true) {
        cout<<"\nPlayer "<<player(turn)<<"'s turn:\n";
        printBoard(board);
        
        //request and accept row and column inputs, test for validity of inputs,
        //repeat if inputs are invalid
        row = -1;
        while (row < 0) {
            cout<<"input a row number (1, 2, 3, or 4) ";
            std::getline (std::cin,input);
            if ((input == "1" || input == "2" || input == "3" || input == "4")){
                row = atoi(input.c_str()) - 1;
            }
            else {
                cout<<"input must be one of the integers 1, 2, 3, or 4\n";
            }
        }
        column = -1;
        while (column < 0) {
            cout<<"input a column number (1, 2, 3, or 4) ";
            std::getline (std::cin,input);
            if ((input == "1" || input == "2" || input == "3" || input == "4")){
                column = atoi(input.c_str()) - 1;
            }
            else {
                cout<<"input must be one of the integers 1, 2, 3, or 4/n";
            }
        }
        
        /* if the (row, column) position has not yet been played, adjust the table accordingly and
         then switch turns, to the other player. otherwise, request another try from the same player */
        
        if (board[row][column].getValue() == '@') {
            //test to see if a player has won yet, using the function playerWins()
            cout<<"\nplayer "<<player(turn)<<" plays "<<"("<<row + 1<<","<<column + 1<<")";
            board[row][column].setValue(player(turn));
            if (playerWins(board, player(turn)) == true) {
                cout<<"\n\n"<<player(turn)<<" wins!\n\n";
                printBoard(board);
                cout<<"\n";
                break;
            }
            turn = !turn; //switch turns
        }
        else {
            cout<<"\ntry again--position ("<<row + 1<<", "<<column + 1<<") has already been played";
        }
    }
        return 0;
}

//set correspondence between 'x' and 'o' and boolean values
char player (bool turn) {
    if (turn == 0) {
        return 'x';
    }
    else {
        return 'o';
    }
}
void printBoard(Square board[][4]) {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cout<<board[i][j].getValue()<<" ";
        }
        cout<<"\n";
    }
}

//test for a win, by initially assuming that there is a win and then looking
//for counterexamples
bool playerWins(Square board[][4], char player) {
    for (int i=0; i<4; i++) {
        bool wins = true;
        for (int j=0; j<4; j++) {
            if (board[i][j].getValue() != player) {
                wins = false;
            }
        }
        if (wins == true) {return true;}    //return true if counterexample not found
    }
    for (int i=0; i<4; i++) {
        bool wins = true;
        for (int j=0; j<4; j++) {
            if (board[j][i].getValue() != player) {
                wins = false;
            }
        }
        if (wins == true) {return true;}    //return true if counterexample not found
    }
    bool wins = true;
    for (int i=0; i<4; i++) {
        if (board[i][i].getValue() != player) {
            wins = false;
        }
    }
    if (wins == true) {return true;}        //return true if counterexample not found
    
    wins = true;
    for (int i=0; i<4; i++) {
        if (board[i][3-i].getValue() != player) {
            wins = false;
        }
    }
    if (wins == true) {return true;}        //return true if counterexample not found
    
    return false;
}









