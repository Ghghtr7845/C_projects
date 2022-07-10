//
//  Hand.cpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#include "Hand.hpp"
#include "Card.hpp"
#include "Deck.hpp"


namespace ECE17 {

    Hand::Hand() = default; 
        
    Hand::Hand(const Hand& aCopy) {
        *this = aCopy; 
    }

    Hand& Hand:: operator = (const Hand& aHand) {
        holdingCards = aHand.holdingCards; 
        return *this; 
    }
    

    // add 5 cards to hands
    bool Hand::addCard(const Card& aCard) {
        if (holdingCards.size() >= kCardsPerHand) {
            return false; 
        }
        holdingCards.push_back(aCard); 
        return true; 
    }

    // when we run out of cards return nullopt, otherwise continue to return cards
    CardOpt Hand::discard(Faces aFace, Suits aSuit) {
        Card theTempCard(aFace, aSuit); 
        
        std::vector<Card>::iterator position = std::find(holdingCards.begin(), holdingCards.end(), theTempCard); 
        
        if (position!= holdingCards.end()) {
            return theTempCard;
            holdingCards.erase(position); 
        }

        return std::nullopt; 
        
    }

    // returns the number of Card objects the Hand contains
    size_t Hand::count() {
        return holdingCards.size(); 
    }

    //returns true if a_card is in the Hand and false otherwise
    bool Hand::contain(const Card& aCard) {
        if (std::find(holdingCards.begin(), holdingCards.end(), aCard) != holdingCards.end()) {
            return true;
        }

        return false; 
    }

    Hand::~Hand() = default;

  std::ostream& operator<<(std::ostream &anOutput,const Hand &aHand) {
    //STUDENT: implement this to show the hand on the output console...
      for (Card myHand : aHand.holdingCards) {
          anOutput << myHand << "\n";
      }
      
    return anOutput;
  }

}
