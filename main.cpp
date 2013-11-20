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
    Hand dealer_hand{cool_deck};
    Hand player_hand{cool_deck};
    
    std::cout << "Hand one: " << std::endl;
    for (auto card : dealer_hand.cards()) {
        std::cout << card << std::endl;
    }
    
    std::cout << "score: " << std::endl;
    std::cout << dealer_hand.eval_hand().first << std::endl;
    dealer_hand.replace_cards(cool_deck);
    
    std::cout << "Replacement HAnd: " << std::endl;
    for (auto card : dealer_hand.cards()) {
        std::cout << card << std::endl;
    }
    std::cout << "score: " << std::endl;
    std::cout << dealer_hand.eval_hand().first << std::endl;
    
    std::cout << std::endl;

    std::cout << "Hand two: " << std::endl;
    for (auto card: player_hand.cards()) {
	std::cout << card << std::endl;
    }
    std::cout << std::endl;

    if (dealer_hand < player_hand) {
	std::cout << "hand two wins!" << std::endl;
    }
    else { std::cout << "hand one wins!" << std::endl; }
    return 0;
    
}
