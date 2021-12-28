#include <iostream>
using namespace std;

#include "Trie.h"
#include "IO.h"

int main() {
    vector<string> in = IO::read("input1.txt");
    auto t = new Trie();
    string command;

    for(auto i : in){
        command = i.substr(0,6);
        cout << command << endl;
        if(command == "insert"){ //

        }

        if(command == "search"){ //

        }

        if(command == "list"){ //

        }

        if(command == "delete"){ //

        }

    }

    return 0;
}
