import re

def DuplicateWordRemover(s):

	regX = r'\b(\w+)(?:\W+\1\b)+'

	return re.sub(regX, r'\1', s, flags=re.IGNORECASE)

str = "Hi Hi how are you you ?"

print(DuplicateWordRemover(str))
