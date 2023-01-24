#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>
#include <string>
#include <iostream>

#include "deck.h"

using namespace std;

    class Expression{
        vector<string> expr;

        public:
            Expression(vector<string> init);
            int getResult();

            float stringToFloat(string str);

            void SetExpr(vector<string> vec);
            // void SetExprToPattern(int pattern, Deck deck);
            void ShowExpr();
            void ShowExprAsInfix();

            bool Equal(Expression eqTarget);

    };

#endif // !EXPRESSION_H