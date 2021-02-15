macbook = {
	'name': 'Macbook',
	'price': 200000,
	'company': 'Apple'
}

sceptre = {
	'name': 'Sceptre',
	'price': 100000,
	'Company': 'HP'
}

yoga = {
	'name': 'Yoga',
	'price': 750000,
	'Company': 'Lenovo'
}

li = [yoga, macbook, sceptre] # list of dictionaries where each dictionary has data about any product


print(li)

li_of_num = [7, 8, -1, 0, 9, 5]

print("Before sorting", li_of_num)

# If you want to sort the same list

li_of_num.sort() # use the sort function on the list

print("After sorting in ASC order", li_of_num)

li_of_num2 = [7, 8, -1, 0, 9, 5]

print("Before sorting", li_of_num2)

li_of_num2.sort(reverse = True)


print("After sorting in DESC order", li_of_num2)


# if you don't want to sort the same list and want to return a new one ??

li_new = [3,7,1,9,2,0]

print("Befor sorting ", li_new)
result = sorted(li_new) # it returns a new sorted list
print("After sorting", li_new)
print("Result = ", result)





