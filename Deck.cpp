#include "Card.hpp"
#include "Deck.hpp"
#include <random>

DeckOfCards::DeckOfCards() {
    for (int suit = 0; suit < 4; suit++)
        for (int face = 0; face < 13; face++)
            _deck.push_back(Card(face, suit));
}

std::vector<Card>::iterator DeckOfCards::begin() {
    return this->_deck.begin();
};

std::vector<Card>::iterator DeckOfCards::end() {
    return this->_deck.end();
}

void DeckOfCards::shuffle_cards() {
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(_deck.begin(), _deck.end(), g);
}

bool DeckOfCards::moreCards() const {
    if (_deck.size() > 0) return true;
    else return false;
}

Card DeckOfCards::dealCard() {
    if (this->moreCards()) {
        Card temp = _deck.front();
        _deck.erase(_deck.begin());
        return temp;
    }
    else { throw std::string("no cards on deck"); }
}
