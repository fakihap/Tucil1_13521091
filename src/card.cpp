#include <iostream>
#include <vector>

#include <time.h>
#include "card.h"

#include <random>

using namespace std;
 
int randint(int start, int end){
    return rand() % (end - start + 1) + start;
}

Card::Card(){

}
Card::Card(int init){
    value = init;
}

string Card::asCard(){
    if (value == 0){
        return "X"; // NOT A CARD
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

string Card::asString(){
    return to_string(value);
}

void Card::SetCard(int val){
    value = val;
}

void Card::RandomizeCard(){
    value = randint(1, 13);
}