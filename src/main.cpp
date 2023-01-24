#include "card.h"

#include <iostream>
#include <vector>

using namespace std;

static vector<int> currentCards;
static vector<vector<int>> result;

void RandomizeCard(){
    getCards(currentCards);
}

int main(int argc, const char** argv) {
    cout << "rtes" << endl;

    currentCards = {NOT_A_CARD, NOT_A_CARD, NOT_A_CARD, NOT_A_CARD};

    // currentCards = getCards();

    cout << currentCards[0] << '-' << currentCards[1] << '-' << currentCards[2] << '-' << currentCards[3] << endl;
    RandomizeCard();
    cout << currentCards[0] << '-' << currentCards[1] << '-' << currentCards[2] << '-' << currentCards[3] << endl;
    
    return 0;
}