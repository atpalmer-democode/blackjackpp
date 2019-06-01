#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <vector>
#include "card.h"
#include "shoe.h"


class Hand {
protected:
    std::vector<Card> cards_;

    Hand(std::vector<Card> cards);

public:
    template<class T>
    static T init_from(Shoe &s);

    void add(Card card);
    int value();

    friend std::ostream &operator <<(std::ostream &s, Hand &h);
};


class DealerHand : public Hand {
public:
    DealerHand(std::vector<Card> cards);

    friend std::ostream &operator <<(std::ostream &s, DealerHand &h);
};


std::ostream &operator <<(std::ostream &s, Hand &h);
std::ostream &operator <<(std::ostream &s, DealerHand &h);

#endif
