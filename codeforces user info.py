# Please do ensure that you have the following modules installed before running the code

import requests
from prettytable import PrettyTable
import json

from requests import status_codes
userHandle = input("Enter your codeforces handle: ")
if userHandle.__contains__(";"):
    print("ERROR! Invalid handle")
else:
    data = requests.get("https://codeforces.com/api/user.info?handles=" + userHandle)
    contests = requests.get("https://codeforces.com/api/user.rating?handle=" + userHandle)
    if data.status_code < 300 and contests.status_codes < 300:
        data = json.loads(data.content)['result'][0]
        contests = json.loads(contests.content)['result']
        def contestsInfo(contests):
            if contests:
                x = PrettyTable()
                x.field_names = ["Contest", "Rank", "Rating Change"]
                for entry in contests:
                    if entry['newRating'] > entry['oldRating']:
                        x.add_row([entry['contestName'], entry['rank'], "+" + str(entry['newRating'] - entry['oldRating'])])
                    elif entry['newRating'] < entry['oldRating']:
                        x.add_row([entry['contestName'], entry['rank'], "-" + str(entry['oldRating'] - entry['newRating'])])
                    else:
                        x.add_row([entry['contestName'], entry['rank'], "0"])
                print("\n\nRecent Contests:")
                print(x)
            else:
                print("----------No Rated Contests to Show----------")


        def info(data):
            res = "Handle: "
            res += data['handle']
            if 'rank' in data:
                res += "\n" + data['rank']
            if 'firstName' in data or 'lastName' in data:
                if 'firstName' in data:
                    res += "\nName: " + data['firstName']
                if 'lastName' in data:
                    res += " " + data['lastName']
            if 'city' in data:
                res += "\nCity: " + data['city']
            if 'organization' in data:
                res += "\nOrganisation: " + data['organization']
            if 'rating' in data:
                res += "\nRating: " + str(data['rating']) 
                res += "\nMax Rating: " + str(data['maxRating'])
            else:
                res += "\nUnrated"
            res += "\nFriend of " + str(data['friendOfCount']) + " users"
            return res

        print(info(data))
        contestsInfo(contests)
    else:
        print("ERROR! Please try again. You could:")
        print("- Check if the handle entered is a valid Codeforces handle")
        print("- Check your internet connection")
