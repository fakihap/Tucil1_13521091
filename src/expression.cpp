#include "expression.h"

Expression::Expression(vector<string> init){
    expr = init;
}

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
    
    if ((numStack[0] - (int)numStack[0]) == 0)
        return (int)numStack[0];
    else
        return 0;
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

string Expression::GetExpr(){
    string result;

    for(auto i:expr){
        result += i + " ";
    } result += "\n";

    return result;
}   

string Expression::GetExprAsInfix(){
    vector<float> numStack;
    vector<string> infixStack;

    for(auto a:expr){
        if(a != "+" && a != "-" && a != "*" && a != "/"){
            numStack.push_back(stringToFloat(a));
            infixStack.push_back(a);
        } else {
            float _temp1 = numStack.back(); numStack.pop_back();
            float _temp2 = numStack.back(); numStack.pop_back();

            string _tempStr1 = infixStack.back(); infixStack.pop_back();
            string _tempStr2 = infixStack.back(); infixStack.pop_back();

            if(a == "+"){
                numStack.push_back(_temp2 + _temp1);
                infixStack.push_back("( " + _tempStr2 + " + " + _tempStr1 + " )");
            } else 
            if (a == "-"){
                numStack.push_back(_temp2 - _temp1);
                infixStack.push_back("( " + _tempStr2 + " - " + _tempStr1 + " )");
            } else
            if (a == "*"){
                numStack.push_back(_temp2 * _temp1);
                infixStack.push_back("( " + _tempStr2 + " * " + _tempStr1 + " )");
            } else
            if (a == "/"){
                numStack.push_back(_temp2 / _temp1);
                infixStack.push_back("( " + _tempStr2 + " / " + _tempStr1 + " )");
            }
        }   
    }   

    return infixStack[0] + "\n";
}

void Expression::ShowExpr(){
    for(auto i:expr){
        cout << i << " ";
    } cout << endl;
}

void Expression::ShowExprAsInfix(){
    vector<float> numStack;
    vector<string> infixStack;

    for(auto a:expr){
        if(a != "+" && a != "-" && a != "*" && a != "/"){
            numStack.push_back(stringToFloat(a));
            infixStack.push_back(a);
        } else {
            float _temp1 = numStack.back(); numStack.pop_back();
            float _temp2 = numStack.back(); numStack.pop_back();

            string _tempStr1 = infixStack.back(); infixStack.pop_back();
            string _tempStr2 = infixStack.back(); infixStack.pop_back();

            if(a == "+"){
                numStack.push_back(_temp2 + _temp1);
                infixStack.push_back("( " + _tempStr2 + " + " + _tempStr1 + " )");
            } else 
            if (a == "-"){
                numStack.push_back(_temp2 - _temp1);
                infixStack.push_back("( " + _tempStr2 + " - " + _tempStr1 + " )");
            } else
            if (a == "*"){
                numStack.push_back(_temp2 * _temp1);
                infixStack.push_back("( " + _tempStr2 + " * " + _tempStr1 + " )");
            } else
            if (a == "/"){
                numStack.push_back(_temp2 / _temp1);
                infixStack.push_back("( " + _tempStr2 + " / " + _tempStr1 + " )");
            }
        }   
    }   

    cout << infixStack[0] << endl;
}

bool Expression::Equal(Expression eqTarget){
    if(expr.size() != eqTarget.expr.size())
        return false;

    for(int i = 0; i < expr.size(); i++){
        if(expr[i] != eqTarget.expr[i]){
            return false;
        }
    }

    return true;
}