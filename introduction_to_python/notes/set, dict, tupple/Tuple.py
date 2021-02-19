"""
Tuples are immutable collection of objects
"""

tup = (1,2,3, "Sanket", False, 5.67)

print(tup)

"""
# Tuples are immutable

tup[0] = 11 # this will give an error
"""

# How to access any individual element of a tuple ?? -> Just like a list
print(tup[0], tup[1]) # tuples are 0 based indedxed


# What are differences with list?
# -> we can update any individual element of a list but we cant do the same with a tuple


# Can we delete any element in tuple ? -> No as they are immutable

"""
Operations on Tuple
"""
print(tup*4) # repitition
print(tup)

print(3 in tup)

t1 = (1,2,3)
t2 = (4,5,6)

print(t1 + t2) # concatenation
print(t1)
print(t2)

print(tup[1:3]) # slicing just like lists

# what is the use of tuple ???????

def test():
	# we want to return multiple values from this function
	return 1,2,3,"Delhi", 45.6

x = test()
print(x)
print(type(x))


# can we change tuple to a list ? 
print(list(x))

y = [1,2,3,"Sanket"]
print(tuple(y))





