#include "Card.hpp"
#include <vector>

#ifndef _HAND
#define _HAND

class Hand {
private:
    std::vector<Card> _cards;
public:
    Hand(DeckOfCards deck); // grab five cards from deck
    std::vector<Card> cards() const;
};


#endif
