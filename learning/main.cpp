#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include "deck.cpp"
#include <memory>
using namespace std;

/* vector<string> questions, answers;
    ifstream ifs("test.txt");
    if(ifs.is_open()) {
        int counter {0};
        string line;
        std::map<string,vector<string>> deck;
        string last_question;
        while(getline(ifs, line)){
            if (line.back() == '?'){
                deck[line];
                cout << "The question is: " << line << "\n";
                last_question = line;
                cout << "The last_question is: " << last_question << "\n";
            }
            else if (line.size()>3){
                deck[last_question].push_back(line);
                cout << "The line is: " << line << "\n";
            }
                
            }
        auto test = deck.begin();
        cout << test->first << " : "<<test->second[0] <<endl;
    }
*/ 
int main() {
    std::string file {"test.txt"};
    std::shared_ptr<Deck> firstdeck = std::make_shared<Deck>(file);
}
