#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "inc/groups.h"

using namespace std;

vector<int> matrix(30000, 0);

void exec(string code) {
    vector<vector<size_t>> con = npairs(groups(code, "["), groups(code, "]"), code.length());
    vector<size_t> left, right;
    int cursor = 0;

    for (vector<size_t> p: con) { 
        left.push_back(p[0]);
        right.push_back(p[1]);
    }

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
                    idx = right[search(left, idx)];
                }
                break;
            case ']':
                if (matrix[cursor]) {
                    idx = left[search(right, idx)];
                }
                break;
            default: break;
        }
    }
}