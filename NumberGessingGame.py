# A Number Guessing Game In Python
import random


flag = True
while flag:
 number = input("Please Enter The Upper Bound Of The Number You Wanna Guess From ")

 if number.isdigit():
    print("Lets Start The Game")
    number = int(number)
    flag = False
else:
     print("Invalid Input ")

generatedNumber = random.randint(1, number)

guess = None
count = 1

while guess != generatedNumber:
    guess = input("Please Enter Your A Number Between 1 and "+ str(number)  + ":")

    if guess.isdigit():
     guess = int(guess)


    if guess == generatedNumber:
          print("You Got It ")

    else:
         print("Try Again")
         count += 1

         print("It Took You", count, "to guess", generatedNumber)





