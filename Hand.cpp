#include "Card.hpp"
#include "Deck.hpp"
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

// int Hand::eval_hand() {
//     int cards[13] = {};
//     for (auto card : this->cards()) {

//     }
// }

bool Hand::pair() const {

}

bool Hand::two_pair() const {
    // if there isn't one pair, there can't be two pairs
    if (!pair()) return false;
}

bool Hand::three_of_kind() const {

}

bool Hand::four_of_kind() const {

}

bool Hand::flush() const {

}

bool Hand::straight() const {

}
