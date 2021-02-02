#ifndef DECK_H
#define DECK_H

#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <tuple>
class Card {
    public:
        Card();
        std::pair<std::string, std::string> info;
        int reps = 0;
};
class Deck{
    public:
        void create_deck(std::string &file);
        Deck(std::string &filename)
            :_filename{filename} {
                //a function that read a file and create a deck automatically
                create_deck(filename);
            }
        std::vector<Card> &get_deck () {return _deck;}
        void printDeck(); 
        void startSession(int limit) { //if one card has reached the limit, it wont be displayed anymore
            bool sessionEnd = false; //turn true, if the card has reached the limit
            std::vector<Card>temp_deck = _deck;
            while(sessionEnd == false) {
            std::string answer;
            //TODO Here is somewhere a BUG in the loop
            for(auto &card: temp_deck) {
                if( card.reps <= limit ) {
                    std::cout << card.info.first << "\n 'y' for yes, 'n' for no \n";
                    std::cin >> answer;
                    if(answer == "y") {
                        card.reps+=1;
                        std::cout << card.reps << "\n";
                    } else {
                        std::cout << card.reps << "\n";
                    }
                    std::cout << "\n" << card.info.second << "\n\n";
                } else {
                    std::cout << "You are done!!!\n";
                    sessionEnd = true;
                }
                
            }    
        }
    }
            
    private:
        std::vector<Card> _deck;
        std::string _filename;
};


#endif
