#include <iostream>
#include <string>
#include "inc/groups.h"
#include "inc/hex.h"
#include "inc/jazz.h"

using namespace std;

int* Executor::pm;
int Executor::flow;

Executor::Executor(int matsize, int stacklength) {
    this -> matsize = matsize;
    this -> matrix = new int*[this->matsize];
    this -> stack = new string[stacklength];
    this -> x = 0;
    this -> y = 0;
    this -> sc = 0;
    this -> idx = 0;

    for (int i = 0; i < stacklength; i++) this -> stack[i] = "";
    for (int r = 0; r < this->matsize; r++) {
        this -> matrix[r] = new int[this->matsize];
        for (int c = 0; c < this->matsize; c++) this -> matrix[r][c] = 0;
    }
}

Executor::~Executor() {
    delete[] stack;
    for (int r = 0; r < this->matsize; r++) {
        delete[] this->matrix[r];
    }
}

void Executor::init() {
    Executor::pm = new int[10];
    Executor::flow = 0;
    for(int i = 0; i < 10; i++) Executor::pm[i] = 0;
}

void Executor::exec(string code) {
    Pair con, proc, num;
    string p = "";
    int t;
    con.vec = npairs(groups(code, "["), groups(code, "]"), code.length());
    proc.vec = npairs(groups(code, "("), groups(code, ")"), code.length());
    num.vec = npairs(groups(code, "{"), groups(code, "}"), code.length());
    if (groups(code, "#").size() % 2 || groups(code, "\"").size() % 2) throw length_error("Unclosed comment/string assignment.");

    while(this->idx < code.length()) {
        switch (code[this->idx]) {
            case '>': (this->x)++; flow = 0; break;
            case '<': (this->x)--; flow = 1; break;
            case '^': (this->y)--; flow = 2; break;
            case 'v': (this->y)++; flow = 3; break;
            case '.': cout << char(*this->curr()); break;
            case '!': cout << *this->curr(); break;
            case ',': cin >> *this->curr(); break;
            case '+': this->matrix[this->x][this->y]++; break;
            case '-': this->matrix[this->x][this->y]--; break;
            case '[': if (!*this->curr()) this->idx = con.sep(1)[search(con.sep(0), this->idx)]; break;
            case ']': if (*this->curr()) this->idx = con.sep(0)[search(con.sep(1), this->idx)]; break;
            case '#': this->idx = search(code, '#', this->idx+1); break;
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': this -> sc = code[this->idx] - 48; break;
            case '(': t = this->idx; p = ""; this->idx++; while (this->idx != proc.sep(1)[search(proc.sep(0), t)]) { p += code[this->idx]; this->idx++; } this->stack[this->sc] = p; break;
            case ':': this->exec(this->stack[this->sc]); break;
            case ';': Executor(64, 10).exec(this -> stack[this -> sc]); break;
            case '{': if (num.sep(1)[search(num.sep(0), this->idx)] != this->idx + 3) throw length_error("Only 2 characters allowed in braces."); *this->curr() = fhex(code[this->idx+1], code[this->idx+2]); this->idx += 3; break;
            case '"': t = search(code, '"', ++this->idx); while (this->idx != t) { *this->curr() = code[this->idx]; this->x++; this->idx++; } this->x--; break;
            case '@': *this->curr() = pm[this->sc]; break;
            case '~': pm[this->sc] = *this->curr(); break;
            case '$': t = pm[this->sc]; this->pm[this->sc] = *this->curr(); *this->curr() = t; break;
            case 'c': *this->curr() = *this->prev(); break;
            case 'x': t = *this->curr(); *this->curr() = *this->prev(); *this->prev() = t; break;
            case 'a': *this->next() = *this->curr() + *this->prev(); break;
            case 'm': *this->next() = *this->curr() * *this->prev(); break;
            case 's': if(*this->curr() > *this->prev()) *this->next() = *this->curr() - *this->prev(); else *this->next() = *this->prev() - *this->curr(); break;
            case 'd': if(*this->curr() > *this->prev()) *this->next() = *this->curr() / *this->prev(); else *this->next() = *this->prev() / *this->curr(); break;
            default: break;
        }
        this->idx++;
    }
}

int* Executor::curr() {
    return &this->matrix[this->x][this->y];
}

int* Executor::prev() {
    switch(flow) {
        case 0: return &this->matrix[this->x-1][this->y]; break;
        case 1: return &this->matrix[this->x+1][this->y]; break;
        case 2: return &this->matrix[this->x][this->y+1]; break;
        case 3: return &this->matrix[this->x][this->y-1]; break;
    }
}

int* Executor::next() {
    switch(flow) {
        case 0: return &this->matrix[this->x+1][this->y]; break;
        case 1: return &this->matrix[this->x-1][this->y]; break;
        case 2: return &this->matrix[this->x][this->y-1]; break;
        case 3: return &this->matrix[this->x][this->y+1]; break;
    }
}
