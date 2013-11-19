#include "Card.hpp"
#include "Deck.hpp"
#include <vector>

#ifndef _HAND
#define _HAND

enum HandType {
    PAIR = 0,
    TWO_PAIR = 1,
    THREE_KIND = 2,
    STRAIGHT = 3,
    FLUSH = 4,
    FULL_HOUSE = 5,
    FOUR_KIND = 6,
    STRAIGHT_FLUSH = 7
};

class Hand {
private:
    std::vector<Card> _cards;
public:
    Hand(DeckOfCards deck);
    std::vector<Card> cards() const;
    bool pair() const;
    bool two_pair() const;
    bool three_of_kind() const;
    bool four_of_kind() const;
    bool flush() const;
    bool straight() const;
    int eval_hand() const;
};


#endif
