import os
import requests
from bs4 import BeautifulSoup
from babel.numbers import format_currency

os.system("clear")

def research():
    number = input("#: ")

    try :
        number = int(number)
        if number not in range(len(country)):
            print("Choose a number from list.")
            return research()
        else:
            return number
    except ValueError :
        print("That wasn't a number.")
        return research()

def money() :
    n = input("#: ")

    try :
        n = int(n)
        return n
    except ValueError :
        print("That wasn't a number.")
        return money()

def currency(code1, code2) :
    URL2 = f"https://wise.com/gb/currency-converter/{code1}-to-{code2}-rate?amount=50"
    url_result2 = requests.get(URL2)
    url_soup2 = BeautifulSoup(url_result2.text, "html.parser")
    str2 = url_soup2.find("span", {"class": "text-success"}).string

    return float(str2)

URL = "https://www.iban.com/currency-codes"
url_result = requests.get("https://www.iban.com/currency-codes")
url_soup = BeautifulSoup(url_result.text,"html.parser")
str = url_soup.find("table",{"class":"table table-bordered downloads tablesorter"}).find_all("td")

country = []
code = []
remove = []

for i in range(len(str)) :
    if i % 4 == 0 :
        country.append(str[i].string)
    elif i % 4 == 2 :
        code.append(str[i].string)

for j in range(len(code)) :
    if code[j] == None :
        del country[j]
        remove.append(j)

for z in range(len(remove)) :
    del code[remove[z]]

print("Hello! Please choose select a country by number")
for n in range(len(country)) :
    print(f"# {n} {country[n].capitalize()}")

find1 = research()

print(f"{country[find1]}\n\nNow choose another country.\n")

find2 = research()
print(f"{country[find2]}\n\nHow many {code[find1]} do you want to convert to {code[find2]}?")

find3 = money()
output = currency(code[find1],code[find2])
result = output*find3
find3 = format(find3,",")
print(f"{code[find1]}{find3} is",format_currency(result, "KRW", locale="ko_KR"))