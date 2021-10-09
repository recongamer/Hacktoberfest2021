import random
guesses=0
choice=1
while(choice==1):
    randomno= random.randint(1,100)
    userGuess= None
    while(userGuess!=randomno):
        userGuess=int(input("Enter your Guess: "))
        guesses=guesses+1
        if(userGuess==randomno):
            print(f"You have successfully guessed the correct number which was {randomno}")
        else:
            if(userGuess>randomno):
                if(userGuess-randomno<=10 and userGuess-randomno>=5):
                    print("Enter a slightly lower number!!!")
                elif(userGuess-randomno<=5):
                    print("U are so close!!! Enter a lower number")
                else:
                    print("Enter a lower Number!!!")
            else:
                if(randomno-userGuess<=10 and randomno-userGuess>=5):
                    print("Enter a slightly higher number!!!")
                elif(randomno-userGuess<=5):
                    print("U are so close!!! Enter a higher number")
                else:
                    print("Enter a higher Number!!!")
    print("________________________________________________________________________________")
    print(f"You have guessed the number in {guesses} guesses \n")    

    with open ("highscore.txt","r") as f:
        hs=int(f.read())
        if(hs!=0):
            if(guesses<hs):
                with open ("highscore.txt","w") as f:
                    f.write(str(guesses))
        else:
            with open ("highscore.txt","w") as f:
                    f.write(str(guesses))
        
    
    guesses=0

    choice=input("\nDo u want to play the game again?? |Y or y| for Yes and |N or n| for No: ")

    if(choice=="Y" or choice=="y"):
        choice=1
    elif(choice=="N" or choice=="n"):
        print("Thanks for playing!!!!")
        print("________________________________________________________________________________")
        break
    else:
        print("Wrong input Game Crash")
        print("________________________________________________________________________________")

with open ("highscore.txt","r") as f:
     print("The current highscore of the game is ",f.read(),"\n","\n")
