#include "card.h"
#include "deck.h"
#include "solver.h"
#include "expression.h"

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int main(int argc, const char** argv) {
    Deck currentCards;
    cardSolver csolver;

    srand(time(0));

    bool start = true;
    int choice = -1;
    while (start)
    {
        cout << "############### 24-Card Game ###############" << endl;
        cout << endl << "Kartu saat ini :" << endl;
        cout << "\t"; currentCards.DisplayDeck();
        cout << endl << "Menu" << endl;
        cout << " 1. Acak Kartu" << endl;
        cout << " 2. Atur Kartu" << endl;
        cout << endl;
        cout << " 0. Cari Solusi" << endl;
        cout << endl << endl;
        cout << "99. Keluar" << endl;

        cout << endl << "Pilihan Anda : "; cin >> choice; cout << endl << endl;

        if (choice == 1){
            currentCards.RandomizeDeck();
        } else if (choice == 2){

        } else if (choice == 0){
            csolver.SetDeck(currentCards);
            csolver.GenerateSolution();
            csolver.ShowInfixSolution();
        } else if (choice == 99){
            start = false;
        }

        choice == -1;
    }
    

    
    return 0;
}