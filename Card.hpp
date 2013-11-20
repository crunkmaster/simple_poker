#include <iostream>
#include <string>
#include <vector>
#include <array>

#ifndef _CARD
#define _CARD

class Card {
private:
    static const std::array<std::string, 13> faces;
    static const std::array<std::string, 4> suits;
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
