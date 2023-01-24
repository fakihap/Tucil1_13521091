#ifndef SOLVER_H
#define SOLVER_H

#include <vector>

#include <chrono>

using namespace std;
using namespace std::chrono;

    vector<vector<char>> getPattern(int patternNum, vector<char> cards);

    void solve(vector<vector<char>> &result, vector<char> cards);

#endif

