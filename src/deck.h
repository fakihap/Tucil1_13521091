#ifndef DECK_H
#define DECK_H
    #include "card.h"

    class Deck {
        vector<Card> cardDeck = {Card(), Card(), Card(), Card()};

        public:
            void DisplayDeck();

            void RandomizeDeck();
            void SetDeck(int a, int b, int c, int d);
    };


#endif