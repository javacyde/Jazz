#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

vector<size_t> groups(string code, string sub) {
    string substring = sub;
    vector<size_t> positions;
    size_t pos = code.find(substring, 0);

    while (pos != std::string::npos) {
        positions.push_back(pos);
        pos = code.find(substring, pos + 1);
    }

    return positions;
}

int search(vector<size_t> vec, int val) {
    vector<size_t>::iterator it = find(vec.begin(), vec.end(), val);

    if (it != vec.end()) return it - vec.begin();
    else return -1;
}

int searchrev(vector<vector<size_t>> vec, vector<size_t> val) {
    auto it = std::find(vec.rbegin(), vec.rend(), val);

    if (it != vec.rend()) return (it.base() - 1) - vec.begin();
    else return -1;
}

vector<vector<size_t>> npairs(vector<size_t> left, vector<size_t> right, size_t len) {
    vector<size_t> lr;
    vector<vector<size_t>> lt;
    merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(lr));
    vector<size_t> temp(len);
    for (size_t i: lr) {
        if (search(left, i) != -1) {
            lt.push_back({0});
            temp.push_back(i);
        } else {
            int n = searchrev(lt, {0});
            lt[n] = {temp.back(), i};
            temp.pop_back();
        }
    }

    return lt;
}