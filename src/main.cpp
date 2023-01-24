#include "card.h"
#include "deck.h"
// #include "calculator.h"
#include "solver.h"
#include "expression.h"

#include <iostream>
#include <vector>

using namespace std;

static vector<vector<char>> result;

Deck currentCards;

int main(int argc, const char** argv) {
    // RandomizeCard();
    // SetCard(1, 8, 9, 12);
    // SetCard(10, 3, 9, 6);
    // SetCard(6, 6, 4, 3);
    // SetCard(4, 4, 4, 2);
    // SetCard(4, 4, 4, 4); // weird
    // cout << (int)currentCards[0] << ' ' << (int)currentCards[1] << ' ' << (int)currentCards[2] << ' ' << (int)currentCards[3] << endl;

    // solve(result, currentCards);

    Expression exp;
    exp.SetExpr({"2", "3", "+", "4", "*"});
    // exp.ShowExpr();
    cout << exp.getResult() << endl;

    srand(time(0));

    bool start = true;
    while (start)
    {
        cout << "24-Card Game" << endl;

        currentCards.DisplayDeck();
        // currentCards.RandomizeDeck();
        currentCards.SetDeck(1, 10, 13, 12);
        currentCards.DisplayDeck();

        break;
    }
    

    
    return 0;
}