#include "deck.h"
#include <memory>
void Deck::create_deck(std::string &file)
{
    std::ifstream ifs(file);
    if(ifs.is_open()) {
        std::shared_ptr<Card> card = std::make_shared<Card>();
        int counter = 0;
        std::string line, last_question;
        while(getline(ifs, line)) {
            if (line.back() == '?'){ //Checks the last character of the line 
                std::shared_ptr<Card> card = std::make_shared<Card>();
                if(!_deck.empty()) {//to check increment after the first pair was completely added
                    ++counter;
                }
                _deck.push_back(*card);
                _deck[counter].info.first = line;
                last_question = line;
            } else if (line.size()>3){
                _deck[counter].info.second = _deck[counter].info.second + "\n" + line;
            }
        }
    }
};


Card::Card() {
    std::cout << "Card constructed\n";
};

void Deck::printDeck() {
    for (const auto &card: _deck) {
        std::cout << card.info.first << " : " << card.info.second << "\n";
    }
};
