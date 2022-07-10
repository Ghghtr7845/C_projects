#ifndef Hand_hpp
#define Hand_hpp

#include <stdio.h>
#include "Card.hpp"
#include "Deck.hpp"
#include <deque>
#include <vector>
#include <array>
#include <string>
#include <random>
#include <map>

namespace GT {
    
    using FaceCountMap = std::map<Faces, size_t>;
    using SuitCountMap = std::map<Suits, size_t>;
    enum class HandRanks {
        unknown = 0, high_card, one_pair, two_pair, three_kind, straight,
        flush, full_house, four_kind, straight_flush, royal_flush
    };
    const int kCardsPerHand{ 5 };

    class Hand {
    public:
      
        Hand();
        Hand(const Hand& aCopy);
        ~Hand();

        Hand& operator=(const Hand& aHand);

        bool    addCard(const Card& aCard); // add 5 cards to hands
       
        CardOpt discard(const Card &aCard);
        bool    contains(const Card& aCard) const; ////returns true if a_card is in the Hand and false otherwise
        size_t  count() const;

        //this will show a hand on the console...
        friend std::ostream& operator<<(std::ostream& anOutput, const Hand& aHand);

        Faces     highCard() const;
        HandRanks determineRank() const; 
        void discardRandom(); 
       
        bool verifyHighCard() const; 
        bool verifyOnePair() const; 
        bool verifyTwoPairs() const; 
        bool verifyThreePairs() const; 
        bool verifyStraight() const; 
        bool verifyFlush() const; 
        bool verifyFullHouse() const; 
        bool verifyFourPairs() const; 
        bool verifyStraightFlush() const; 
        bool verifyRoyalFlush() const; 
       
        bool operator==(const Hand& otherHand) const;
        bool operator<(const Hand& otherHand) const;
        
    protected:

        std::deque<Card> cards; //Deque required; DO NOT CHANGE

        FaceCountMap facesmap;
        SuitCountMap suitsmap;

        size_t count_sequence =0;
        size_t count1 = 0;
        size_t count2 = 0;
        size_t count3 = 0;
        size_t count4 = 0;
        size_t count5 = 0;

    };

} // end of namespace 

#endif /* Hand_hpp */
