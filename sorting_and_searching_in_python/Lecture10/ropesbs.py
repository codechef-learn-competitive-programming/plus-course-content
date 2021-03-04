def isCutPossible(x, arr, k):
	sum = 0
	for i in range(0, len(arr)):
		sum += arr[i]//x
	return sum >= k

n, k = [int(x) for x in input().split()]
arr = []
for i in range(0, n):
	y = int(input())
	arr.append(y)

l, r = 0, 1e10
for i in range(0, 200):
	m = (l + r) / 2
	if isCutPossible(m, arr, k) == True:
		l = m
	else:
		r = m

print("%0.6f"%l)