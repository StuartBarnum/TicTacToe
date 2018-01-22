
#include "Header.h"

char player(bool turn);
void printBoard(Square board[][4]);
bool playerWins(Square board[][4], char player);

int main() {
    Square board[4][4];
    bool turn = 0; //0 for player x, 1 for player o
    int row = -1;
    int column = -1;
    
    while (true) {
        cout<<"\nPlayer "<<player(turn)<<"'s turn:\n";
        printBoard(board);
        cout<<"input a row number ";
        cin>>row;
        cout<<"\ninput a column number ";
        cin>>column;
        cout<<"\nplayer "<<player(turn)<<" plays "<<"("<<row<<","<<column<<")";
        board[row][column].setValue(player(turn));
        if (playerWins(board, player(turn)) == true) {
            cout<<"\n\n"<<player(turn)<<" wins!\n\n";
            printBoard(board);
            cout<<"\n";
            break;
        }
        turn = !turn;
    }
    return 0;
}
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
bool playerWins(Square board[][4], char player) {
    for (int i=0; i<4; i++) {
        bool wins = true;
        for (int j=0; j<4; j++) {
            if (board[i][j].getValue() != player) {
                wins = false;
            }
        }
        if (wins == true) {return true;}
    }
    for (int i=0; i<4; i++) {
        bool wins = true;
        for (int j=0; j<4; j++) {
            if (board[j][i].getValue() != player) {
                wins = false;
            }
        }
        if (wins == true) {return true;}
    }
    bool wins = true;
    for (int i=0; i<4; i++) {
        if (board[i][i].getValue() != player) {
            wins = false;
        }
    }
    if (wins == true) {return true;}
    
    wins = true;
    for (int i=0; i<4; i++) {
        if (board[i][3-i].getValue() != player) {
            wins = false;
        }
    }
    if (wins == true) {return true;}
    
    return false;
}









