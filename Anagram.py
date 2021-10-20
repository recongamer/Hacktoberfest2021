def is_anagram(s, s1):
  if len(s)!= len(s1):
    return False

  else :
    for i, j in zip(s,s1):
      if 1!=j:
        return False
      return True

s= "CIDER"
s1= "CRIED"
s= sorted(s.lower())
s1= sorted(s1.lower())
res= is_anagram (s, s1)
if res == False:
  print("Anagram")
else:
  print("Not Anagram")
