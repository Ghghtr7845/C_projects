#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include "Hand.hpp"
#include <deque>

namespace GT {

  class Deck  {
  public:
    
    Deck();
    Deck(const Deck &aDeck);
    Deck& operator=(const Deck &aDeck);
    ~Deck();

    CardOpt take(); //remove top card from deck...
    bool    discard(const Card &aCard);//pushes card to bottom of deck
        
    size_t  count(); //retrieve number of cards in deck...
    bool    contains(const Card &aCard) const; // determine if card is in deck
    Deck&   shuffle(); // shuffle cards
        
    friend std::ostream& operator<<(std::ostream &anOutput, const Deck &aDeck);

  protected:
    void initializeCards();
    std::deque<Card> cards; // will hold all the cards here

  };

} // end of namespace


#endif /* Deck_hpp */
