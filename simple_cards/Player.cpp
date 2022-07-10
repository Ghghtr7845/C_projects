//
//  Player.cpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#include "Player.hpp"
#include <iostream>

namespace ECE17 {
/*
    Player::Player() :name("") {
    }

    Player::Player(string name) : name(name) {
    }

    void Player::setName(string n) {
        name = n;
    }

    string Player::getName() const { 
        return name; 
    }

    Player::Player(const Player& aPlayer) {
        *this = aPlayer;
    }
    Player &Player::operator = (const Player& aPlayer) {
       name = aPlayer.name;
        return *this;
    }
   
    Player::~Player() {}

    std::ostream& operator<<(std::ostream& anOutput, const Player& aPlayer) {
        //write the cards in your deck to the given output stream...
        anOutput << aPlayer.name << '\n'; 

        return anOutput;
    }*/
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
    
}