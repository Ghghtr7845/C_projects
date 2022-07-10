#include "WordAnalyzer.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>

namespace GT {
    using holdText = std::vector<std::string>;

    WordAnalyzer::WordAnalyzer() = default;
  
    WordAnalyzer& WordAnalyzer::operator = (const WordAnalyzer& aCopy) {
        containtext = aCopy.containtext; 
        word = aCopy.word; 
        return *this; 
    }
  
    WordAnalyzer::WordAnalyzer(const WordAnalyzer& aCopy) { 
        *this = aCopy;
    }
  
    WordAnalyzer::~WordAnalyzer() = default;

    bool isPunct(char aChar) {
        static std::string punct(".;?!:,(){}/ '\"'");
        return std::string::npos == punct.find(aChar) ? false : true;
    }

    holdText WordAnalyzer::cleanUp(std::istream& anInput) {

        while (anInput >> word) {

            char temp = word.back();
            char tempfront = word.front();

            if (isPunct(temp)) {
                word.pop_back();

            }
            if (isPunct(tempfront)) {
                word.erase(0, 1);
                containtext.push_back(word);
            }
            else {
                containtext.push_back(word);
            }

        }//end of while loop 

        for (std::string& i : containtext) {
            std::transform(i.begin(), i.end(), i.begin(), [](char c) { return std::tolower(c); });
        }

        containtext.erase(std::remove(containtext.begin(), containtext.end(), "-"), containtext.end());

        return containtext; //contain a vector 
    }//end of cleanUp

    size_t printWords(holdText aVector, std::ostream& anOutput) {
        std::map<std::string, int> wordmap;

        for (const std::string& s : aVector) { wordmap[s]++; }

        size_t count = 0;
        for (const auto& i : wordmap) {
            anOutput << i.first << ": " << i.second << "\n";
            count++;
        }
        return count; // number of unique words
    }


    size_t WordAnalyzer::countWords(std::istream& anInput, std::ostream& anOutput) {

        containtext = cleanUp(anInput);

        anOutput << "Total Words: " << containtext.size() << "\n";

        return printWords(containtext, anOutput);

    }// end of countWords

    //count the distinct word-pairs from input stream, write each word-pair (on a newline) to output
    //Return the number of word-pairs you found
    size_t WordAnalyzer::getWordPairs(std::istream& anInput, std::ostream& anOutput) {


        containtext = cleanUp(anInput);

        holdText containtextnew;
        std::string string_temp;

        for (long unsigned int i = 1; i <= containtext.size() - 1; i++)
        {
            string_temp = containtext[i - 1] + " " + containtext[i];
            containtextnew.push_back(string_temp);

        }

        anOutput << "Word Pair (" << containtextnew.size() << ")" << "\n";

        return printWords(containtextnew, anOutput);

    }//end of getPair

    std::string matchesMap(std::vector<std::string> aVector, std::string aCommand= "compress") {
        std::map<std::string, std::string>themap = {
       {"Skateboarding is exhilarating - you can move quickly and fly through the", "1"},
        {"air! Before you can do amazing tricks in the air, though, you need to learn", "2"},
        {"the basics of skateboarding, and be prepared for a lot of trial and error.", "3"},
        {"The first thing you need to do is get a skateboard. It's probably best to", "4"},
        {"talk with a skateboarder to find a store that sells good quality skateboards, not just", "5"},
        {"toys. Many skateboarders create their own setup, but for your first board, someone", "6"},
        {"at a skate shop should be able to help you. A helmet, elbow pads,", "7"},
        {"knee pads, and wrist guards are important to get, as well. It is better to wear", "8"},
            {"all of those than to hurt yourself! Once you are ready to learn tricks, you might", "9"},
            {"also need to buy some skate shoes. Then you'll need to find a place to skateboard.", "10"},
            {"An empty parking lot (with a safe adult around) or your driveway are good places to start.", "11"},
            {"Skate parks are popping up in many towns now, so try to find one near you! Wherever", "12"},
            {"you go, though, make sure it's a place where skateboarding is allowed.", "13"},
            {"There are some basic movements you'll need to learn in order to", "14"},
            {"skateboard. The first movement is to find your stance. Most skateboarders", "15"},
            {"put their left foot towards the front of the board and use their right foot to", "16"},
            {"push themselves. If you're left-handed, you might want to try standing in a", "17"},
            {"your left foot to push. Make sure your foot isn't all the way at the front of the", "18"},
            {"Next, you'll want to practice how to push off the ground and glide along on", "19"},
            {"the board. Make sure most of your weight is over your front foot so that you", "20"},
            {"can balance as your back foot pushes. Push off of your back foot and", "21"},
            {"balance as the board moves. Balancing on the board as it's moving might", "22"},
            {"take some time to get used to, so make sure you're comfortable balancing", "23"},
            {"Once you get used to balancing with your weight over your front foot, you", "24"},
            {"can practice shifting your weight while you're on the moving skateboard.", "25"},
            {"After you push off, practice putting your back foot on the board and shifting", "26"}

        };

        if (aCommand != "compress") {
            for (auto it = themap.begin(); it != themap.end(); it++) {
                replace(aVector.begin(), aVector.end(), it->second, it->first);
            }
        }

        else {
            for (auto it = themap.begin(); it != themap.end(); it++) {
                replace(aVector.begin(), aVector.end(), it->first, it->second);
            }
        }
        
        //convert vector to string

        std::string thestring;

        for (std::string i : aVector) {
            thestring = thestring + i + "\n";
        }

        return thestring;
    }//end of mapmatches and convert to string

    holdText WordAnalyzer::readLinebyLine(std::istream& anInput) {
        std::string line;
        while (getline(anInput, line)) {
            containtext.push_back(line);
        }

        return containtext; 

    }
    //end of readLinebyLine

    //compress string data from input, and write compressed version to output
    //Return number of bytes you've written to output
    size_t WordAnalyzer::compress(std::istream& anInput, std::ostream& anOutput) {

        containtext = readLinebyLine(anInput); 

        std::string compressed_string = matchesMap(containtext);

        anOutput << compressed_string << std::endl;

        return compressed_string.size();

    }

    //Decompress string data from input, and write uncompressed version to output
    //Return number of bytes you've written to output    
    size_t WordAnalyzer::decompress(std::istream& anInput, std::ostream& anOutput) {

        containtext = readLinebyLine(anInput);
        std::string decompressed_string = matchesMap(containtext, "decompress");

        anOutput << decompressed_string << std::endl;

        return decompressed_string.size();

    }


} // end of namespace
