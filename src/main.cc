#include <fstream>
#include <iostream>
#include "inc/jazz.h"

using namespace std;

ifstream fs;
char b;

int main(int argc, char** argv) {
    string line;
    string code;

    fs.open(argv[1]);
    if (!fs.is_open()) {
        cerr << "Unable to open file: " << argv[1] << ".";
        return 1;
    } else {
        while (getline(fs, line)) {
            code += line;
        }
        fs.close();
    }
    fs.close();

    Executor e = Executor();

    try { 
        e.exec(code);
    } catch (const exception& e) {
        cerr << e.what(); 
        return 1;
    }
    return 0;
}