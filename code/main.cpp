//
//  main.cpp
//  DND
//
//  Created by Jaiden M. Atwood on 11/24/19.
//  Copyright © 2019 Jaiden M. Atwood. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
//#include <time.h>

#include "Commands.h"

using namespace std;

int GetArraySize(string str) {
    int number_of_spaces = 0;
    for(auto& iter : str) {
        if(iter == ' ') {
            number_of_spaces++;
        }
    }
    number_of_spaces++;
    return number_of_spaces;
}

int main(int argc, const char * argv[]) {
    string input;
    while(1) {
        cout << ">";
        getline(cin, input);
        istringstream ss(input);
        string token;
        int i = 0;
        
        int cmdLength = GetArraySize(input);
        string command[cmdLength];
        
        while(getline(ss, token, ' ')) {
            command[i] = token;
            i++;
        }
        for(i=0; ; i++) {
            if(command[i] == "")
                break;
            /*else
                cout << cmd[i] << endl;*/
        }
        cout << "\n";
        if(RunCommand(command[0]) == 1) {
            return 0;
        }
        cout << "\n";
    }
    //return 0;
}