"""
1. Indexing of String -> Strings in python are 0-indexed
s = 'codechef'
s[0] = 'c'
s[1] = 'o'
s[2] = 'd'
.....
s[len(s) - 1] = 'f'

In python Strings are also indexed from -1 if we start from last character to the first
s[-1] = 'f'
s[-2] = 'e'
s[-3] = 'h'
"""

s = "codechef"

print(s[0], s[1], s[2], s[3], s[4], s[len(s) - 1])

print(s[-1], s[-2], s[-3], s[-4])

# -------------------------------------------

"""
2. Multiline strings -> we can have multiline strings using triple quotes
triple quotes can be either triple double quotes or triple single quotes
"""

a = """Thisis
amultiline 
string
"""

b = '''
Thisis 
amultiline
string'''

c = a + b
# print(a, b)

# print("Result of concatenation = ", c)

print(b[0], b[1], b[2], b[-1], len(b)) 
"""
if you have a multiline string which starts from a new line like b, then 
on the 0th index we will have new line character and the first character will be at index 1
whereas if we have a string like a, which starts just after quotes then 
first char is at index 0
"""
print(a[0], a[1], a[2], a[-1], len(a))



# -------------------------------------------

"""
3. Operators on strings
"""
first = "Sanket"
last = "Singh"
middle = "Singh"
print(first + last) # concatenation
print(first*3) # repition of string
# Comparison operators
print(first == last) # -> False
print(last == middle) # -> True
print(last != first) # -> True
print(last != middle) # -> False

# Comparison based on dictionary order
print("abc" < "def") # -> Acc to dictionary it should be yes
print("camel" > "apple") # -> true

print("Singh" == "singh") #-> false
print("Singh" > "singh") # based on ascii

print("aa" < "aab") # in dictionary also aa comes before aab

# membership operator
print("a" in first)
print("aa" in first)
print("ab" not in first)




# -------------------------------------------

"""
4. Mutability in strings
"""
li = [1,2,3,4,5]
li[2] = 22 # this will work
# why it works for list ??? because lists are mutable/updatable

st = "codechef"
st[2] = 'r' # this wont work because strings are not mutable












