#include "deck.h"

void Deck::DisplayDeck(){
    for(auto i:cardDeck){
        cout << i.asCard() << " ";
    } cout << endl;
}

void Deck::RandomizeDeck(){
    for(int i = 0; i < 4; i++){
        cardDeck[i].RandomizeCard();
    }
}

void Deck::SetDeck(int a, int b, int c, int d){
    cardDeck = {Card(a), Card(b), Card(c), Card(d)};
}

void Deck::SetDeck(vector<int> vec){
    cardDeck = {Card(vec[0]), Card(vec[1]), Card(vec[2]), Card(vec[3])};
}