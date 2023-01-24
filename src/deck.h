#ifndef DECK_H
#define DECK_H
    #include "card.h"

    class Deck {
        public:
            vector<Card> cardDeck = {Card(), Card(), Card(), Card()};

            void DisplayDeck();

            void RandomizeDeck();
            void SetDeck(int a, int b, int c, int d);
            void SetDeck(vector<int> vec);
    };


#endif