#include "solver.h"
#include "calculator.h"


static vector<char> ops = {'+', '-', '*', '/'};

vector<vector<char>> getPattern(int patternNum, vector<char> cards){
    vector<vector<char>> res;
    for(auto i:ops){
        for(auto j:ops){
            for(auto k:ops){
                if (patternNum == 1) {
                    res.push_back({cards[3], cards[2], i, cards[1], j, cards[0],  k});
                }
            }
        }
    }

    return res;
}

void solve(vector<vector<char>> &result, vector<char> cards){
    for(auto it:getPattern(1, cards)){
        for (auto a:it){
            bool isOps = false;

        for(auto b:ops) {
            if (a == b)
                isOps = true;
        }
        
        if(isOps)
            cout << a << " ";
        else
            cout << (int)a << " ";
        }

        if(postfixCalculate(it) == 24){
            cout << " good" << endl;
        } else {
            cout << "[" << postfixCalculate(it) << "] wrong" << endl;
        }
    }

    

    // for (auto a:toSolve){
    //         bool isOps = false;

    //     for(auto b:ops) {
    //             if (a == b)
    //                 isOps = true;
    //     }
        
    //     if(isOps)
    //         cout << a << " ";
    //     else
    //         cout << (int)a << " ";
    // }

    // if(postfixCalculate(toSolve) == 24){
    //     cout << " good" << endl;
    // } else {
    //     cout << "[" << postfixCalculate(toSolve) << "] wrong" << endl;
    // }
}