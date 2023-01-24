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