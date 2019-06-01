#include <iostream>
#include <vector>
#include "card.h"
#include "shoe.h"
#include "hand.h"


int main() {
    Shoe shoe = Shoe::decks(4);
    Hand player_hand = Hand::init_from <Hand> (shoe);
    DealerHand dealer_hand = Hand::init_from <DealerHand> (shoe);
    std::cout << "Player: " << player_hand << " (Value:" << player_hand.value() << ")" << std::endl;
    std::cout << "Dealer: " << dealer_hand << std::endl;
    return 0;
}
