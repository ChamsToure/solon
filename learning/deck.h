#ifndef DECK_H
#define DECK_H

#include <vector>
#include <map>
#include <fstream>
#include <iostream>
//TODO take the code from the main file and construct
//it into a class named "Deck"
class Deck{
    public:
        void create_deck(std::string &file);
        Deck(std::string &filename)
            :_filename{filename} {
                //TODO write a function that read a file and create a deck automatically
                create_deck(filename);
            }
        std::map<std::string, std::string> &get_deck () {return _deck;}
        void printDeck() {
            //TODO should print every card in the deck
            for (const auto& [key, value]: _deck) {
                std::cout << "\n"<<key <<  value << "\n";
            }
            }
        
    private:
        
        std::map<std::string, std::string> _deck;
        std::string _filename;
};
//TODO turn every question and answer into an card object



//Card create_card(std::map<std::string, std::vector<std::string>> temp_card);

#endif
