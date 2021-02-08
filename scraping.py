import requests, bs4

#The website we want to inspect
res = requests.get("https://www.dictionary.com/browse/psychology")
res.raise_for_status()
soup = bs4.BeautifulSoup(res.text, "html.parser")
elements = soup.select("div")

print(len(elements))
#Because each definition is inside a div tag with the "value=[num]" attribute
#we only have to find these tags and extract the text or information from it.
for item in elements:
    if "value" in item.attrs.keys():
        print(item.getText()+ "\n")


