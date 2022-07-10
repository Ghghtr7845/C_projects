#include "Player.hpp"
#include "Hand.hpp"
#include "Deck.hpp"
#include "Card.hpp"

namespace GT {

    Player::Player(const std::string& aName)
        : name(aName) {}

    Player::Player(const Player& aCopy) { *this = aCopy; }

    Player& Player::operator=(const Player& aCopy) {
        name = aCopy.name;
        hand = aCopy.hand;
        return *this;
    }

    Player::~Player() {}

    const Hand& Player::getHand() const { return hand; }

    void  Player::setHand(const Hand& aHand) {
        hand = aHand;
    }

    const std::string& Player::getName() const { return name; }


    ///////////////////////////////////////////////////////////////////////////////////

    bool Player::isFolding(float aBalance) const {
        
        HandRanks currentrank = hand.determineRank();
        
        if (currentrank == HandRanks::high_card){
            return true;
        }
        if (currentrank == HandRanks::one_pair) {
            return true; 
        }

        return false; //placeholder for you...
    }

    bool Player::drawCards(Deck& aDeck, size_t aMaxCount) {
          // if aMaxCoutn exceeds 5 then you cant take more cards

        for (size_t i = 0; i < aMaxCount; i++) {
            hand.addCard(*aDeck.take());
        }

        return true;
    }

    float Player::placeBet(float aBalance, float aMinBet) {
        // bet must be above the minBet but less than aBalance
        // put any number in theBet
        
        HandRanks currentrank = hand.determineRank();
        float theBet{ 0.0 };
        while (theBet < aBalance) {
            
            if (currentrank == HandRanks::royal_flush || currentrank == HandRanks::straight_flush || currentrank == HandRanks::four_kind) { theBet = 50.0; }
            else if (currentrank == HandRanks::full_house || currentrank == HandRanks::flush || currentrank == HandRanks::straight) { theBet = 40.0; }
            else { theBet = 10.0; }
            aBalance = aBalance - theBet;
            return theBet; 

        } //end of while
        return aBalance; 
    }


    size_t Player::discardUnwanted() {
        //implement discard a random card because you haven't figured out how to discard specific cards
      
        HandRanks currentrank = hand.determineRank(); 
        if (hand.count() == 5 ) {
            hand.discardRandom();
        }
      
        return hand.count();
    }

    std::ostream& operator<<(std::ostream& anOut, const Player& aPlayer) {
        anOut << aPlayer.name;
        return anOut;
    }

} // end of namespace 
