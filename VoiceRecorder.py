#---------- VOICE RECORDER ----------------
#sounddevice scipy is a python library 

import sounddevice
from scipy.io.wavfile import write 

fs = 44100   #sample_rate
second = int(input("enter the time duration in second: "))

#enter your required time 

print("Recording....\n")

record_voice = sounddevice.rec(int(second * fs),samplerate = fs,channels = 2)
sounddevice.wait()

write("out.wav", fs,record_voice)

print("Finished..\nPlease Check It...")
