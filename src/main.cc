#include <fstream>
#include <iostream>
#include "inc/bf.h"

using namespace std;

ifstream fs;
char b;


int main(int argc, char** argv) {
    string line;
    string code;

    fs.open(argv[1]);
    if (!fs.is_open()) cerr << "Unable to open file. " << argv[1]; return 1;
    if (fs.is_open()) {
        while (getline(fs, line)) {
            code += line;
        }
        fs.close();
    }
    fs.close();

    exec(code);
    return 0;
}