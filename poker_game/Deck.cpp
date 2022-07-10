
#include "Deck.hpp"
#include <algorithm>
#include <random>

namespace GT {

  Deck::Deck() { initializeCards(); }

  void Deck::initializeCards() {
      char theSuitList[] = { 'C','D','H','S' };
      for (auto theSuit : theSuitList) {
          Faces theFace = Faces::two;
          while (theFace <= Faces::ace) {
              Card theCard{ theFace,static_cast<Suits>(theSuit) };
              cards.push_back(theCard);
              theFace = (Faces)((int)theFace + 1);
          }
      }
  }

  Deck::Deck(const Deck &aCopy) {
         *this = aCopy;
  }

  Deck& Deck::operator=(const Deck &aDeck) {
      cards = aDeck.cards; 
      return *this; 
  }

  Deck::~Deck() {
      cards.clear(); // this deletes all elements in deque<Cards> cards
  }

  size_t Deck::count() {return cards.size();}
  
  Deck& Deck::shuffle() {
    
      std::random_device rd;
      std::mt19937 shuffleThis(rd());
      std::shuffle(cards.begin(), cards.end(), shuffleThis);
      return *this;
  }

  //take (draw) a card from deck; what if deck is empty?
  CardOpt Deck::take() {
    
    if (!count()){ return std::nullopt; }

    CardOpt topCard = cards.front();
    cards.erase(cards.begin());
    return topCard;
    
  }

  // determine if card is in the deck
  bool Deck::contains(const Card &aCard) const {
    
        bool theResult{ false };
        if (std::find(cards.begin(), cards.end(), aCard) != cards.end()) {
            return !theResult; 
        }
        
        return theResult;
  }
  
  //put card back on bottom of deck
  bool Deck::discard(const Card &aCard) {
    
    cards.push_back(aCard);
    bool theResult{false};
    return theResult;
  }

  std::ostream& operator<<(std::ostream &anOutput, const Deck &aDeck) {
       
      for (Card aDeck : aDeck.cards) {
          anOutput << aDeck << "\n";
      }

    return anOutput;
  }


} // end of namespace
