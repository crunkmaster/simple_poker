#include "Card.hpp"
#include "Deck.hpp"
#include <vector>
#include <utility>

#ifndef _HAND
#define _HAND

// PAIR = 0,
// TWO_PAIR = 1,
// THREE_KIND = 2,
// STRAIGHT = 3,
// FLUSH = 4,
// FULL_HOUSE = 5,
// FOUR_KIND = 6,
// STRAIGHT_FLUSH = 7

// takes number of pairs, triples, quads and whether it is a flush
// or a straight
std::pair<int, int> score_hand(int p_c, int t_c, int q_c, bool flush,
                               bool straight, int high_card);

class Hand {
private:
    std::vector<Card> _cards;
    void sort_hand();
    mutable std::array<int, 13> _hist{};
public:
    Hand(DeckOfCards& deck);
    std::vector<Card> cards() const;
    bool pair() const;
    bool two_pair() const;
    bool three_of_kind() const;
    bool four_of_kind() const;
    bool flush() const;
    bool straight() const;
    std::pair<int, int> eval_hand() const;
    void replace_cards(DeckOfCards& replace_deck);
    bool operator<(const Hand& rhs);
    bool operator>(const Hand& rhs);
};

int draw_num(Hand testhand);

#endif
