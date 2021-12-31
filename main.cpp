#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include "Trie.h"
#include "IO.h"

int main() {
    vector<string> in = IO::read("input2.txt");
    auto t = new Trie();
    string i;
    char delimiter1 = '(';
    char delimiter2 = ',';
    char delimiter3 = ')';
    string components;



    for(auto i : in){
        string command;
        command = i.substr(0,i.find(delimiter1));


        if(command == "insert"){ //
            components = i.substr(7, i.size());
            components.erase(remove(components.begin(), components.end(), ')'), components.end());
            vector<vector<string>> insertVectors;
            vector<string> insertVector;
            stringstream ss(components);

            while (ss.good()) {
                string substr;
                getline(ss, substr, ',');
                insertVector.push_back(substr);
            }

            insertVectors.push_back(insertVector);

            for(int i = 0; i < insertVectors.size(); i++){
                string key = insertVectors[i][0];
                string value = insertVectors[i][1];
                t->insert(key,value);
            }






        }

        //-------------------------------------------------------------------

        if(command == "search"){ //
            components = i.substr(7, i.size());
            components.erase(remove(components.begin(), components.end(), ')'), components.end());
            string searchReturn = t->search(components);
            cout << searchReturn << endl;

        }

        //---------------------------------------------

        if(command == "list"){ //

        }

        //-----------------------------------------------

        if(command == "delete"){ //
            string componentDel;
            componentDel = i.substr(7,i.size());
            componentDel.pop_back();
            vector<string> delVector;

            delVector.push_back(componentDel);

            for(int i = 0; i < delVector.size(); i++){
                string key = delVector[i];
                string result = t->deleteWord(key);
                cout << result << endl;
            }





        }

        //-------------------------------------------------------

    }


    return 0;
}
