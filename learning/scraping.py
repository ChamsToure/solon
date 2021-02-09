import requests, bs4
import os
import time
import speech_recognition as sr
import playsound

from gtts import gTTS

iteration = 0
def speak(text,num_of_iter):
    tts = gTTS(text=text, lang="en")
    filename = "voice" + str(num_of_iter)+".mp3"
    tts.save(filename)
    playsound.playsound(filename)

#The website we want to inspect
res = requests.get("https://www.dictionary.com/browse/psychology")
res.raise_for_status()
soup = bs4.BeautifulSoup(res.text, "html.parser")
elements = soup.select("div")

definitions = []

print(len(elements))
#Because each definition is inside a div tag with the "value=[num]" attribute
#we only have to find these tags and extract the text or information from it.
for item in elements:
    if "value" in item.attrs.keys():
        definitions.append(item.getText())
        print(item.getText()+ "\n")

for i in definitions:
    speak(i, iteration)
    iteration +=1
speak("hello chams")
