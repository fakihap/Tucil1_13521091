#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

    class Expression{
        vector<string> expr;

        public:
            int getResult();

            float stringToFloat(string str);

            void SetExpr(vector<string> vec);
            void ShowExpr();

    };

#endif // !EXPRESSION_H