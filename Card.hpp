#include <iostream>
#include <string>
#include <vector>

#ifndef _CARD
#define _CARD

class Card {
private:
    static const std::string faces[];
    static const std::string suits[];
    int _face;
    int _suit;
public:
    Card(int face, int suit);
    std::string toString() const;
    int suit_index() const;
    int face_index() const;
    std::string suit() const;
    std::string face() const;
};

#endif
