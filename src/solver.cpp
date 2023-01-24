#include "solver.h"
#include "calculator.h"


static vector<char> ops = {'+', '-', '*', '/'};

vector<vector<char>> getPattern(int patternNum, vector<char> cards){
    vector<vector<char>> res;

    for(int ia = 0; ia < 4; ia++){
        for(int ib = 0; ib < 4; ib++){
            if(ia == ib)
                continue;
            for(int ic = 0; ic < 4; ic++){
                if(ia == ic || ib == ic)
                    continue;
                for(int id = 0; id < 4; id++){
                    if(ia == id || ib == id || ic == id)
                        continue;

                    for(auto i:ops){
                        for(auto j:ops){
                            for(auto k:ops){
                                if (patternNum == 1) {
                                    res.push_back({cards[ia], cards[ib], i, cards[ic], j, cards[id], k});
                                } else if (patternNum == 2) {
                                    res.push_back({cards[ia], cards[ib], cards[ic], i, j, cards[id], k});
                                } else if (patternNum == 3) {
                                    res.push_back({cards[ia], cards[ib], cards[ic], i, cards[id], j, k});
                                } else if (patternNum == 4) {
                                    res.push_back({cards[ia], cards[ib], cards[ic], cards[id], i, j, k});
                                } else if (patternNum == 5) {
                                    res.push_back({cards[ia], cards[ib], i, cards[ic], cards[id], j, k});
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    return res;
}

void solve(vector<vector<char>> &result, vector<char> cards){
    for(int ix = 1; ix <= 5; ix++){
        for(auto it:getPattern(ix, cards)){
            if(postfixCalculate(it) == 24){
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
                cout << " good" << endl;
            } else {
                // cout << "[" << postfixCalculate(it) << "] wrong" << endl;
            }
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