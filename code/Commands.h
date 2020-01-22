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

#define NUM_STATS 9
string STATS[NUM_STATS] = {
    "NAME",
    "STRENGTH",
    "DEXTERITY",
    "CONSTITUTION",
    "INTELLIGENCE",
    "WISDOM",
    "CHARISMA",
    "INITIATIVE",
    "ARMOR CLASS"
};

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
void getStats(string name) {
    int i=0;
    ifstream inFile;
    string val, fileName = name + ".txt";
    inFile.open(fileName);
    if(!inFile) {
        cout << "Character not found" << endl;
        return;
    }
    inFile >> val;
    while(inFile) {
        if(i == 7) {
            cout << STATS[i] << ": +" << val << endl;
        }
        else {
            cout << STATS[i] << ": " << val << endl;
        }
        inFile >> val;
        i++;
    }
    inFile.close();
}
void create(string name) {
    ofstream outFile;
    string fileName = name + ".txt";
    int val;/*str, dex, cons, intel, wisd, cha, init, ac;*/
    outFile.open(fileName);
    outFile << name << endl;
    for(int i=1; i <= (NUM_STATS-1); i++) {
        cout << STATS[i] << ": ";
        cin >> val;
        outFile << val << endl;
    }
    outFile.close();
    cin.ignore(1);
}


int RunCommand(string cmd, string arg1, int argc) {
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
    else if(cmd == "get" || cmd == "Get" || cmd == "GET") {
        if(argc < 2)
            cout << "Usage: get <Character Name>" << endl;
        else {
            getStats(arg1);
        }
    }
    else if(cmd == "create" || cmd == "Create" || cmd == "CREATE") {
        if(argc < 2)
            cout << "Usage: create <Character Name>" << endl;
        else {
            create(arg1);
            return 0;
        }
    }
    /*else if(cmd == "clear" || cmd == "Clear" || cmd == "CLEAR" || cmd == "cls" || cmd == "Cls" || cmd == "CLS") {
        clear();
    }*/
    else if(cmd == "exit" || cmd == "Exit" || cmd == "EXIT") {
        return 1;
    }
    else if(cmd == "" || cmd == " ") {
        return 0;
    }
    else {
        cout << "Unknown command: " << cmd << endl;
    }
    return 0;
}
