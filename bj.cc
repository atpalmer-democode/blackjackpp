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


void dealer_turn(Hand &dealer_hand, Shoe &shoe) {
    while(dealer_hand.value() < 17) {
        dealer_hand.add(shoe.draw_card());
    }
}


int main() {
    auto shoe = Shoe::decks(4);
    auto player_hand = Hand::init_from<Hand>(shoe);
    auto dealer_hand = Hand::init_from<DealerHand>(shoe);

    play_turn(player_hand, dealer_hand, shoe);
    dealer_turn(dealer_hand, shoe);

    auto exposed_dealer_hand = Hand(dealer_hand);
    std::cout << "Player: " << player_hand << std::endl;
    std::cout << "Dealer: " << exposed_dealer_hand << std::endl;
}
