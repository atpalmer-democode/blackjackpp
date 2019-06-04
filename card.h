#ifndef CARD_H
#define CARD_H

#include <array>


class CardRank {
private:
    std::string name_;
    int value_;

    CardRank(std::string name, int value);

public:
    static const std::array <CardRank, 13> RANKS;

    std::string get_name() const { return name_; }
    int get_value() const { return value_; }

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
    static const std::array<CardSuit, 4> SUITS;

    std::string get_name() const { return name_; }
    std::string get_symbol() const { return symbol_; }
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
    int get_value() const { return rank_.get_value(); }
};

std::ostream &operator <<(std::ostream &stream, const Card &card);


#endif
