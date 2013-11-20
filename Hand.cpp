#include "Card.hpp"
#include "Deck.hpp"
#include "Hand.hpp"
#include <vector>
#include <algorithm>

Hand::Hand(DeckOfCards deck) {
    while (_cards.size() < 5) {
        _cards.push_back(deck.dealCard());
    }
    this->sort_hand();
}

std::vector<Card> Hand::cards() const {
    return _cards;
}

void Hand::sort_hand() {
    // sort the hand using a cool lambda expression!
    // these are sorted by face value to make things easy
    std::sort(_cards.begin(), _cards.end(), [](Card a, Card b) {
            return (a.face_index() < b.face_index());
        });
}

int Hand::eval_hand() const {
    std::array<int, 13> hist{};

    int pair_count = 0;
    int triple_count = 0;
    int quad_count = 0;
    bool flush = 0;
    bool straight = 0;

    for (auto card : _cards) {
	hist[card.face_index()] += 1;
    }

    for (auto item : hist) {
	std::cout << item << " ";
    }
    std::cout << std::endl;

    // detect pairs, triples and quads
    for (int item : hist) {
	if (item == 2) pair_count++;
	if (item == 3) triple_count++;
	if (item == 4) quad_count++;
    }

    // detect flush, ie all cards are same suit
    int cmp_suit_index = _cards.front().suit_index();
    int consec_suits = 0;
    
    for (auto card : _cards) {
	if (card.suit_index() == cmp_suit_index)
	    consec_suits += 1;
	else break; 
    }

    if (consec_suits == _cards.size())
	flush = true;

    //detect straight
    int consec_faces = 0;
    for (auto it = begin(_cards); it != end(_cards); ++it) {
	if (it->face_index() == (it+1)->face_index())
	    consec_faces += 1;
	else
	    break;
    }

    if (consec_faces == _cards.size())
	straight = true;

    std::cout << "pairs: " << pair_count << std::endl;
    std::cout << "triples: " << triple_count << std::endl;
    std::cout << "fours: " << quad_count << std::endl;
    std::cout << "flush: " << flush << std::endl;
    std::cout << "straight: " << straight << std::endl;
    
}

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
