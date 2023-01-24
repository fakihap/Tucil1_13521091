#include "solver.h"

void cardSolver::SetDeck(Deck deck){
    deckToSolve = deck;
}

void cardSolver::ShowDeck(){
    deckToSolve.DisplayDeck();
}

void cardSolver::GenerateSolution(){
    ClearSolution();

    clock_t startTime, endTime;
    startTime = clock();

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

    endTime = clock();

    lastExecutionTime = double(endTime - startTime) / double(CLOCKS_PER_SEC) * 1000;

    
}

void cardSolver::ClearSolution(){
    solutionExpr.clear();
}

void cardSolver::SaveSolution(){
    string path = "../test/Solution_" + to_string(time(0)) + ".txt";

    ofstream SolutionFile(path);

    for(auto i:solutionExpr){
        SolutionFile << i.GetExprAsInfix();
    }

    SolutionFile.close();

    cout << "Solutions saved as " + path << endl;
}

void cardSolver::ShowExecutionTime(){
    cout << "Execution time : " << lastExecutionTime << " ms" << endl << endl;
}

void cardSolver::PushSolution(Expression candidateSolution){
    if(!IsSolutionContains(solutionExpr, candidateSolution) && candidateSolution.getResult() == 24){
        solutionExpr.push_back(candidateSolution);
    }
}

void cardSolver::ShowSolution(){
    cout << endl;
    if(solutionExpr.size() == 0)
        cout << "solutionExpr is empty" << endl;
    else
        cout << "There are " << solutionExpr.size() << " solutions." << endl;
    
    for(auto i:solutionExpr){
        i.ShowExpr();
    }
    cout << endl << endl;
}

void cardSolver::ShowInfixSolution(){
    cout << endl;
    if(solutionExpr.size() == 0)
        cout << "solutionExpr is empty" << endl;
    else
        cout << "There are " << solutionExpr.size() << " solutions." << endl;

    for(auto i:solutionExpr){
        i.ShowExprAsInfix();
    }
    cout << endl << endl;
}

bool cardSolver::IsSolutionContains(vector<Expression> _solutionExpr, Expression _expr){
    for(auto i:_solutionExpr){
        if(i.Equal(_expr))
            return true;
    }

    return false;
}