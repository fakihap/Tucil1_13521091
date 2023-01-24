#include "solver.h"
// #include "calculator.h"


// vector<vector<char>> getPattern(int patternNum, vector<char> cards){
//     vector<vector<char>> res;

//     for(int ia = 0; ia < 4; ia++){
//         for(int ib = 0; ib < 4; ib++){
//             if(ia == ib)
//                 continue;
//             for(int ic = 0; ic < 4; ic++){
//                 if(ia == ic || ib == ic)
//                     continue;
//                 for(int id = 0; id < 4; id++){
//                     if(ia == id || ib == id || ic == id)
//                         continue;

//                     for(auto i:ops){
//                         for(auto j:ops){
//                             for(auto k:ops){
//                                 if (patternNum == 1) {
//                                     res.push_back({deck.cardDeck[di].asString(), deck[dj], i, deck.asString().cardDeck[dk], j, deck.cardDeck[dl].asString(), k});
//                                 } else if (patternNum == 2) {
//                                     res.push_back({deck.cardDeck[di].asString(), deck[dj], deck.ca.asString()rdDeck[dk], i, j, deck.cardDeck[dl].asString(), k});
//                                 } else if (patternNum == 3) {
//                                     res.push_back({deck.cardDeck[di].asString(), deck[dj], deck.ca.asString()rdDeck[dk], i, deck.cardDeck[dl].asString(), j, k});
//                                 } else if (patternNum == 4) {
//                                     res.push_back({deck.cardDeck[di].asString(), deck[dj], deck.ca.asString()rdDeck[dk], deck.cardDeck[dl].asString(), i, j, k});
//                                 } else if (patternNum == 5) {
//                                     res.push_back({deck.cardDeck[di].asString(), deck[dj], i, deck.asString().cardDeck[dk], deck.cardDeck[dl].asString(), j, k});
//                                 }
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }
    
//     return res;
// }

// bool eqVec(vector<char> a, vector<char> b){
//     if(a.size() == b.size()){
//         for(int i = 0; i < a.size(); i++){
//             if(a[i] != b[i]) {
//                 // cout << "false " << i << " " << (int)a[i] << " " << (int)b[i] << endl;
//                 return false;
//             }
//         }
//     }

//     return true;
// }

// void solve(vector<vector<char>> &result, vector<char> cards){
//     auto start = high_resolution_clock::now();
//     int count = 0;

//     for(int ix = 1; ix <= 5; ix++){
//         for(auto it:getPattern(ix, cards)){
//             if(postfixCalculate(it) == 24){
//                 bool exists = false;
//                 for(auto cR:result){
//                     // if (exists) break;
//                     // // cout << (int)cR[0] << (int)it[0] << endl;
//                                         // if (eqVec(cR, it)){
//                                         //     exists = true;
//                                         // } else {
//                                         //     for(auto zzz:cR){
//                                         //         cout << zzz;
//                                         //     } cout << "   "; 

//                                         //     for(auto zzzz:it){
//                                         //         cout << zzzz;
//                                         //     } cout << "THIS" << endl;
//                                         // }

//                     // cout << exists << endl;
//                     // cout << cR.size() << it.size() << endl;
//                 }

//                 // for (auto a:it){
//                 //     bool isOps = false;

//                 //     for(auto b:ops) {
//                 //         if (a == b)
//                 //             isOps = true;
//                 //     }
                    
//                 //     if(isOps)
//                 //         cout << a << " ";
//                 //     else
//                 //         cout << (int)a << " ";
//                 // }
//                 // showAsPostFix(it);
//                 showAsInFix(it);
//                 cout << " good" << endl;

//                 result.push_back(it);
//                 count++;

//             } else {
//                 // cout << "[" << postfixCalculate(it) << "] wrong" << endl;
//             }
//         }
//     }

    

//     // for (auto a:toSolve){
//     //         bool isOps = false;

//     //     for(auto b:ops) {
//     //             if (a == b)
//     //                 isOps = true;
//     //     }
        
//     //     if(isOps)
//     //         cout << a << " ";
//     //     else
//     //         cout << (int)a << " ";
//     // }

//     // if(postfixCalculate(toSolve) == 24){
//     //     cout << " good" << endl;
//     // } else {
//     //     cout << "[" << postfixCalculate(toSolve) << "] wrong" << endl;
//     // }

//     auto stop = high_resolution_clock::now();

//     auto duration = duration_cast<microseconds>(stop - start);

//     cout << "there are " << count << " solutions. " << result.size() << " vector members." << endl;
//     cout << "bruteforcing takes " << duration.count()/1000 << " ms" << endl;
// }


void cardSolver::SetDeck(Deck deck){
    deckToSolve = deck;
}

void cardSolver::ShowDeck(){
    deckToSolve.DisplayDeck();
}

void cardSolver::GenerateSolution(){
    time_t startTime, endTime;
    time(&startTime);

    for(int di = 0; di < 4; di++){
        for(int dj = 0; dj < 4; dj++){
            if(dj == di)
                continue;

            for(int dk = 0; dk < 4; dk++){
                if(dk == dj || dk == di)
                    continue;
                
                for(int dl = 0; dl < 4; dl++){
                    if(dl == di || dl == dj || dl == dk)
                        continue;

                    // cout << di << dj << dk << dl << endl;

                    for(auto i:ops) {
                        for(auto j:ops){
                            for(auto k:ops){
                                PushSolution(Expression({deckToSolve.cardDeck[di].asString(), deckToSolve.cardDeck[dj].asString(), i, deckToSolve.cardDeck[dk].asString(), j, deckToSolve.cardDeck[dl].asString(), k}));
                                PushSolution(Expression({deckToSolve.cardDeck[di].asString(), deckToSolve.cardDeck[dj].asString(), deckToSolve.cardDeck[dk].asString(), i, j, deckToSolve.cardDeck[dl].asString(), k}));
                                PushSolution(Expression({deckToSolve.cardDeck[di].asString(), deckToSolve.cardDeck[dj].asString(), deckToSolve.cardDeck[dk].asString(), i, deckToSolve.cardDeck[dl].asString(), j, k}));
                                PushSolution(Expression({deckToSolve.cardDeck[di].asString(), deckToSolve.cardDeck[dj].asString(), deckToSolve.cardDeck[dk].asString(), deckToSolve.cardDeck[dl].asString(), i, j, k}));
                                PushSolution(Expression({deckToSolve.cardDeck[di].asString(), deckToSolve.cardDeck[dj].asString(), i, deckToSolve.cardDeck[dk].asString(), deckToSolve.cardDeck[dl].asString(), j, k}));   
                            }
                        }
                    }

                }
            }
        }
    }    

    time(&endTime);

    cout << "Execution time : " << (long)(endTime - startTime) << " ms" << endl;
}

void cardSolver::PushSolution(Expression candidateSolution){
    if(!IsSolutionContains(solutionExpr, candidateSolution) && candidateSolution.getResult() == 24){
        solutionExpr.push_back(candidateSolution);
    }
}

void cardSolver::ShowSolution(){
    if(solutionExpr.size() == 0)
        cout << "solutionExpr is empty" << endl;
    else
        cout << "There are " << solutionExpr.size() << " solutions." << endl;
    
    for(auto i:solutionExpr){
        i.ShowExpr();
    }
}

void cardSolver::ShowInfixSolution(){
    if(solutionExpr.size() == 0)
        cout << "solutionExpr is empty" << endl;
    else
        cout << "There are " << solutionExpr.size() << " solutions." << endl;

    for(auto i:solutionExpr){
        i.ShowExprAsInfix();
    }
}

bool cardSolver::IsSolutionContains(vector<Expression> _solutionExpr, Expression _expr){
    for(auto i:_solutionExpr){
        if(i.Equal(_expr))
            return true;
    }

    return false;
}