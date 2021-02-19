"""
Sets are same to same as dictionaries with just a differece that they only
have keys and no values associated with the keys
Sets are also unordered/Randomly stored like Dict
In Sets we cant have Duplicates
Sets are mutable
"""

s = {"Sanket", "Singh", 1,2,3,4}

print(s)
print(type(s))

S = {"Sanket", "Sanket"}
print(S)

s.remove(1)
print(s)

s.add(123)
print(s)

print(2 in s)