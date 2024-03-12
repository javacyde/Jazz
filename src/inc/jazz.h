#ifndef JAZZ
#define JAZZ
#include <string>

class Executor {
    int** matrix;
    std::string* stack;
    int x, y, sc;

    public: 
        Executor(int matsize = 256, int stacklength = 10);
        void exec(std::string code);
};

#endif