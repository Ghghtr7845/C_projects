
#ifndef WordAnalyzer_hpp
#define WordAnalyzer_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

namespace GT {
  
  class WordAnalyzer {
  public: 
      using holdText = std::vector <std::string>; 

      WordAnalyzer();
      ~WordAnalyzer();
      WordAnalyzer& operator = (const WordAnalyzer& aCopy);
      WordAnalyzer(const WordAnalyzer& aCopy);

    
    //count the distinct words from input stream, write each word (on a newline) to output
    //Return the number of words you found
    size_t countWords(std::istream& anInput, std::ostream& anOutput);
    
    //count the distinct word-pairs from input stream, write each word-pair (on a newline) to output
    //Return the number of word-pairs you found
    size_t getWordPairs(std::istream& anInput, std::ostream& anOutput);

    //compress string data from input, and write compressed version to output
    //Return number of bytes you've written to output
    size_t compress(std::istream& anInput, std::ostream& anOutput);
    
    //Decompress string data from input, and write uncompressed version to output
    //Return number of bytes you've written to output    
    size_t decompress(std::istream& anInput, std::ostream& anOutput);

    holdText cleanUp(std::istream& anInput);
    holdText readLinebyLine(std::istream& anInput); 
    
  protected: 
    holdText containtext; 
    std::string word; 
  };


} // end of namespace 

#endif /* WordAnalyzer_hpp */
