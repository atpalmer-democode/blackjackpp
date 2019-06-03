#include <array>
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


const std::array<CardRank, 13> CardRank::RANKS = {
    CardRank::RA,
    CardRank::R2,
    CardRank::R3,
    CardRank::R4,
    CardRank::R5,
    CardRank::R6,
    CardRank::R7,
    CardRank::R8,
    CardRank::R9,
    CardRank::RT,
    CardRank::RJ,
    CardRank::RQ,
    CardRank::RK,
};


CardSuit::CardSuit(std::string name, std::string symbol)
    : name_(name), symbol_(symbol) {
}


const CardSuit CardSuit::Spades("Spades", "♠");
const CardSuit CardSuit::Hearts("Hearts", "♥");
const CardSuit CardSuit::Diamonds("Diamonds", "♦");
const CardSuit CardSuit::Clubs("Clubs", "♣");


const std::array<CardSuit, 4> CardSuit::SUITS = {
    CardSuit::Spades,
    CardSuit::Hearts,
    CardSuit::Diamonds,
    CardSuit::Clubs,
};


Card::Card(const CardRank &rank, const CardSuit &suit)
    : rank_(rank), suit_(suit) {
}


std::ostream &operator <<(std::ostream &stream, const Card &card) {
    return stream << card.get_rank().get_name() << card.get_suit().get_symbol();
}
