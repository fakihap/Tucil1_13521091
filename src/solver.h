#ifndef SOLVER_H
#define SOLVER_H

#include <vector>

#include <chrono>

#include "expression.h"
#include "deck.h"

using namespace std;
using namespace std::chrono;

    // vector<vector<char>> getPattern(int patternNum, vector<char> cards);

    // void solve(vector<vector<char>> &result, vector<char> cards);
    static vector<string> ops = {"+", "-", "*", "/"};

    class cardSolver {
        vector<Expression> solutionExpr;

        Deck deckToSolve;

        public:
            void SetDeck(Deck deck);
            void ShowDeck();

            void GenerateSolution();

            void PushSolution(Expression candidateSolution);

            void ShowSolution();
            void ShowInfixSolution();

            // should be static
            bool IsSolutionContains(vector<Expression> _solutionExpr, Expression _expr);


    };

#endif

