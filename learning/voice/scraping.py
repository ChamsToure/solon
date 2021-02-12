import requests, bs4
import os
import time
import speech_recognition as sr
import playsound
from commands import *
from gtts import gTTS

iteration = 0

def speak(text,num_of_iter):
    tts = gTTS(text=text, lang="de")
    filename = "voice" + str(num_of_iter)+".mp3"
    tts.save(filename)
    playsound.playsound(filename)

#function that listens to the connected microphone and convert the speech into text
def get_audio():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        audio = r.listen(source)
        said = ""

        try:
            said = r.recognize_google(audio, language='de-DE')
            print(said)
        except Exception as e:
            print("Exception: "+ str(e))
    return said

speak("hallo chams",1)
the_word = get_audio()

#The website we want to inspect
res = requests.get("https://www.dictionary.com/browse/" + the_word)
res.raise_for_status()
soup = bs4.BeautifulSoup(res.text, "html.parser")
elements = soup.select("div")

definitions = []

#print(len(elements))
#Because each definition is inside a div tag with the "value=[num]" attribute
#we only have to find these tags and extract the text or information from it.
for item in elements:
    if "value" in item.attrs.keys():
        definitions.append(item.getText())
        #print(item.getText()+ "\n")

#will print the first two definitions if available
if len(definitions) > 1:
    print(definitions[0])
    print(definitions[1])
else:
    print(definitions[0])
#each definition will be spoke by the assistant and saved as a file with the iteration number
#for i in definitions:
#    speak(i, iteration)
#    iteration +=1

search_browser(the_word)

