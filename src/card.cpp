#include <cstdlib>
#include <iostream>
#include <vector>

#include <time.h>
#include "card.h"

#include <random>

using namespace std;
 
int randint(int start, int end)
{
    mt19937 mt(time(0));

    return mt() % (end - start + 1) + start;
}

void getCards(vector<int> &cards){
    // int cards[] = {NOT_A_CARD, NOT_A_CARD, NOT_A_CARD, NOT_A_CARD};

    int i = 0, _card;
    while (i < 4) {
        _card = randint(0, 51); // since both ends inclusive
        bool found = false;

        for (int j = 0; j < i; j++){
            if (found)
                break;

            if (cards[j] == _card)
                found = true;
        }
        
        if (!found) {
            cards[i] = _card;
            i++;
        }
    }

    // cout << cards[0] << '-' << cards[1] << '-' << cards[2] << '-' << cards[3];

    // int kerd = (int)

}