s = "sanket"
t = "singh"
# Concatenation on string
print(s + t)

# replicate the string
print((s+" ")*3)

# Replication on list

li = [1,2,3]
print(li*3) # it makes a new list
print(li)

print(li + [2,3,4]) # it makes a new list
print(li)

li.extend([2,3,4]) # it makes changes in original list
print(li)

li = li + [1,2,3] # this still makes a new list but assigns to li


# We know that indexing in list starts from 0 (from left)
# we have another indexing starting from -1 (from right)

# a = " sanket " + 2 # this gives error
a = "sanket " + str(2)
print(a)

