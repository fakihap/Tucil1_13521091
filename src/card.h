#ifndef CARD_H
#define CARD_H

    #include <iostream>
    #include <vector>
    #include <string>
    #include <random>

    #include <time.h>

    using namespace std;

    int randint(int start, int end);

    void getCards(vector<char> &cards);

    class Card {
        int value  = 0; // NOT A CARD

        public:
            Card();
            Card(int init);

            int asInt();
            string asCard();
            string asString();

            void SetCard(int val);
            void RandomizeCard();
    };

#endif