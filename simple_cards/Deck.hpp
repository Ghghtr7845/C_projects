//
//  Deck.hpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <optional>

#include "Hand.hpp"
#include "Card.hpp"

namespace ECE17 {
    const int cards_per_deck{ 52 };

  class Deck {
  public:

      Deck(); 
      Deck(const Deck& aCopy); 
      Deck& operator = (const Deck& aDeck);
      ~Deck(); 
    
    //STUDENT: implement this class as outlined in the readme...
       
      //void shuffle(); // shuffle cards
      Deck& shuffle();
      CardOpt take(); // go get card, get top card from deck 
      bool discard(Card &aCard); // pushes card to bottom 
      size_t count(); //returns size 
      void show(std::ostream &anOutput); 

    // this is also where we implment the 52 cards
    //this method will print the deck to the terminal
    friend std::ostream& operator<<(std::ostream &anOutput,
                                    const Deck &aDeck);
    
    //I need to hold 52 cards, but an ARRAY
    //would be a poor choice...

  private:  
     std::vector<Card> deck;
     void initDeck();
  };
}

#endif /* Deck_hpp */
