#include <iostream>
#include <vector>
#include "card.h"
#include "shoe.h"
#include "hand.h"


void play_turn(Hand &player_hand, const DealerHand &dealer_hand, Shoe &shoe) {
    if(player_hand.has_blackjack()) {
        std::cout << "BLACKJACK!" << std::endl;
        return;
    }

    for(;;) {
        std::cout << "Player: " << player_hand << std::endl;
        std::cout << "Dealer: " << dealer_hand << std::endl;

        if(player_hand.is_busted()) {
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


void dealer_turn(DealerHand &dealer_hand, Shoe &shoe) {
    while(dealer_hand.wants_card()) {
        dealer_hand.add(shoe.draw_card());
    }
}


double score_bet_multiplier(const Hand &player_hand, const DealerHand &dealer_hand) {
    if(player_hand.is_busted()) {
        return -1;
    }

    if(player_hand.has_blackjack() && !dealer_hand.has_blackjack()) {
        return 1.5;
    }

    if(dealer_hand.has_blackjack() && !player_hand.has_blackjack()) {
        return -1;
    }

    if(dealer_hand.is_busted()) {
        return 1;
    }

    if(player_hand.value() > dealer_hand.value()) {
        return 1;
    }

    if(player_hand.value() == dealer_hand.value()) {
        return 0;
    }

    return -1;
}


int main() {
    auto shoe = Shoe::decks(4);
    auto player_hand = Hand::init_from<Hand>(shoe);
    auto dealer_hand = Hand::init_from<DealerHand>(shoe);

    play_turn(player_hand, dealer_hand, shoe);
    dealer_turn(dealer_hand, shoe);

    std::cout << "Player: " << player_hand << std::endl;
    std::cout << "Dealer: " << Hand(dealer_hand) << std::endl;

    double multiplier = score_bet_multiplier(player_hand, dealer_hand);
    std::cout << "Bet × " << multiplier << std::endl;
}
