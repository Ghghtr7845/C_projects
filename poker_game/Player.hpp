#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include "Deck.hpp"
#include "Hand.hpp"
#include "Card.hpp"

namespace GT {

    class Player {
    public:

        Player(const std::string& aName = "");
        Player(const Player& aPlayer);
        ~Player();
        Player& operator=(const Player& aPlayer);

        const Hand& getHand() const;
        void          setHand(const Hand& aHand);

        const std::string& getName() const;


        //////////////////////////////////////////////////////////
        bool          isFolding(float aBalance) const;

        float         placeBet(float aBalance, float aMinBet);
        size_t        discardUnwanted();

        bool          drawCards(Deck& aDeck, size_t aMaxCount);


        //////////////////////////////////////////////////////////


        friend std::ostream& operator<<(std::ostream& anOut, const Player& anObj);

    protected:
        std::string name;
        Hand        hand;

    };

} // end of namespace

#endif /* Player_hpp */
