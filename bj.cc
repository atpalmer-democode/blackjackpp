#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "card.h"


class Shoe {
private:
    std::vector<Card> cards_;

public:
    Shoe(std::vector<Card> cards) {
        cards_ = cards;
    }

    Card draw_card() {
        Card result = cards_.back();
        cards_.pop_back();
        return result;
    }

    static Shoe decks(int decks) {
        assert(decks > 0);

        std::vector<Card> cards;
        std::vector<CardRank> ranks = CardRank::ranks();
        std::vector<CardSuit> suits = CardSuit::suits();

        for(int i = 0; i < decks; ++i) {
            for(const CardSuit &suit : suits) {
                for(const CardRank &rank : ranks) {
                    cards.push_back(Card(rank, suit));
                }
            }
        }

        std::srand(std::time(nullptr));
        std::random_shuffle(cards.begin(), cards.end());

        return Shoe(cards);
    }
};


int main(void) {
    Shoe s = Shoe::decks(4);
    std::cout << s.draw_card() << std::endl;
    return 0;
}
