#include <iostream>
#include <string>
#include "Card.hpp"
#include "Deck.hpp"
#include "Hand.hpp"

std::ostream& operator<<(std::ostream &os, const Card &rhs) {
    os << rhs.toString();
    return os;
}

int main() {
    DeckOfCards cool_deck;
    // shuffle deck
    cool_deck.shuffle_cards();

    // generate one poker hand
    Hand cool_hand{cool_deck};
    for (auto card : cool_hand.cards()) {
        std::cout << card << std::endl;
    }

    return 0;
}
