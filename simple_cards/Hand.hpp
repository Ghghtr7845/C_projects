//
//  Hand.hpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#ifndef Hand_hpp
#define Hand_hpp


#include "Card.hpp"
#include "Deck.hpp"

#include <stdio.h>
#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>

namespace ECE17 {

  const int kCardsPerHand{5};

  class Hand {
  public:
    //STUDENT: implement this class from assigment...
    
      Hand(); // at first hand holds nothing
      Hand(const Hand &aCopy); 
      ~Hand(); 
      Hand& operator = (const Hand &aHand); 

  public: 

      bool addCard(const Card &aCard); 
      //CardOpt discard(const Card &aCard);
      CardOpt discard(Faces aFace, Suits aSuit);
      size_t count(); 
      bool contain(const Card& aCard); 

    //this will show a hand on the console...
    friend std::ostream& operator<<(std::ostream &anOutput,
                                    const Hand &aHand);
    
  private:
    //how will you "hold" the cards you're given?
      std::vector<Card> holdingCards; // a deque of type Card name cards, this will hold all the cards
  };
   
}

#endif /* Hand_hpp */


