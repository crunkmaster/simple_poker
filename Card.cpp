#include "Card.hpp"
#include <string>
#include <vector>
#include <array>

// try to see if there's a cleaner way to initialize this thing..
const std::array<std::string, 13> Card::faces{ 
    {"Ace", "2", "3", "4", "5", "6",
	    "7","8","9","10","Jack",
	    "Queen","King"} };
const std::array<std::string, 4> Card::suits{ {"Clubs", "Diamonds", "Hearts", "Spades"} } ;

Card::Card(int face, int suit) {
    _face = face;
    _suit = suit;

    if (_face > 12) throw std::string("invalid face");
    if (_suit > 3) throw std::string("invalid suit");
}

std::string Card::toString() const {
    return (this->face() + " of " + this->suit());
}

std::string Card::suit() const {
    return this->suits[_suit];
}

int Card::suit_index() const {
    return _suit;
}

int Card::face_index() const {
    return _face;
}

std::string Card::face() const {
    return this->faces[_face];
}
