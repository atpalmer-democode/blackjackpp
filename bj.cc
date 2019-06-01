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


class Hand {
private:
    std::vector<Card> cards_;

    Hand(std::vector<Card> cards) {
        cards_ = cards;
    }
public:
    static Hand init_from(Shoe &s) {
        std::vector<Card> cards;
        cards.push_back(s.draw_card());
        cards.push_back(s.draw_card());
        return Hand(cards);
    }

    void add(Card card) {
        cards_.push_back(card);
    }

    friend std::ostream &operator <<(std::ostream &s, Hand &h);
};

std::ostream &operator <<(std::ostream &s, Hand &h) {
    for(Card c : h.cards_) {
        s << c << ' ';
    }
    return s;
}


int main() {
    Shoe shoe = Shoe::decks(4);
    Hand hand = Hand::init_from(shoe);
    std::cout << hand << std::endl;
    return 0;
}
