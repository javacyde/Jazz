#include <iostream>
#include <string>
#include "inc/groups.h"
#include "inc/hex.h"
#include "inc/jazz.h"

using namespace std;

Executor::Executor(int matsize, int stacklength) {
    this -> matrix = new int*[matsize];
    this -> stack = new string[stacklength];
    this -> x = 0;
    this -> y = 0;
    this -> sc = 0;

    for (int i = 0; i < stacklength; i++) this -> stack[i] = "";
        for (int r = 0; r < matsize; r++) {
        this -> matrix[r] = new int[matsize];
        for (int c = 0; c < matsize; c++) this -> matrix[r][c] = 0;
    }
}

void Executor::exec(string code) {
    Pair con, proc, num;
    string p = "";
    int t;
    con.vec = npairs(groups(code, "["), groups(code, "]"), code.length());
    proc.vec = npairs(groups(code, "("), groups(code, ")"), code.length());
    num.vec = npairs(groups(code, "{"), groups(code, "}"), code.length());
    if (groups(code, "#").size() % 2 || groups(code, "\"").size() % 2) throw length_error("Unclosed comment.");

    for(int idx = 0; idx < code.length(); idx++) {
        switch (code[idx]) {
            case '>': this -> x++; break;
            case '<': this -> x--; break;
            case '^': this -> y--; break;
            case 'v': this -> y++; break;
            case '.': cout << char(this -> matrix[this -> x][this -> y]); break;
            case '!': cout << this -> matrix[this -> x][this -> y]; break;
            case ',': cin >> this -> matrix[this -> x][this -> y]; break;
            case '+': this -> matrix[this -> x][this -> y]++; break;
            case '-': this -> matrix[this -> x][this -> y]--; break;
            case '[': if (!this -> matrix[this -> x][this -> y]) idx = con.sep(1)[search(con.sep(0), idx)]; break;
            case ']': if (this -> matrix[this -> x][this -> y]) idx = con.sep(0)[search(con.sep(1), idx)]; break;
            case '#': idx = search(code, '#', idx+1); break;
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': this -> sc = code[idx] - 48; break;
            case '(': t = idx; p = ""; idx++; while (idx != proc.sep(1)[search(proc.sep(0), t)]) { p += code[idx]; idx++; } this->stack[this->sc] = p; break;
            case ':': this->exec(this->stack[this->sc]); break;
            case ';': Executor(64, 10).exec(this -> stack[this -> sc]); break;
            case '{': if (num.sep(1)[search(num.sep(0), idx)] != idx + 3) throw length_error("More than 2 characters in braces."); this->matrix[this->x][this->y] = fhex(code[idx+1], code[idx+2]); idx += 3; break;
            case '"':
                t = search(code, '"', ++idx);
                while (idx != t) {
                    this->matrix[this->x][this->y] = code[idx];
                    this->x++;
                    idx++;
                }
                this->x--;
                break;
            default: break;
        }
    }
}
