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
    string choice = "-1";
    while (start)
    {
        cout << "############### 24-Card Game ###############" << endl;
        cout << endl << "Kartu saat ini :" << endl;
        cout << "\t"; currentCards.DisplayDeck();
        cout << endl << "Menu" << endl;
        cout << " 1. Acak Kartu" << endl;
        cout << " 2. Atur Kartu" << endl;
        cout << " 3. Simpan Solusi" << endl;
        cout << endl;
        cout << " 0. Cari Solusi" << endl;
        cout << endl << endl;
        cout << "99. Keluar" << endl;

        cout << endl << "Pilihan Anda : "; cin >> choice; cout << endl;

        if (choice == "1"){
            currentCards.RandomizeDeck();
        } else if (choice == "2"){
            vector<int> _cardChoices;

            int _i = 0, _buf;
            while(_i < 4){
                cout << "Masukkan nilai Kartu ke-" << _i+1 << " : "; cin >> _buf;

                if (1 <= _buf && _buf <= 13){
                    _i++;
                    _cardChoices.push_back(_buf);
                }
            }

            currentCards.SetDeck(_cardChoices);
        } else if (choice == "3"){
            csolver.SaveSolution();
        } else if (choice == "0"){
            csolver.SetDeck(currentCards);
            csolver.GenerateSolution();
            csolver.ShowInfixSolution();
        } else if (choice == "99"){
            start = false;
        }

        choice == "-1";
    }
    

    
    return 0;
}