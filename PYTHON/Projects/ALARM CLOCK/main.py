import datetime as dt
from time import time
import playsound as ps
import time
import os 

hours = int(input("what hour you want to set alarm?: "))
minutes = int(input("what minutes you want to set alarm?: "))

am_or_pm = input("AM or PM ? : ")

if(am_or_pm == "PM" or am_or_pm == "pm"):
    hours = hours + 12

os.system("cls")

while(True):
    if(hours == dt.datetime.now().hour and minutes == dt.datetime.now().minute):
        print("WAKE UP!!!")
        while(True):
            ps.playsound("Alarm-Clock Sound!!!.mp3")
            time.sleep(2)
            


