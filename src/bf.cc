#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "inc/groups.h"

using namespace std;

vector<int> matrix(30000, 0);

void exec(string code) {
    Pair con;    
    int cursor = 0;
    con.vec = npairs(groups(code, "["), groups(code, "]"), code.length());
    if (groups(code, "#").size() % 2) throw length_error("Unclosed comment.");

    for(int idx = 0; idx < code.length(); idx++) {
        switch (code[idx]) {
            case '>':
                cursor++;
                break;
            case '<':
                cursor--;
                break;
            case '.':
                cout << char(matrix[cursor]);
                break;
            case ',':
                cin >> matrix[cursor];
                break;
            case '+':
                matrix[cursor]++;
                break;
            case '-':
                matrix[cursor]--;
                break;
            case '[':
                if (!matrix[cursor]) {
                    idx = con.sep(1)[search(con.sep(0), idx)];
                }
                break;
            case ']':
                if (matrix[cursor]) {
                    idx = con.sep(0)[search(con.sep(1), idx)];
                }
                break;
            case '#':
                idx = search(code, '#', idx+1);
                break;
            default: break;
        }
    }
}