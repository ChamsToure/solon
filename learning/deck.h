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
        std::map<std::string, std::vector<std::string>> &get_deck () {return _deck;}
        
    private:
        
        std::map<std::string, std::vector<std::string>> _deck;
        std::string _filename;
};
//TODO turn every question and answer into an card object
class Card{
    public:
        void createCard

    private:
        std::string question;
        std::vector<std::string> answers;
}


#endif
