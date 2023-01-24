#include "expression.h"

int Expression::getResult(){
    vector<float> numStack;

    for(auto a:expr){
        if(a != "+" && a != "-" && a != "*" && a != "/"){
            numStack.push_back(stringToFloat(a));
        } else {
            float _temp1 = numStack.back(); numStack.pop_back();
            float _temp2 = numStack.back(); numStack.pop_back();

            if(a == "+"){
                numStack.push_back(_temp2 + _temp1);
            } else 
            if (a == "-"){
                numStack.push_back(_temp2 - _temp1);
            } else
            if (a == "*"){
                numStack.push_back(_temp2 * _temp1);
            } else
            if (a == "/"){
                numStack.push_back(_temp2 / _temp1);
            }
        }   
    }

    if (numStack.size() != 1)
        cout << "EXPRESSION : WARNING numStack has more than 1 member";

    return numStack[0];
}

float Expression::stringToFloat(string str){
    for(int i = 1; i <= 13; i++){
        if(to_string(i) == str){
            return (float) i;
        }
    }
}

void Expression::SetExpr(vector<string> vec){
    expr = vec;
}

void Expression::ShowExpr(){
    for(auto i:expr){
        cout << i << " ";
    } cout << endl;
}