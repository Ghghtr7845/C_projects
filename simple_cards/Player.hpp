#ifndef Player_hpp
#define Player_hpp

#include "Hand.hpp"
#include "Card.hpp"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std; 

namespace GT {
    
    class Player {

    public: 
        Player();
        Player(const char *aName);
        Player(const Player& aCopy); 
        Player& operator = (const Player& aCopy); 
        ~Player(); 

        void setName(const char* aName); //set the player name 
        const char* getName();
        friend std::ostream& operator<<(std::ostream& anOutput, const Player& aPlayer);

    private:
        const char* name;
        int score; 
        Hand playerHand;
    };
      
} // end of namespace 

#endif /* Player_hpp */
