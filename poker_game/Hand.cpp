#include "Hand.hpp"
#include "Card.hpp"
#include "Deck.hpp"

#include <map>
#include <algorithm>
#include <numeric>

namespace GT {

    using FaceCountMap = std::map<Faces, size_t>;
    using SuitCountMap = std::map<Suits, size_t>; 

    Hand::Hand() = default;

    Hand::Hand(const Hand& aCopy) {
        *this = aCopy;
    }

    Hand::~Hand() { cards.clear(); }

    //Determine the kind of hand (rank) we have, given a set of cards...
    HandRanks Hand::determineRank() const {
        //student: implement
        
        if (verifyFlush() == true) { return HandRanks::flush; }
        else if (verifyHighCard() == true) { return HandRanks::high_card; }
        else if (verifyOnePair() == true) { return HandRanks::one_pair; }
        else if (verifyTwoPairs() == true) { return HandRanks::two_pair; }
        else if (verifyThreePairs() == true) { return HandRanks::three_kind; }
        else if (verifyStraight() == true) { return HandRanks::straight; }
        else if (verifyFullHouse() == true) { return HandRanks::full_house; }
        else if (verifyFourPairs() == true) { return HandRanks::four_kind; }
        else if (verifyStraightFlush() == true) { return HandRanks::straight_flush; }
        else if (verifyRoyalFlush() == true) { return HandRanks::royal_flush; }
        
        
        return HandRanks :: unknown; //placeholder for you
    }

    bool Hand::verifyHighCard() const {
        // EX: 2,4,7,8,12
        // holdcountedsuits don't matter
        // holdcountedfaces.size()=5 because each face appears once
        // count_sequence!= 0 because it is not in consecutive order 
        // count1=5 because each number is counted once in a deque of length 5
        
        if (facesmap.size() == 5 && count_sequence != 0 && count1 == 5 && suitsmap.size() != 1) {
            return true; 
        }
        return false; 
    }
    
    bool Hand::verifyOnePair() const {
        //EX: 2,2,4,5,6
        //holdcountedsuits don't matter
        //holdcountedfaces.size()==4 because 1 face is counted twice while the rest is counted once 
            // {2,1,1,1}

        // count_sequence!=0 because it is not in secutive order there is a repeating face
        //count1==3 because 3 different faces
        //count2==1 because one face appears twice

       if (facesmap.size() == 4 && count_sequence != 0 && count1 == 3 && count2 == 1) {
            return true;
        }
        return false; 
    }

    bool Hand::verifyTwoPairs() const {
        // EX: 3,3,4,4,6
        //holdcountedsuits don't matter 
        // holdcountedfaces.size() == 3 , two faces are counted twice
            // {2,2,1}
        // count_sequence!=0 because it is not in secutive order there is are two repeating faces
        //count1==1 because 1 different face
        //count2==2 because two faces appears twice

        if (facesmap.size() == 3 && count_sequence != 0 && count1 == 1 && count2 == 2) {
            return true;
        }
        return false;

    }

    bool Hand::verifyThreePairs() const {
        // EX: 3,3,3,4,6
        //holdcountedsuits don't matter 
        // holdcountedfaces.size() == 3 , 1 face is counted 3 times while the rest is counted once
            // {3,1,1}
        // count_sequence!=0 because it is not in secutive order there is are 3 repeating faces
        //count1==1 because 2 different face
        //count3==1 because there is a face that appears 3 times

        if (facesmap.size() == 3 && count_sequence != 0 && count1 == 2 && count3 == 1) {
            return true;
        }
        return false;
       
    }

    bool Hand::verifyStraight() const {
        // EX: 1,2,3,4,5 or 6,7,8,9,10 or 12, 11, 10, 9,8,7
        //holdcountedsuits don't matter 
        // holdcountedfaces.size() == 5  because each face is counted once they should all be unique faces
            // {1,1,1,1,1}
        // count_sequence==0 because it is in sequence
            // recall that we sort cards from smallest to largest already so we don't have to care about the 3rd EX
        //count1==5 because each face is different
       
        if (count_sequence == 0 && suitsmap.size() != 1) {
            return true;
        }
        return false;
    }

    bool Hand::verifyFlush() const {
        // EX: 2H,3H,5H,6H,10H
        //holdcountedsuits.size()==1 because there is only one suit to consider 
            //{5}
        // holdcountedfaces.size() == 5  because each face is counted once they should all be unique faces
            // {1,1,1,1,1}
        // count_sequence!=because it is not supposed to be in sequence 
        // 

        if (count_sequence != 0 && suitsmap.size() == 1) {
            return true;
        }
        return false;
    }

    bool Hand::verifyFullHouse() const{
        // EX: 2,2,2,6,6
        //holdcountedsuits.size() don't matter
        // holdcountedfaces.size() == 2  because each face is counted once they should all be unique faces
            // {3,2}
        // count_sequence!=because there are repeating faces
        // count2==1
        //count3==1

        if (count_sequence != 0 && facesmap.size() == 2 && count2 == 1 && count3 == 1) {

            return true;
        }
        return false;
        
    }
    bool Hand::verifyFourPairs() const {
        // EX: 2,2,2,2,6
        //holdcountedsuits.size() don't matter
        // holdcountedfaces.size() == 2  because 1 face is counted 4 times and the other is counted onc
            // {4,1}
        // count_sequence!=because there are repeating faces
        // count1 ==1
        //count4==1

        if (count_sequence != 0 && facesmap.size() == 2 && count1 == 1 && count4 == 1) {
            return true;
        }
        return false;
    }

    bool Hand::verifyStraightFlush() const {
        // EX: 1H,2H,3H,4H,5H
        //holdcountedsuits.size() ==1
            // {5}
        // holdcountedfaces.size() == 5  because 1 each face is counted once
            //{1,1,1,1,1}
        // count_sequence==0 because it is consecutive
        if (count_sequence == 0 && suitsmap.size() == 1 && cards[0].getFace() != Faces::ten
            && cards[1].getFace() != Faces::jack && cards[2].getFace() != Faces::queen
            && cards[3].getFace() != Faces::king && cards[4].getFace() != Faces::ace) {
            return true;
        }
        
        return false; 
    }
    bool Hand::verifyRoyalFlush() const {
       // holdcountedfaces.size()==5
       // holdcountedsuits.size()==1; 
        //Faces::ten, Faces::jack, Faces::queen, Faces::king, Faces::ace

        if (cards[0].getFace() == Faces::ten && cards[1].getFace() == Faces::jack && cards[2].getFace() == Faces::queen
            && cards[3].getFace() == Faces::king && cards[4].getFace() == Faces::ace) {
            return true;
        }
        return false; 
    }
    
    bool Hand::addCard(const Card& aCard) {
        //student: implement

        bool theResult{ false };
        if (count() >= kCardsPerHand) {
            return theResult;

        }
        
        cards.push_back(aCard); //push both faces and suits

        if (count() == kCardsPerHand) {
            std::sort(cards.begin(), cards.end()); //sort cards

            for (size_t i = 0; i < cards.size(); i++) {
                facesmap[cards[i].getFace()]++; // count faces value put into map
                suitsmap[cards[i].getSuit()]++; // count suits value put into map
            }
            
            // if cards in consecutive sequence
            for (size_t i = 0; i <= cards.size() - 2; i++) {
                if (static_cast<size_t> (cards[i].getFace()) + 1 != static_cast<size_t>(cards[i + 1].getFace())) {
                    count_sequence++; // if number is 0 then it is in consecutive sequence
                }

            }
            for (const auto& i : facesmap) {
                if (1 == i.second) { count1++; }
                if (2 == i.second) { count2++; }
                if (3 == i.second) { count3++; }
                if (4 == i.second) { count4++; }
                if (5 == i.second) { count5++; }
            }

        }
        return !theResult;
    }
 
    void Hand::discardRandom() {
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_int_distribution<int> distr(0, 4);

        int aRand = distr(eng);
        cards.erase(cards.begin() + aRand);

        //re-initialize
        facesmap.clear(); 
        suitsmap.clear();
        count_sequence = 0; 
        count1 = 0;
        count2 = 0;
        count3 = 0;
        count4 = 0;
        count5 = 0;
        
        for (size_t i = 0; i < cards.size(); i++) {
            facesmap[cards[i].getFace()]++; // count faces value put into map
            suitsmap[cards[i].getSuit()]++; // count suits value put into map
        }

        // if cards in consecutive sequence
        for (size_t i = 0; i <= cards.size() - 2; i++) {
            if (static_cast<size_t> (cards[i].getFace()) + 1 != static_cast<size_t>(cards[i + 1].getFace())) {
                count_sequence++; // if number is 0 then it is in consecutive sequence
            }

        }
       
        for (const auto& i : facesmap) {
            if (1 == i.second) { count1++; }
            if (2 == i.second) { count2++; }
            if (3 == i.second) { count3++; }
            if (4 == i.second) { count4++; }
            if (5 == i.second) { count5++; }
        }

    }
    
    Hand& Hand::operator=(const Hand& aCopy) {
        cards = aCopy.cards;
        facesmap = aCopy.facesmap; 
        suitsmap = aCopy.suitsmap; 
        count_sequence = aCopy.count_sequence;
        count1 = aCopy.count1; 
        count2 = aCopy.count2; 
        count3 = aCopy.count3; 
        count4 = aCopy.count4;
        count5 = aCopy.count5;
        

        return *this;
    }

    bool Hand::operator<(const Hand& aHand) const {
       
        return this->determineRank() < aHand.determineRank() ;
    }

    bool Hand::operator==(const Hand& aHand) const {

        return this->determineRank() == aHand.determineRank();
    }

   
    CardOpt Hand:: discard (const Card &aCard){
        
        std::deque<Card>::iterator position = std::find(cards.begin(), cards.end(), aCard);

        if (position != cards.end()) {
          return aCard;
          cards.erase(position);
        }

        return std::nullopt;
    }

    size_t Hand::count() const {
        return cards.size();
    }

    bool Hand::contains(const Card& aCard) const {
        //student: implement
        if (std::find(cards.begin(), cards.end(), aCard) != cards.end()) {
            return true;
        }

        return false; //placeholder for you
    }

    std::ostream& operator<<(std::ostream& anOutput, const Hand& aHand) {
        for (auto theCard : aHand.cards) {
            anOutput << theCard << " ";
        }
        return anOutput;
    }

    Faces Hand::highCard() const {
        Faces theMax = Faces::two;
        //student: implement
        for (size_t i = 0; i < cards.size(); i++) {
            Faces holdFace = cards[i].getFace();
            if (holdFace > theMax) {
                theMax = holdFace;

            }
        }
        return theMax;
    }

} // end of namespace
