#include "Card.hpp"
#include "Hand.hpp"
#include <vector>

Hand::Hand(DeckOfCards deck) {
    while (_cards.size() < 5) {
        _cards.push_back(deck.dealCard());
    }
}

std::vector<Card> Hand::cards() const {
    return _cards;
}
