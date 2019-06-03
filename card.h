#ifndef CARD_H
#define CARD_H

#include <array>


class CardRank {
private:
    std::string name_;
    int value_;

    CardRank(std::string name, int value);

public:
    std::string get_name() const { return name_; }
    int get_value() const { return value_; }

    static const std::array <CardRank, 13> RANKS;

    static const CardRank RA;
    static const CardRank R2;
    static const CardRank R3;
    static const CardRank R4;
    static const CardRank R5;
    static const CardRank R6;
    static const CardRank R7;
    static const CardRank R8;
    static const CardRank R9;
    static const CardRank RT;
    static const CardRank RJ;
    static const CardRank RQ;
    static const CardRank RK;

    bool operator ==(const CardRank &other) const {
        return this->name_ == other.name_;
    }
};


class CardSuit {
private:
    std::string name_;
    std::string symbol_;

    CardSuit(std::string name, std::string symbol);

public:
    std::string get_name() const { return name_; }
    std::string get_symbol() const { return symbol_; }

    static const std::array<CardSuit, 4> SUITS;

    static const CardSuit Spades;
    static const CardSuit Hearts;
    static const CardSuit Diamonds;
    static const CardSuit Clubs;
};


class Card {
private:
    CardRank rank_;
    CardSuit suit_;

public:
    Card(const CardRank &rank, const CardSuit &suit);

    bool is_ace() const { return rank_.get_name() == "A"; }
    CardRank get_rank() const { return rank_; }
    CardSuit get_suit() const { return suit_; }
};

std::ostream &operator <<(std::ostream &stream, const Card &card);


#endif
