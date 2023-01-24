#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <fstream>

#include "expression.h"
#include "deck.h"

#include "time.h"

using namespace std;

    static vector<string> ops = {"+", "-", "*", "/"};

    class cardSolver {
        vector<Expression> solutionExpr;

        Deck deckToSolve;

        public:
            int lastExecutionTime;
            void SetDeck(Deck deck);
            void ShowDeck();

            void GenerateSolution();
            void ClearSolution();
            void SaveSolution();

            void ShowExecutionTime();

            void PushSolution(Expression candidateSolution);

            void ShowSolution();
            void ShowInfixSolution();

            bool IsSolutionContains(vector<Expression> _solutionExpr, Expression _expr);


    };

#endif

