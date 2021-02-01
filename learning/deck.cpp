#include "deck.h"
#include <memory>
void Deck::create_deck(std::string &file)
{
    std::ifstream ifs(file);
    if(ifs.is_open()) {
        int counter {0};
        std::string line, last_question;
        while(getline(ifs, line)) {
            if (line.back() == '?'){ //Checks the last character of the line 
                _deck[line]; 
                //std::cout << "The question is: " << line << "\n";
                last_question = line;
                //std::cout << "The last_question is:  " << last_question << "\n";   
            } else if (line.size()>3){
                _deck[last_question] =_deck[last_question] +"\n"+ line;
                //std::cout << "The line is: " << line << "\n";
            }
        }
    }
};




//Card Card::create_card(std::map<std::string, std::vector<std::string>> temp_card) {
//    Card card(temp_card);  
//}
