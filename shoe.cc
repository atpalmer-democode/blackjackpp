#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "card.h"
#include "shoe.h"


Shoe::Shoe(std::vector<Card> cards)
    : cards_(cards) {
}


Card Shoe::draw_card() {
    Card result = cards_.back();
    cards_.pop_back();
    return result;
}


Shoe Shoe::decks(int decks) {
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
