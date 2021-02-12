#include "search.h"
#include <windows.h>
#include <shellapi.h>
#include <tchar.h>
#include <fstream>
#include <algorithm>
#include <cctype>
/*The searchWord feature only works on windows because of the sehllExecute function
 * But you can implement it by yourself for macOS or Linux
 * It basically opens a string in your browser.
 */
void searchWord() {
    std::cout << "What are you looking for?\n";
    std::string word, search, base_url2, search2;
    const std::string base_url = "www.dictionary.com/browse/";
    base_url2 = "https://en.wikipedia.org/wiki/";
    std::cin >> word;
    search = base_url + word;
    search2 = base_url2 + word;
    checkWord(word);
    //Only works on windows
    ShellExecute(0, _T("open"), search.c_str(), 0, 0, 0);
    ShellExecute(0, _T("open"), search2.c_str(), 0, 0, 0);

};

void checkWord(const std::string& the_word) {
    const std::ifstream ifs("words.txt");
    
 
    if(ifs.is_open()) {
        bool isInFile = false;
        std::string line;
        while(getline(ifs, line)) {
            //transform the first charater of the line to lowercase
            std::transform(line.begin(), line.end(),line.begin(), [](unsigned char c)
                    {return std::tolower(c);});
            if (the_word == line){
                std::cout << "YES IT IS IN FILE\n";
                isInFile = true;
            }
        }
        ifs.close();
        if (!isInFile) {
            std::cout << "It is not in file and will be added!\n";
            std::ofstream ofs("words.txt",std::ofstream::app);
            ofs << the_word << std::endl;
            ofs.close();
        } 
    }
    
};
