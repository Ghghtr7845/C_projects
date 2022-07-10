//
//  Deck.cpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#include "Deck.hpp"
#include "Card.hpp"
#include "Hand.hpp"

#include <vector>
#include <optional>
#include <iostream>
#include <algorithm>
#include <random>
//#include <random>

namespace ECE17 {
    //initialize deck of cards here in default

    Deck::Deck() {
        initDeck(); 
    }

    Deck::Deck(const Deck& aCopy) {
        *this = aCopy; 
    }
    Deck& Deck::operator=(const Deck& aDeck) {
        deck = aDeck.deck; 
        return *this;
    }

    void Deck::initDeck() {
        Suits aSuit[]{ Suits::clubs,Suits::diamonds,Suits::hearts,Suits::spades };

        for (Suits aSuit : aSuit) {
            for (size_t theFace = 2; theFace < 15; theFace++) {
                Card theCard{ static_cast <Faces>(theFace),aSuit };
                deck.push_back(theCard);
            }
        }
    }

    //void Deck::shuffle() {
    Deck& Deck::shuffle() {
        std::random_device rd; 
        std::mt19937 shuffleThis(rd()); 
        std::shuffle(deck.begin(), deck.end(), shuffleThis); 
        return *this; 

    }
    // take the top card 
    CardOpt Deck::take() {

        if (!deck.size()) { return std::nullopt; }

        CardOpt topCard = deck.front();
        deck.erase(deck.begin());
        return topCard; 
  
    }
   
    //push card to bottom 
    bool Deck::discard(Card &aCard) {
       deck.push_back(aCard);
        return true; 
    }

    //return size 
    size_t Deck::count() {
       return deck.size(); 
    }

    Deck::~Deck () = default;

    void Deck::show(std::ostream& anOutput) {
        anOutput << *this << '\n';
    }
  
  std::ostream& operator<<(std::ostream &anOutput, const Deck &aDeck) {
    //write the cards in your deck to the given output stream...
      for (Card aDeck: aDeck.deck) {
          anOutput << aDeck << "\n"; 
      }

    
     
    return anOutput;
  }
  
}
