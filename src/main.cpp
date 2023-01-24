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

void SetCard(int a, int b, int c, int d){
    currentCards = {(char)a, (char)b, (char)c, (char)d};
}

int main(int argc, const char** argv) {
    cout << "main test:" << endl;

    currentCards = {NOT_A_CARD, NOT_A_CARD, NOT_A_CARD, NOT_A_CARD};
    // vector<char> keo = {2, 3, '*', 4, '+'};
    // // keo = {10, 3, '/', 9, '*', 6, '-'}; //==== 24
    // postfixCalculate(keo);

    // currentCards = getCards();

    // RandomizeCard();
    // SetCard(1, 8, 9, 12);
    SetCard(10, 3, 9, 6);
    cout << (int)currentCards[0] << ' ' << (int)currentCards[1] << ' ' << (int)currentCards[2] << ' ' << (int)currentCards[3] << endl;

    solve(result, currentCards);

    
    return 0;
}