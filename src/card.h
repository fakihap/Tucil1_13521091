#ifndef CARD_H
#define CARD_H

#define NOT_A_CARD -1

#include <vector>
#include <string>

using namespace std;

int randint(int start, int end);

void getCards(vector<char> &cards);

class Card {
    public:
        int value  = 0; // NOT A CARD

        int asInt();
        string asCard();

        void SetCard(int val);
        void RandomizeCard();
};

#endif