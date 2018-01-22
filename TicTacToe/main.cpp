/*simple two-player tic-tac-toe game, with the board an instance of the
 the class Square, which is defined in the header file.*/

#include "Header.h"
#include <string>

char player(bool turn);
void printBoard(Square board[][4]);
bool playerWins(Square board[][4], char player);
string input;

int main() {
    Square board[4][4];  //class Square from Header.h
    bool turn = 0; //0 for player x, 1 for player o
    int row;
    int column;
    
    while (true) {
        cout<<"\nPlayer "<<player(turn)<<"'s turn:\n";
        printBoard(board);
        
        //request row and column inputs, test for validity of inputs, repeat if inputs are invalid
        row = -1;
        while (row < 0) {
            cout<<"input a row number (0, 1, 2, or 3) ";
            std::getline (std::cin,input);
            if ((input == "0" || input == "1" || input == "2" || input == "3")){
                row = atoi(input.c_str());
            }
            else {
                cout<<"input must be one of the integers 0, 1, 2, or 3\n";
            }
        }
        column = -1;
        while (column < 0) {
            cout<<"input a column number (0, 1, 2, or 3) ";
            std::getline (std::cin,input);
            if ((input == "0" || input == "1" || input == "2" || input == "3")){
                column = atoi(input.c_str());
            }
            else {
                cout<<"input must be one of the integers 0, 1, 2, or 3\n";
            }
        }
        
        //test to see if a player has won yet, using the function playerWins()
        cout<<"\nplayer "<<player(turn)<<" plays "<<"("<<row<<","<<column<<")";
        board[row][column].setValue(player(turn));
        if (playerWins(board, player(turn)) == true) {
            cout<<"\n\n"<<player(turn)<<" wins!\n\n";
            printBoard(board);
            cout<<"\n";
            break;
        }
        turn = !turn; //switch turns
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









