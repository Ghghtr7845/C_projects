#include "Player.hpp"
#include <iostream>

namespace GT {

    Player::Player() {}
    Player::Player (const char* aName = "No name") : name(aName) {}
    Player::Player(const Player & aCopy) {*this = aCopy;}

    Player& Player::operator = (const Player& aCopy) {
        name = aCopy.name; 
        playerHand = aCopy.playerHand; 
        return *this; 
    }
    Player::~Player() = default; 

    void Player::setName(const char* aName) {name = aName;}

    const char *Player::getName() {return name; }

    std::ostream& operator<<(std::ostream& anOutput, const Player& aPlayer) {
        //write the cards in your deck to the given output stream...
        anOutput << aPlayer.name << "\n";

        return anOutput;
    }
    
} // end of namespace
