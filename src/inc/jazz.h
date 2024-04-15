#ifndef JAZZ
#define JAZZ
#include <string>
#include <vector>

class Executor {
    static int *pm, flow;
    int** matrix;
    std::string* stack;
    int x, y, sc, idx, matsize;

    public:
        static void init();
        Executor(int matsize = 256, int stacklength = 10);
        ~Executor();
        void exec(std::string code);

    private:
        int* curr();
        int* prev();
        int* next();
};

#endif