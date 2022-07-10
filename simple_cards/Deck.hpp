#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <optional>

#include "Hand.hpp"
#include "Card.hpp"

namespace GT {
    const int cards_per_deck{ 52 };

  class Deck {
  public:

      Deck(); 
      Deck(const Deck& aCopy); 
      Deck& operator = (const Deck& aDeck);
      ~Deck(); 
    
      
      Deck& shuffle();
      CardOpt take(); // go get card, get top card from deck 
      bool discard(Card &aCard); // pushes card to bottom 
      size_t count(); //returns size 
      void show(std::ostream &anOutput); 

    // this is also where we implment the 52 cards
    //this method will print the deck to the terminal
    friend std::ostream& operator<<(std::ostream &anOutput, const Deck &aDeck);

  private:  
     std::vector<Card> deck;
     void initDeck();
  };
    
} // end of namespace 

#endif /* Deck_hpp */
