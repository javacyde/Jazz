#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> matrix(30000, 0);

void exec(string code) {
    int cursor = 0;
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
            //case '[':
            //    cursor++;
            //    break;
            //case ']':
            //    cursor++;
            //    break;
            default: break;
        }
    }
}

int main() {
    exec("++++++++++++++++++++++++++++++++++++++++++++++++++++++.");
    return 0;
}