#include <iostream>
#include <vector>
#include "card.h"
#include "shoe.h"


class Hand {
protected:
    std::vector<Card> cards_;

    Hand(std::vector<Card> cards): cards_(cards) {
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

    int value() {
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
    std::cout << "Player: " << player_hand << " (Value:" << player_hand.value() << ")" << std::endl;
    std::cout << "Dealer: " << dealer_hand << std::endl;
    return 0;
}
