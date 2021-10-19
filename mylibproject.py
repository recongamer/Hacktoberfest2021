class Library:
    def __init__(self,ListOfBooks):
        self.books= ListOfBooks
    
    def displayAvailableBooks(self):
        print("The books present in this library are: ")
        for book in self.books:
            print("\t*"+book)

    def borrowBook(self,BookName):
        if(BookName in self.books):
            print(f"U have been issued {BookName}. Please keep it safe and return it within a month")
            self.books.remove(BookName)
            return True
        else:
            print("This book has already been issued to someone else. Please wait until the book is returned")
            return False

    def returnBook(self,BookName):
        self.books.append(BookName)
        print("Thanks for returning this book. Hope u enjoyed reading it!!!")

class Student:
    def requestBook(self):
        self.book= input("Enter the name of the book u want to borrow: ")
        return self.book

    def returnBook(self):
        self.book= input("Enter the name of the book u want to return: ")
        return self.book

if __name__=="__main__":
    centralLibrary= Library(["Algo","Ds","HC VERMA","Python Notes","Django"])
    studentobj=Student()


    while(True):
        welcomeMsg='''======= Welcome To Central Library ======
        Please choose an option:
        1. Listing all books
        2. Request a Book
        3. Return a Book
        4. Exit the Library'''
        
        print(welcomeMsg)
        a = int(input("Enter a choice: "))
        if a == 1:
            centralLibrary.displayAvailableBooks()
        elif a == 2:
            centralLibrary.borrowBook(studentobj.requestBook())
        elif a == 3:
            centralLibrary.returnBook(studentobj.returnBook())
        elif a == 4:
            print("Thanks for choosing Central Library. Have a great day ahead!")
            exit()
        else:
            print("Invalid Choice!")
