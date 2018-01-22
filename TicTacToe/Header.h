//
//  ticTacToeClasses.h
//  udacityTicTacToe
//
//  Created by Stuart Barnum on 11/5/17.
//  Copyright © 2017 Stuart Barnum. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

class Square {
    char value;
public:
    Square();
    void setValue(char play);
    char getValue();
};

Square::Square() {
    value = '@';
}
void Square::setValue(char play) {
    value = play;
}
char Square::getValue() {
    return value;
}


