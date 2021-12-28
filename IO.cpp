#include "IO.h"

vector<string> IO::read(string s) {
    string line;
    fstream ReadFile(s);
    vector<string> out;


    while (getline(ReadFile, line)) {
        // Output the text from the file
        out.push_back(line);
    }

    return out;
}