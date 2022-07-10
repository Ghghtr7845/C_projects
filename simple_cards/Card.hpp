
#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <optional> //C++ 17

namespace GT {

  enum class Suits
    : char {clubs='C', diamonds='D', hearts='H', spades='S'};

  enum class Faces
    : int {two=2, three, four, five, six, seven, eight,
           nine, ten, jack, queen, king, ace /*14*/};
    
  class Card {
  public:
    // initializer, face starts with ace and suits starts with clubs
    Card(Faces aFace=Faces::ace, Suits aSuit=Suits::clubs);
    Card(const Card &aCopy);
    ~Card();
    
    Card& operator=(const Card& aCopy);
    bool  operator==(const Card& aCopy) const;
            
    //this method will print the card to output stream
    friend std::ostream& operator<<(std::ostream &anOutput,
                                    const Card &aCard);
    
    Suits suit;
    Faces face;
  };
  
  using CardOpt = std::optional <Card>;
} // end of namespace 

#endif /* Card_hpp */
