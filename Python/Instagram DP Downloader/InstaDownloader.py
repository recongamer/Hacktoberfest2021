import instaloader
from PIL import ImageTk, Image
import tkinter as tk
from tkinter import messagebox

win = tk.Tk()
win.title('InstaGram DP Downloader')


def dpDownload():
    ig = instaloader.Instaloader()
    profile = entry.get()
    ig.download_profile(profile, profile_pic_only=True)
    messagebox.showinfo("Status", "Image Download Successfully")


img = Image.open("ig.png")
img = img.resize((200, 200), Image.ANTIALIAS)
resized_img = ImageTk.PhotoImage(img)

title = tk.Label(win, text="Instagram DP Downloader", font=("Times", 20, "bold"))
title.grid(row=0, column=0, columnspan=5, padx=30, pady=10)

image = tk.Label(win, image=resized_img)
image.grid(row=2, column=0, columnspan=5, pady=20)

label2 = tk.Label(win, text="Enter Username: ", font=("Arial", 10))
label2.grid(row=3, column=0)

entry = tk.Entry(win, width=40)
entry.grid(row=3, column=1, columnspan=3)

btn = tk.Button(win, text="Download", command=dpDownload)
btn.grid(row=4, column=0, columnspan=5, pady=10)

win.mainloop()
