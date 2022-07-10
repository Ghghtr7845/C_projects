#ifndef Hand_hpp
#define Hand_hpp

#include "Card.hpp"
#include "Deck.hpp"

#include <stdio.h>
#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>

namespace GT {

  const int kCardsPerHand{5};

  class Hand {
  public:
    
      Hand(); // at first hand holds nothing
      Hand(const Hand &aCopy); 
      ~Hand(); 
      Hand& operator = (const Hand &aHand); 

  public: 
      bool addCard(const Card &aCard); 
      CardOpt discard(Faces aFace, Suits aSuit);
      size_t count(); 
      bool contain(const Card& aCard); 

    //this will show a hand on the console...
    friend std::ostream& operator<<(std::ostream &anOutput,
                                    const Hand &aHand);
    
  private:
    
      std::vector<Card> holdingCards; 
  };
   
} // end of namespace 

#endif /* Hand_hpp */


