#include "calculator.h"


int postfixCalculate(vector<char> vec) {
    vector<float> result;

    vec.shrink_to_fit();

    // cout << endl << "size is" << vec.size() << endl;

    for(auto a:vec){
        // printf("%c +", a);
        if(a != '+' && a != '-' && a != '*' && a != '/'){
            result.push_back((float) a);
        } else {
            float _temp1 = result.back(); result.pop_back();
            float _temp2 = result.back(); result.pop_back();

            if(a == '+'){
                result.push_back(_temp2 + _temp1);
            } else 
            if (a == '-')
            {
                result.push_back(_temp2 - _temp1);
            } else
            if (a == '*') {
                result.push_back(_temp2 * _temp1);
            } else
            if (a == '/'){
                result.push_back(_temp2 / _temp1);
            }
        }
    }

    result.shrink_to_fit();
    // cout << "hasilnya adalah " << result[0] << endl;

    if (result.size() != 1)
        cout << "Calculator : WARNING, result vect has more than 1 member : " << result.size() << endl;

    return result[0];
}

void showAsPostFix(vector<char> val){
    bool isOps;

    for (auto a:val){
        isOps = false;
        for(auto b:ops) {
            if (a == b)
                isOps = true;
        }
        
        if(isOps)
            cout << a << " ";
        else
            cout << (int)a << " ";
    }
}

void showAsInFix(vector<char> val){
    vector<int> numVec;
    vector<string> strVec;
    // string resString;

    for(auto a:val){
        // printf("%c +", a);
        if(a != '+' && a != '-' && a != '*' && a != '/'){
            numVec.push_back((int) a);
            strVec.push_back(to_string((int) a));
        } else {
            float _temp1 = numVec.back(); numVec.pop_back();
            float _temp2 = numVec.back(); numVec.pop_back();

            string _tempStr1 = strVec.back(); strVec.pop_back();
            string _tempStr2 = strVec.back(); strVec.pop_back();


            if(a == '+'){
                numVec.push_back(_temp2 + _temp1);
                strVec.push_back( "(" + _tempStr2 + "+" + _tempStr1 + ")");
                // if(resString == "")
                //     resString = "(" + to_string((int)_temp2) + "+" + to_string((int)_temp1) + ")";
                // else
                //     resString = "(" + resString + "+" + to_string((int)_temp1) + ")";    
            } else 
            if (a == '-')
            {
                numVec.push_back(_temp2 - _temp1);
                strVec.push_back( "(" + _tempStr2 + "-" + _tempStr1 + ")");
                // if(resString == "")
                //     resString = "(" + to_string((int)_temp2) + "-" + to_string((int)_temp1) + ")";
                // else
                //     resString = "(" + resString + "-" + to_string((int)_temp1) + ")";    
            } else
            if (a == '*') {
                numVec.push_back(_temp2 * _temp1);
                strVec.push_back( "(" + _tempStr2 + "*" + _tempStr1 + ")");
                // if(resString == "")
                //     resString = "(" + to_string((int)_temp2) + "*" + to_string((int)_temp1) + ")";
                // else
                //     resString = "(" + resString + "*" + to_string((int)_temp1) + ")";    
            } else
            if (a == '/'){
                numVec.push_back(_temp2 / _temp1);
                strVec.push_back( "(" + _tempStr2 + "/" + _tempStr1 + ")");
                // if(resString == "")
                //     resString = "(" + to_string((int)_temp2) + "/" + to_string((int)_temp1) + ")";
                // else
                //     resString = "(" + resString + "/" + to_string((int)_temp1) + ")";    
            }
        }
    }

    // cout << resString;
    cout << strVec[0];
}