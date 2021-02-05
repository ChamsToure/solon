#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include "deck.cpp"
#include <memory>
using namespace std;

int main() {
    std::string file {"test.txt"};
    std::shared_ptr<Deck> firstdeck = std::make_shared<Deck>(file);
    //firstdeck->printDeck();
    firstdeck->startSession(4);
}
