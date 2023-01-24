#include "solver.h"
#include "calculator.h"


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

bool eqVec(vector<char> a, vector<char> b){
    if(a.size() == b.size()){
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]) {
                // cout << "false " << i << " " << (int)a[i] << " " << (int)b[i] << endl;
                return false;
            }
        }
    }

    return true;
}

void solve(vector<vector<char>> &result, vector<char> cards){
    auto start = high_resolution_clock::now();
    int count = 0;

    for(int ix = 1; ix <= 5; ix++){
        for(auto it:getPattern(ix, cards)){
            if(postfixCalculate(it) == 24){
                bool exists = false;
                for(auto cR:result){
                    // if (exists) break;
                    // // cout << (int)cR[0] << (int)it[0] << endl;
                                        // if (eqVec(cR, it)){
                                        //     exists = true;
                                        // } else {
                                        //     for(auto zzz:cR){
                                        //         cout << zzz;
                                        //     } cout << "   "; 

                                        //     for(auto zzzz:it){
                                        //         cout << zzzz;
                                        //     } cout << "THIS" << endl;
                                        // }

                    // cout << exists << endl;
                    // cout << cR.size() << it.size() << endl;
                }

                // for (auto a:it){
                //     bool isOps = false;

                //     for(auto b:ops) {
                //         if (a == b)
                //             isOps = true;
                //     }
                    
                //     if(isOps)
                //         cout << a << " ";
                //     else
                //         cout << (int)a << " ";
                // }
                // showAsPostFix(it);
                showAsInFix(it);
                cout << " good" << endl;

                result.push_back(it);
                count++;

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

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "there are " << count << " solutions. " << result.size() << " vector members." << endl;
    cout << "bruteforcing takes " << duration.count()/1000 << " ms" << endl;
}