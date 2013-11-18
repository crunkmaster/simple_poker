#include <iostream>
#include <string>
#include <vector>

#ifndef _CARD
#define _CARD

class Card {
private:
    static const std::string faces[];
    static const std::string suits[];
    int _face;
    int _suit;
public:
    Card(int face, int suit);
    std::string toString() const;
};

class DeckOfCards {
private:
    std::vector<Card> _deck;
    int _currentCard;
    bool moreCards() const;
public:
    DeckOfCards();
    std::vector<Card>::iterator begin();
    std::vector<Card>::iterator end();
    void shuffle_cards();
    Card dealCard();
};

#endif
