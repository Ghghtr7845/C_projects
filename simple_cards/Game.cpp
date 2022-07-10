//
//  Game.cpp
//  Assignment1
//
//  Created by rick gessner on 10/12/20.
//

#include "Game.hpp"
#include <string>

namespace ECE17 {

   Game:: Game() {}

   Game::Game(const Game& aCopy) {
        *this = aCopy; 
    }

    

    Game& Game :: operator = (const Game& aCopy) {
        thedeck = aCopy.thedeck; 
        player1 = aCopy.player1; 
        player2 = aCopy.player2; 
        return *this; 
    }
  
  bool Game::willStartGame() {
      return true; 
  }

  Game::~Game() = default;
}
