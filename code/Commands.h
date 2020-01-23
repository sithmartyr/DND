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

#define NUM_COMMANDS 10
string COMMANDS[NUM_COMMANDS] = {
    "D4 - Roll a random value between 1 and 4",
    "D6 - Roll a random value between 1 and 6",
    "D8 - Roll a random value between 1 and 8",
    "D10 - Roll a random value between 1 and 10",
    "D12 - Roll a random value between 1 and 12",
    "D20 - Roll a random value between 1 and 20",
    "D100 - Roll a random value between 1 and 100",
    "GET - Get the stats for a specified character",
    "CREATE - Create a new character",
    "HELP - Show this help prompt"
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
void get(string name) {
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
void help() {
    for(int i=0; i <= NUM_COMMANDS; i++) {
        cout << COMMANDS[i] << endl;
    }
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
            get(arg1);
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
    else if(cmd == "help" || cmd == "Help" || cmd == "HELP") {
        help();
    }
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
