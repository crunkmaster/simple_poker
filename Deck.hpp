#include "Card.hpp"

#ifndef _DECK
#define _DECK

class DeckOfCards {
private:
    std::vector<Card> _deck;
    int _currentCard;
    bool moreCards() const;
public:
    DeckOfCards();
    std::vector<Card>::iterator begin();
    std::vector<Card>::iterator end();
    int size() const;
    void shuffle_cards();
    Card dealCard();
};

#endif
