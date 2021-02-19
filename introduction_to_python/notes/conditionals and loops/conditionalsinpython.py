# Let's start with 'if'
if 10 < 5:
	# we will start a new block and whatever is there in the block will be executed if the condition is true
	print("10 is greater than 5") # this is the start of a new block
	x = 12 # this is in same block as of the above statement

	print(x**2) # this is in same block as of the above statement
	print("one more level of indentation") # this is another blok so gives error

else: # else will say give me a new block
	print("doing something when condition is false")

print("end of if") # this is a separate block now


print("hello")
	# print("world") # we cant randomly give blocks in between

# here line 3, 11, 14 lies in same level of indentation so same block

a = 10
b = 2
operator = input()

if operator == '+':
	print(a+b)
elif operator == '-':
	print(a-b)
elif operator == '*':
	print(a*b)
else:
	print(a/b)


# if operator == '+':
# 	print(a+b)
# elif operator == '-':
# 	print(a-b)
# elif operator == '*':
# 	print(a*b)
# elif operator == '/':
# 	print(a/b)


# nested if elif else

if 10 > 5: 
	if 5 < 3:
		print("first nested if")
	elif 4 > 2:
		if 3 < 4:
			print("second nested if inside elif")
			print("hi"*3)
		else:
			print("else inside first elif")
	elif 17 > 8:
		print("second elif")
	else:
		print("else")
elif 4 % 2 == 0:
	print("end")



