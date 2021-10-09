from tkinter import *

window = Tk()
window.minsize(width=100,height=200)
window.config(padx=20, pady=20)

def cal():
    km =float(input.get()) 
    label2["text"] = 0.62*km

new_label = Label(text="is equal to")
new_label.grid(column=0, row=1)

input = Entry()
input.grid(column=1, row=0)

label1 = Label(text="km")
label1.grid(column=2, row=0)

label2 = Label(text=0)
label2.grid(column=1, row=1)

label3 = Label(text="miles")
label3.grid(column=2, row=1)

btn = Button(text="Calculate" ,command=cal)
btn.grid(column=1,row=2)

window.mainloop()