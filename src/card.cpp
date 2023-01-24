#include <cstdlib>
#include <iostream>
#include <vector>

#include <time.h>
#include "card.h"

#include <random>

using namespace std;
 
int randint(int start, int end)
{
    // mt19937 mt();

    // return mt() % (end - start + 1) + start;

    return rand() % (end - start + 1) + start;
}

void getCards(vector<char> &cards){
    srand(time(0));

    // int cards[] = {NOT_A_CARD, NOT_A_CARD, NOT_A_CARD, NOT_A_CARD};

    // [for 52 cards format]
    // int i = 0, _card;
    // while (i < 4) {
    //     _card = randint(1, 52); // since both ends inclusive // starts with 1
    //     bool found = false;

    //     for (int j = 0; j < i; j++){
    //         if (found)
    //             break;

    //         if (cards[j] == _card)
    //             found = true;
    //     }
        
    //     if (!found) {
    //         cards[i] = _card;
    //         i++;
    //     }
    // }

    // [13 * 4 cards format]
    int _card;
    for(int i = 0; i < 4; i++){
        _card = randint(1, 13); // since both ends inclusive // starts with 1
        cards[i] = _card;
    }

    // cout << cards[0] << '-' << cards[1] << '-' << cards[2] << '-' << cards[3];

    // int kerd = (int)

}


string Card::asCard(){
    if (value == 0){
        return "X"; // missing values
    } else if (value == 1){
        return "A";
    } else if (value == 11) {
        return "J";
    } else if (value == 12) {
        return "Q";
    } else if (value == 13) {
        return "K";
    } else {
        return to_string(value);
    }
}

int Card::asInt(){
    return (int) value;
}

void Card::SetCard(int val){
    value = val;
}

void Card::RandomizeCard(){
    // srand(time(0));

    value = randint(1, 13);
}