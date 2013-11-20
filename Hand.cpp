#include "Card.hpp"
#include "Deck.hpp"
#include "Hand.hpp"
#include <vector>
#include <algorithm>
#include <utility>

Hand::Hand(DeckOfCards& deck) {
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

std::pair<int, int> score_hand(int p_c, int t_c, int q_c,
                               bool flush, bool straight, int high_card) {
    std::pair<int, int> score_pair;
    if (p_c == 1 and t_c == 0 and q_c == 0) {
        //PAIR
        // std::cout << "PAIR" << std::endl;
        score_pair = std::make_pair(1, high_card);
    }
    else if (p_c == 2 and t_c == 0 and q_c == 0) {
        //TWO_PAIR
        // std::cout << "TWO_PAIR" << std::endl;
        score_pair = std::make_pair(2, high_card);
    }
    else if (t_c == 1 and p_c == 0) {
        //THREE_KIND
        // std::cout << "THREE_KIND" << std::endl;
        score_pair = std::make_pair(3, high_card);
    }
    else if (straight == true and flush == false) {
        //STRAIGHT
        // std::cout << "STRAIGHT" << std::endl;
        score_pair = std::make_pair(4, high_card);
    }
    else if (flush == true and straight == false) {
        //FLUSH
        // std::cout << "FLUSH" << std::endl;
        score_pair = std::make_pair(5, high_card);
    }
    else if (t_c == 1 and p_c == 1) {
        //FULL_HOUSE
        // std::cout << "FULL_HOUSE" << std::endl;
        score_pair = std::make_pair(6, high_card);
    }
    else if (q_c == 1) {
        //FOUR_KIND
        // std::cout << "FOUR_KIND" << std::endl;
        score_pair = std::make_pair(7, high_card);
    }
    else if (straight == true and flush == true) {
        //STRAIGHT_FLUSH
        // std::cout << "STRAIGHT_FLUSH" << std::endl;
        score_pair = std::make_pair(8, high_card);
    }
    else {
        // std::cout << "HIGH_CARD" << std::endl;
        score_pair = std::make_pair(0, high_card);
    }

    return score_pair;
}

std::pair<int, int> Hand::eval_hand() const {

    int pair_count = 0;
    int triple_count = 0;
    int quad_count = 0;
    bool flush = 0;
    bool straight = 0;

    for (auto card : _cards) {
        _hist[card.face_index()] += 1;
    }

    // detect pairs, triples and quads
    for (int item : _hist) {
        if (item == 2) pair_count++;
        if (item == 3) triple_count++;
        if (item == 4) quad_count++;
    }

    // detect flush, ie all cards are same suit
    // in same sweep detect highest card
    int cmp_suit_index = _cards.front().suit_index();
    int consec_suits = 0;
    int high_card = 0;

    for (auto card : _cards) {
        if (card.face_index() > high_card) high_card = card.face_index();
        if (card.suit_index() == cmp_suit_index)
            consec_suits += 1;
        else break;
    }

    if (consec_suits == int(_cards.size()))
        flush = true;

    //detect straight
    int consec_faces = 0;
    for (auto it = begin(_cards); it != end(_cards); ++it) {
        if (it->face_index() == (it+1)->face_index())
            consec_faces += 1;
        else
            break;
    }

    if (consec_faces == int(_cards.size()))
        straight = true;

    return (score_hand(pair_count, triple_count,
                       quad_count, flush, straight,
                       high_card));
}

void Hand::replace_cards(DeckOfCards& replace_deck) {
    std::pair<int, int> score = this->eval_hand();
    int draw_number = 0;

    switch(score.first) {
    case 0: draw_number = 3; break;
    case 1: draw_number = 3; break;
    case 2: draw_number = 1; break;
    case 3: draw_number = 2; break;
    case 4: draw_number = 0; break;
    case 5: draw_number = 0; break;
    case 6: draw_number = 0; break;
    case 7: draw_number = 1; break;
    case 8: draw_number = 0; break;
    }
    // based on draw number, determine which cards to throw away
    while (draw_number > 0) {
        for (int i = 0; i < int(_hist.size()); i++) {
            if (_hist[i] == 0 or _hist[i] == 1) {
                _cards.erase(_cards.begin() + (i-1));
                draw_number -= 1;
            }
        }
    }
    while (_cards.size() < 5) {
	_cards.push_back(replace_deck.dealCard());
    }
}

bool Hand::operator<(const Hand& rhs) {
    std::pair<int, int> left = this->eval_hand();
    std::pair<int, int> right = rhs.eval_hand();

    if (left.first != right.first) {
        return (left.first < right.first);
    }
    else { // the two hands are of the same type, compare high card
        return (left.second < right.second);
    }
}

bool Hand::operator>(const Hand& rhs) {
    return operator<(*this);
}
