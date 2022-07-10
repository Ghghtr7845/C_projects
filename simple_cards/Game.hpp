//
//  Game.hpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Card.hpp"
#include "Player.hpp"
#include "Hand.hpp"
#include "Deck.hpp"

#include <string>
#include <vector>

//STUDENT -- you need to finish this class!

namespace ECE17 {

    class Game {
    public:

        //Student -- add methods here (including OCF)...
        Game();
        
        Game(const Game& aCopy); 
        Game& operator = (const Game& aCopy);
        bool willStartGame();

        ~Game(); 
       
       
  private:
    
    //Student -- add data members here...
      Deck thedeck;
      Player player1;
      Player player2;
  };

}


#endif /* Game_hpp */
