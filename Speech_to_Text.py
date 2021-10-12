# We need to first install some libraries
# 1) Speech Recognititon: pip install SpeechRecognition
# 2) PyAudio: pip install pyAudio
# 3) Pyttsx3: pip install pyttsx3


import speech_recognition as sr
import pyttsx3

recog = sr.Recognizer()

def GiveCommand(gc):
    engine = pyttsx3.init()
    engine.say(gc)
    engine.runAndWait()

while (1):

    try:
        with sr.Microphone() as s:

            recog.adjust_for_ambient_noise(s, duration=0.2)
            audio2 = recog.listen(s)

            talk = recog.recognize_google(audio2)
            talk = talk.lower()

            print("You said: " + talk)
            GiveCommand(talk)

    except sr.RequestError as err:
        print("ERROR!!!")

    except sr.UnknownValueError:
        print("Unknown Error Occured!!")
