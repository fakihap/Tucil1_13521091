#include "card.h"
// #include "calculator.h"
#include "solver.h"

#include <iostream>
#include <vector>

using namespace std;

static vector<char> currentCards;
static vector<vector<char>> result;

void RandomizeCard(){
    getCards(currentCards);
}

int main(int argc, const char** argv) {
    cout << "main test:" << endl;

    currentCards = {NOT_A_CARD, NOT_A_CARD, NOT_A_CARD, NOT_A_CARD};
    // vector<char> keo = {2, 3, '*', 4, '+'};
    // // keo = {10, 3, '/', 9, '*', 6, '-'}; //==== 24
    // postfixCalculate(keo);

    // currentCards = getCards();

    RandomizeCard();
    cout << currentCards[0] << '-' << currentCards[1] << '-' << currentCards[2] << '-' << currentCards[3] << endl;

    solve(result, currentCards);

    
    return 0;
}