#ifndef JAZZ
#define JAZZ
#include <string>
#include <vector>

class Executor {
    public: static int* pm;
    int** matrix;
    std::string* stack;
    int x, y, sc, idx, flow;

    public:
        static void init();
        Executor(int matsize = 256, int stacklength = 10);
        void exec(std::string code);

    private:
        int* curr();
        int* prev();
        int* next();
};

#endif