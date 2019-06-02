#include <iostream>
#include <vector>
#include "card.h"
#include "shoe.h"
#include "hand.h"


void play_turn(Hand player_hand, DealerHand dealer_hand, Shoe shoe) {
    if(player_hand.value() == 21) {
        std::cout << "BLACKJACK!" << std::endl;
        return;
    }

    for(;;) {
        std::cout << "Player: " << player_hand << std::endl;
        std::cout << "Dealer: " << dealer_hand << std::endl;

        if(player_hand.value() > 21) {
            std::cout << "BUSTED!" << std::endl;
            break;
        }

        std::string choice;
        std::cout << "<H>it or <S>tand? ";
        std::cin >> choice;

        if(std::tolower(choice.front()) == 'h') {
            player_hand.add(shoe.draw_card());
            continue;
        }

        if(std::tolower(choice.front()) == 's') {
            break;
        }
    }
}


int main() {
    Shoe shoe = Shoe::decks(4);
    Hand player_hand = Hand::init_from <Hand> (shoe);
    DealerHand dealer_hand = Hand::init_from <DealerHand> (shoe);

    play_turn(player_hand, dealer_hand, shoe);

    return 0;
}
