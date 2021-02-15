#ifndef DECK_H
#define DECK_H

#include <vector>
#include <fstream>
#include <iostream>
#include <tuple>

class Card {
    public:
        Card();
        std::pair<std::string, std::string> info;
        int correct = 0;
        std::pair<std::string, std::string> &getCard() {return info;}
        void incrementCorrect() {++correct;}
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
        void startSession(int limit); 
            
    private:
        std::vector<Card> _deck;
        std::string _filename;
};


#endif
