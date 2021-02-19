"""
Dictionary stores elements in Key, Value form
"""

x = {"name": "Sanket", (100, 3): 22, "name": "LinkedIn", "nested_dict": {1: 3, 2: 4}}

print(x)
print(type(x))
# What will happen if we give two same keys ?????
# it will override the existing key's value

# given a key how to access values ???

print(x["name"], x[(100, 3)])

# dict are mutable

x["name"] = "Unacademy"
print(x)

# How to add a key value pair ???
x["location"] = "Bengaluru"

print(x)

# how we can delete a key value pair ?

del x[(100, 3)]

print(x)


print(x.get("querty"), x.get("location")) # get is another way to extract values where if you dont have a value in the first place then it will return None

# if you want to delete everything from a dict ???
# x.clear()

print(x)

# what if we want to print all the keys????
k = x.keys()
# print(k)
# what if we want to print all the values ????
v = x.values()
# print(v)

for i in k:
	print(i)

# iterate on values
for i in v:
	print(i)

for i in k:
	print(x[i])









