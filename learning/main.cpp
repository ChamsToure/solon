#include <filesystem>
#include <iostream>
#include <map>
#include <vector>
#include "deck.cpp"
#include <memory>
#include <string>
namespace fs = std::filesystem;

//TODO UNFINISHED finish the main menu function
void menu() {
    std::vector<std::string> choices = {
        "Choose a Deck\n",
        "Create a new Deck\n",
        "Display all Decks\n",
    };
    int choice;
    std::cout << "What do you want to do? \n\n";
    std::cin >> choice;
   /* switch(choice){
        case 1: std::string deck = choose_deck();
        case 2: create_new_deck();
        default: std::cout << "Pick Again!\n";
    }*/
};


int main() {
//    menu();
    std::string deck = choose_deck();
    std::string file {deck};
    std::shared_ptr<Deck> firstdeck = std::make_shared<Deck>(file);
    firstdeck->startSession(2);
}
