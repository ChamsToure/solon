#include <filesystem>
#include <iostream>
#include <map>
#include <vector>
#include "deck.cpp"
#include <memory>
#include <string>
namespace fs = std::filesystem;



int main() {
    create_new_deck(); 
    std::string path_to = "decks/";
    //for (const auto  entry: fs::directory_iterator(path_to))
    //    std::cout << entry.path().string()<< "\n";
    std::string file {"decks/physics.txt"};
    std::shared_ptr<Deck> firstdeck = std::make_shared<Deck>(file);
    //firstdeck->printDeck();
    //firstdeck->startSession(4);
    
}
