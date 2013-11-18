#include "Card.hpp"
#include <string>
#include <vector>
#include <random>

const std::string Card::faces[] = {"Ace","2","3","4","5",
                                   "6","7","8","9","10","Jack","Queen","King"};
const std::string Card::suits[] = {"Clubs","Diamonds","Hearts","Spades"};

Card::Card(int face, int suit) {
    _face = face;
    _suit = suit;

    if (_face > 12) throw std::string("invalid face");
    if (_suit > 3) throw std::string("invalid suit");
}

std::string Card::toString() const {
    return (this->faces[_face] + " of " + this->suits[_suit]);
}

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
