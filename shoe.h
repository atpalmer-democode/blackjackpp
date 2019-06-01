#ifndef SHOE_H
#define SHOE_H

#include <vector>
#include "card.h"


class Shoe {
private:
    std::vector<Card> cards_;

public:
    Shoe(std::vector<Card> cards);
    Card draw_card();
    static Shoe decks(int decks);
};

#endif
