#ifndef GROUPS
#define GROUPS
#include <vector>
#include <string>

struct Pair {
    std::vector<std::vector<size_t>> vec;
    std::vector<size_t> sep(int idx);
};

std::vector<size_t> groups(std::string code, std::string sub);

int search(std::vector<size_t> vec, int val);

int search(std::string str, char val, int start=0);

std::vector<std::vector<size_t>> npairs(std::vector<size_t> left, std::vector<size_t> right, size_t len);

#endif