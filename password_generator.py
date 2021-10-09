import string as str
import secrets
import random

class PasswordGenerator:
    def gen_sequence(
            conditions,
    ):
        possible_characters = [
                str.ascii_lowercase,
                str.ascii_uppercase,
                str.digits,
                str.punctuation,
        ]
        sequence = ""
        for x in range(len(conditions)):
            if conditions[x]:
                sequence += possible_character[x]
            else:
                pass
        return sequence


    def gen_password(sequence, passlength=8):
        password = "".join((secrets.choice(sequence) for i in range(passlength)))
        return password

class Interface:
    has_characters = {
        "lowercase": True,
        "uppercase": True,
        "digits": True,
        "punctuation": True,
    }

    def change_has_characters(cls, change):
        try:
            cls.has_characters[
                    change
            ]
        except Exception as err:
            print(f"Invalid \nan Exception: {err}")
        else:
            cls.has_characters[change] = not cls.has_characters[
                change
            ]
            print(f"{change} is now set to {cls.has_characters[change]}")
    def show_has_charcters(cls):
        print(cls.has_characters)

    def generate_password(self, length):
         sequence = PasswordGenerator.gen_sequence(list(self.has_characters.values()))
        print(PasswordGenerator.gen_password(sequence, lenght))
    def list_to_vertical_string(list):
        to_return = ""
        for member in list:
            to_return += f"{member}\n"
        return to_return
class Run:
    def decide_operation(self):
        user_input = input(": ")
        try:
            int(user_input)
        except:
            Interface.change_has_characters(user_input)
        else:
            Interface().generate_password(int(user_input))
        finally:
            print("\n\n")

    def run(self):
        menu = f

        print(menu)
        while True:
            self.decide_operation()

Run().run()
