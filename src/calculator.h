#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>
#include <iostream>
#include <string>

using namespace std;

static vector<char> ops = {'+', '-', '*', '/'};

int postfixCalculate(vector<char> vec);

void showAsPostFix(vector<char> val);
void showAsInFix(vector<char> val);

#endif // !CALCULATOR_H