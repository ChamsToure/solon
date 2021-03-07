# Solon
A Virtual Assistant to improve productivity and learning.

## Features
- using voice or keyboard shortcut to search for definitions and explanation of words or concepts 
- save the searched words as a flashcard or add cards by yourself 
- transform your personal notes automatically into flashcards
- create your own decks
- start learning sessions with a goal of correct answers for each card in the choosen deck

## Requirements
- If you want to use the search feature and are not on windows,
you have to change line 21 and 22 inside the search.cpp folder because it only
works on windows.

## Before Building
### Setting up the browser
1. set your default browser. You can find the option in the search/search.cpp file.
If you use Chromium for example:
```
system(("chromium -new-tab " + search2).c_str()); 
```
Basically you just replace chromium with your default browser:
* For google chrome: google-chrome or google-chrome-stable (on linux)
* For Firefox: firefox
2. On windows you can also uncomment the ShellExecute function to enable the browser. This method may
be easier if you run into issues with the browser set up.

## How to build
- cd to project root directory
- mkdir build 
- cd build
- cmake ..
- make
- ./solon


## Python packages
- beautifulsoup
- SpeechRecognition
- gTTS

## How to use?
- First of all I would recommend to set it as a keyboard shortcut, to use it effortless, quickly and intuitively.
- If you already have a collection of notes, you can turn them easily into flashcard:
    1. Create a .txt file inside /solon/examples/decks/
    2. Copy your entire notes document into the .txt file
    3. Mark the front of the card with a question mark "?" at the end.
    4. Save the file and the programm will automatically set the front and back of each card

## Information
- If you have your own ideas and want contribute or want to make your own version feel free to use it.
