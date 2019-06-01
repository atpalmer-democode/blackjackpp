#include <vector>
#include <string>
#include "card.h"


CardRank::CardRank(std::string name, int value)
    : name_(name), value_(value) {
}


const CardRank CardRank::RA("A", 1);
const CardRank CardRank::R2("2", 2);
const CardRank CardRank::R3("3", 3);
const CardRank CardRank::R4("4", 4);
const CardRank CardRank::R5("5", 5);
const CardRank CardRank::R6("6", 6);
const CardRank CardRank::R7("7", 7);
const CardRank CardRank::R8("8", 8);
const CardRank CardRank::R9("9", 9);
const CardRank CardRank::RT("T", 10);
const CardRank CardRank::RJ("J", 10);
const CardRank CardRank::RQ("Q", 10);
const CardRank CardRank::RK("K", 10);


std::vector<CardRank> CardRank::ranks() {
    std::vector<CardRank> ranks;
    ranks.reserve(13);
    ranks.push_back(CardRank::RA);
    ranks.push_back(CardRank::R2);
    ranks.push_back(CardRank::R3);
    ranks.push_back(CardRank::R4);
    ranks.push_back(CardRank::R5);
    ranks.push_back(CardRank::R6);
    ranks.push_back(CardRank::R7);
    ranks.push_back(CardRank::R8);
    ranks.push_back(CardRank::R9);
    ranks.push_back(CardRank::RT);
    ranks.push_back(CardRank::RJ);
    ranks.push_back(CardRank::RQ);
    ranks.push_back(CardRank::RK);
    return ranks;
}


CardSuit::CardSuit(std::string name, std::string symbol)
    : name_(name), symbol_(symbol) {
}


const CardSuit CardSuit::Spades("Spades", "♠");
const CardSuit CardSuit::Hearts("Hearts", "♥");
const CardSuit CardSuit::Diamonds("Diamonds", "♦");
const CardSuit CardSuit::Clubs("Clubs", "♣");


std::vector<CardSuit> CardSuit::suits() {
    std::vector<CardSuit> suits;
    suits.reserve(4);
    suits.push_back(CardSuit::Spades);
    suits.push_back(CardSuit::Hearts);
    suits.push_back(CardSuit::Diamonds);
    suits.push_back(CardSuit::Clubs);
    return suits;
}


Card::Card(const CardRank &rank, const CardSuit &suit)
    : rank_(rank), suit_(suit) {
}


std::ostream &operator <<(std::ostream &stream, const Card &card) {
    return stream << card.get_rank().get_name() << card.get_suit().get_symbol();
}
