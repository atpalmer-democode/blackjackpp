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
protected:
    std::vector<Card> cards_;

    Hand(std::vector<Card> cards) {
        cards_ = cards;
    }
public:
    template<class T>
    static T init_from(Shoe &s) {
        std::vector<Card> cards;
        cards.push_back(s.draw_card());
        cards.push_back(s.draw_card());
        return T(cards);
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


class DealerHand : public Hand {
public:
    DealerHand(std::vector<Card> cards) : Hand(cards) {
    }

    friend std::ostream &operator <<(std::ostream &s, DealerHand &h);
};


std::ostream &operator <<(std::ostream &s, DealerHand &h) {
    s << "🂠 " << ' ';
    std::vector<Card>::iterator ptr = h.cards_.begin();
    ++ptr;
    for(;ptr < h.cards_.end(); ++ptr) {
        s << *ptr << ' ';
    }
    return s;
}


int main() {
    Shoe shoe = Shoe::decks(4);
    Hand player_hand = Hand::init_from <Hand> (shoe);
    DealerHand dealer_hand = Hand::init_from <DealerHand> (shoe);
    std::cout << player_hand << std::endl;
    std::cout << dealer_hand << std::endl;
    return 0;
}
