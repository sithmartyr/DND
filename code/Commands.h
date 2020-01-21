//
//  Commands.h
//  DND
//
//  Created by Jaiden M. Atwood on 11/24/19.
//  Copyright © 2019 Jaiden M. Atwood. All rights reserved.
//

#ifndef Commands_h
#define Commands_h


#endif /* Commands_h */

#include <time.h>
#include <fstream>
//#include <curses.h>

using namespace std;

int d4() {
    srand(time(0));
    return rand() % 4 + 1;;
}
int d6() {
    srand(time(0));
    return rand() % 6 + 1;
}
int d8() {
    srand(time(0));
    return rand() % 8 + 1;
}
int d10() {
    srand(time(0));
    return rand() % 10;
}
int d12() {
    srand(time(0));
    return rand() % 12 + 1;
}
int d20() {
    srand(time(0));
    return rand() % 20 + 1;
}
int d100() {
    srand(time(0));
    return rand() % 100;
}
void testFileInput() {
    ifstream inFile;
    string val;
    
    inFile.open("Data.txt");
    inFile >> val;
    cout << val << endl;
    inFile.close();
}
void create() {
    
}

int RunCommand(string cmd) {
    if(cmd == "d4" || cmd == "D4") {
        cout << d4() << endl;
    }
    else if(cmd == "d6" || cmd == "D6") {
        cout << d6() << endl;
    }
    else if(cmd == "d8" || cmd == "D8") {
        cout << d8() << endl;
    }
    else if(cmd == "d10" || cmd == "D10") {
        cout << d10() << endl;
    }
    else if(cmd == "d12" || cmd == "D12") {
        cout << d12() << endl;
    }
    else if(cmd == "d20" || cmd == "D20") {
        cout << d20() << endl;
    }
    else if(cmd == "d100" || cmd == "D100") {
        cout << d100() << endl;
    }
    else if(cmd == "testFileInput") {
        testFileInput();
    }
    /*else if(cmd == "clear" || cmd == "Clear" || cmd == "CLEAR" || cmd == "cls" || cmd == "Cls" || cmd == "CLS") {
        clear();
    }*/
    else if(cmd == "exit" || cmd == "Exit" || cmd == "EXIT") {
        return 1;
    }
    else {
        cout << "Unknown command" << endl;
    }
    return 0;
}
