#include <array>
#include <string>
#include "card.h"


CardRank::CardRank(std::string name, int value)
    : name_(name), value_(value) {
}


const std::array<CardRank, 13> CardRank::RANKS = {
    CardRank("A", 1),
    CardRank("2", 2),
    CardRank("3", 3),
    CardRank("4", 4),
    CardRank("5", 5),
    CardRank("6", 6),
    CardRank("7", 7),
    CardRank("8", 8),
    CardRank("9", 9),
    CardRank("T", 10),
    CardRank("J", 10),
    CardRank("Q", 10),
    CardRank("K", 10),
};


CardSuit::CardSuit(std::string name, std::string symbol)
    : name_(name), symbol_(symbol) {
}


const std::array<CardSuit, 4> CardSuit::SUITS = {
    CardSuit("Spades", "♠"),
    CardSuit("Hearts", "♥"),
    CardSuit("Diamonds", "♦"),
    CardSuit("Clubs", "♣"),
};


Card::Card(const CardRank &rank, const CardSuit &suit)
    : rank_(rank), suit_(suit) {
}


std::ostream &operator <<(std::ostream &stream, const Card &card) {
    return stream << card.get_rank().get_name() << card.get_suit().get_symbol();
}
