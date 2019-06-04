#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <vector>
#include "card.h"
#include "shoe.h"


struct HandValue {
    bool is_soft;
    int value;

    HandValue(bool is_soft=false, int value=0)
        : is_soft(is_soft), value(value) {
    }
};


class Hand {
protected:
    std::vector<Card> cards_;
    HandValue cached_value_;

    Hand(std::vector<Card> cards);

public:
    template<class T>
    static T init_from(Shoe &s);

    void add(Card card);
    int value() const { return cached_value_.value; }
    bool is_busted() const;
    bool has_blackjack() const;

    friend std::ostream &operator <<(std::ostream &s, const Hand &h);
};


class DealerHand : public Hand {
public:
    DealerHand(std::vector<Card> cards);
    bool wants_card() const;

    friend std::ostream &operator <<(std::ostream &s, const DealerHand &h);
};


std::ostream &operator <<(std::ostream &s, const Hand &h);
std::ostream &operator <<(std::ostream &s, const DealerHand &h);

#endif
