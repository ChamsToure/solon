#include <filesystem>
#include <iostream>
#include <map>
#include <vector>
#include "deck.cpp"
#include <memory>
#include <string>
namespace fs = std::filesystem;

void choose_deck() {
    std::cout << "These are the available decks: \n";
    for (const auto &entry: fs::directory_iterator("decks/"))
        std::cout << entry.path().string() << std::endl;
}

int main() {

    std::string path_to = "decks/";
    //for (const auto  entry: fs::directory_iterator(path_to))
    //    std::cout << entry.path().string()<< "\n";
    std::string file {"../decks/physics.txt"};
    std::shared_ptr<Deck> firstdeck = std::make_shared<Deck>(file);
    //firstdeck->printDeck();
    //firstdeck->startSession(4);
    
}
