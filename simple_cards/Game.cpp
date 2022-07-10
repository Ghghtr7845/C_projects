#include "Game.hpp"
#include <string>

namespace GT {

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
} // end of namespace 
