#ifndef GROUPS
#define GROUPS
#include <vector>
#include <string>

std::vector<size_t> groups(std::string code, std::string sub);

int search(std::vector<size_t> vec, int val);

std::vector<std::vector<size_t>> npairs(std::vector<size_t> left, std::vector<size_t> right, size_t len);

#endif