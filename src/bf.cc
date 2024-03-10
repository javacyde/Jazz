#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "inc/groups.h"

using namespace std;

int** matrix;

void init(int s) {
    matrix = new int* [s];
    for (int r = 0; r < s; r++) {
        matrix[r] = new int[s];
        for (int c = 0; c < s; c++)
            matrix[r][c] = 0;
    }
}

void exec(string code) {
    init(256);
    Pair con;    
    int x = 0;
    int y = 0;
    con.vec = npairs(groups(code, "["), groups(code, "]"), code.length());
    if (groups(code, "#").size() % 2) throw length_error("Unclosed comment.");

    for(int idx = 0; idx < code.length(); idx++) {
        switch (code[idx]) {
            case '>':
                x++;
                break;
            case '<':
                x--;
                break;
            case '^':
                y--;
                break;
            case 'v':
                y++;
                break;
            case '.':
                cout << char(matrix[x][y]);
                break;
            case '!':
                cout << matrix[x][y];
                break;
            case ',':
                cin >> matrix[x][y];
                break;
            case '+':
                matrix[x][y]++;
                break;
            case '-':
                matrix[x][y]--;
                break;
            case '[':
                if (!matrix[x][y]) {
                    idx = con.sep(1)[search(con.sep(0), idx)];
                }
                break;
            case ']':
                if (matrix[x][y]) {
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