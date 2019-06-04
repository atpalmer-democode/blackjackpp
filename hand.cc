#include <iostream>
#include <vector>
#include "card.h"
#include "hand.h"
#include "shoe.h"


Hand::Hand(std::vector<Card> cards): cards_(cards) {
}


template<class T>
T Hand::init_from(Shoe &s) {
    std::vector<Card> cards;
    cards.push_back(s.draw_card());
    cards.push_back(s.draw_card());
    return T(cards);
}


template Hand Hand::init_from<Hand>(Shoe &s);
template DealerHand Hand::init_from<DealerHand>(Shoe &s);


void Hand::add(Card card) {
    cards_.push_back(card);
}


int Hand::value() const {
    int result = 0;
    int aces = 0;
    for(Card c : cards_) {
        result += c.get_rank().get_value();
        if(c.is_ace()) {
            ++aces;
        }
    }
    while(aces--) {
        if(result + 10 > 21) {
            break;
        }
        result += 10;
    }
    return result;
}


bool Hand::is_busted() const {
    return this->value() > 21;
}


bool Hand::has_blackjack() const {
    return this->cards_.size() == 2 && this->value() == 21;
}


std::ostream &operator <<(std::ostream &s, const Hand &h) {
    for(Card c : h.cards_) {
        s << c << ' ';
    }
    return s << "(Value:" << h.value() << ")";
}


DealerHand::DealerHand(std::vector<Card> cards) : Hand(cards) {
}


bool DealerHand::wants_card() const {
    return this->value() < 17;
}

std::ostream &operator <<(std::ostream &s, const DealerHand &h) {
    s << "🂠 " << ' ';
    std::vector<Card>::const_iterator ptr = h.cards_.cbegin();
    ++ptr;
    for(;ptr < h.cards_.end(); ++ptr) {
        s << *ptr << ' ';
    }
    return s;
}
