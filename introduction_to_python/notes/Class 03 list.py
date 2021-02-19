# How to initialise a list ?? 
a = []
b = [1,2,3]
c = [1, 'a', "string", 4.5, 2+3j, False, -89, True]
print(a)
print(b)
print(c)

# How to add elements at the last in the list ??
b.append(33)
c.append(29)

# How is indexing done in lists of python ?? 
# -> same like flowcharts i.e. 0 based indexing

print(c[0], c[1], c[2])

# how can we take input from user and add in list ???
# n = 10
# arr = []
# while n > 0:
# 	x = input()
# 	arr.append(x)
# 	n = n-1

# print(arr)

# Are lists mutable ?? i.e can u update any element ?? Yes!!!
c[0] = "Sanket"
print(c)


# how can we manually print list ??
# i = 0
# while i < len(c):
# 	print(c[i], end = " ")
# 	i = i + 1

# -> Can we remove the elements from last just like how we added at last ?? yes
c.pop()
print(c)

#-----------------------

# Can we append multiple elements at once ?  yes 
c.extend([23, 'true', False, 45, 45, 45, 45, -9, 45])
print(c)

# How to remove from any specific index ???? 
c.pop(3)
print(c)

# Can we remove any specific element ???? 
c.remove(45)
print(c)

# Can we add any element at a specific index ?? Yes
c.insert(1, "Singh")
print(c)

# can we remove all the elements at once ??? yes
# c.clear()
# print(c)

# can we reverse the list ?? yes
c.reverse()
print(c)


### use help(list) to get all the functions

