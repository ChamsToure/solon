#include "deck.h"
#include <memory>
#include <random>
#include <filesystem>
#include <fstream>

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
                //to check increment after the first pair was completely added
                if(!_deck.empty())
                    ++counter;
                _deck.push_back(*card);
                _deck[counter].info.first = line;
                last_question = line;
            } else if (line.size()>3){
                _deck[counter].info.second = _deck[counter].info.second + "\n" + line;
            }
        }
    } else {
        std::cerr << "Cannot open the file \n";
    }
};

int generateRandomNumber(const std::vector<Card> &item) {
    std::random_device random_dev;
    std::mt19937 gen(random_dev());
    std::uniform_int_distribution<> distr(0, item.size()-1);    
    int random_num = distr(gen);
    return random_num;
};

/*
 * The startSession method will start a session. The limit parameter sets the goal for correct guesses for each card
 * It will pick random cards, will wait until you pressed a character to show you the answer
 * If your guess was correct you shold type 'y' and it will automatically increment the number of correct guesses
 * If a card has reached the limit of correct guesses, it will be removed from the temporary list
 * The user can exit if he presses 'q'
 */

void Deck::startSession(int limit) 
{ //if one card has reached the limit, it wont be displayed anymore
    std::vector<Card>temp_deck = _deck;
    std::string delay;
    std::string answer;
    while(!temp_deck.empty()) {
        //Will generate a random number for each iteration in the range of the deck size
        int randNum = generateRandomNumber(temp_deck);
        std::cout << "\n" << temp_deck[randNum].getCard().first;
        std::cout << "\nShow Answer: ";
        std::cin >> delay;
        std::cout << "\n" << temp_deck[randNum].getCard().second << "\n";
        std::cout << "\nCorrect(y), Wrong(n): ";
        std::cin >> answer;
        if(answer == "y") {
            temp_deck[randNum].incrementCorrect();
            if (temp_deck[randNum].correct == 4){
                //Get the first element to add the index of the element that has to be removed if it reaches the limit
                auto it = temp_deck.begin(); 
                temp_deck.erase(temp_deck.begin() +randNum);
            }
        }
        if (delay == "q")
            break;
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

//TODO
void choose_deck() {
    char choice[2];
    std::cout << "These are the available decks: \n";
    for (const auto &entry: std::filesystem::directory_iterator("decks/"))
        std::cout << entry.path().string() << std::endl;
    std::cout << "Which deck do you want?\n";
    std::cin >> choice;
};

void create_new_deck() {
    const std::string decks_path = "decks/";
    std::cout << "What is the name of the Deck?" << std::endl;
    std::string deck_name;
    std::cin >> deck_name;
    std::string file = deck_name + ".txt";
    //TODO Before creating the file, check if its already in the deck
    std::ofstream filename("decks/" + file);
    filename.close();
    
}
