#include "deck.h"

#include <iostream>

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
    cardDeck[0].SetCard(a);
    cardDeck[1].SetCard(b);
    cardDeck[2].SetCard(c);
    cardDeck[3].SetCard(d);
}