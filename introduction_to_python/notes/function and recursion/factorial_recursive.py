def fact(n):
	if n == 1: # base case
		return 1

	value = fact(n - 1) # assume this works correctly
	ans = n * value # self work ans -> f(n)
	return ans


print(factmini(4))
