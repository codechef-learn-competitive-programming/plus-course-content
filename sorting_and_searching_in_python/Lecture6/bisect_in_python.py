import bisect

arr = [int(x) for x in input().split()]

while True:
	ch = input()
	if ch == 'l':
		x = int(input())
		print(bisect.bisect_left(arr, x)) # O(logn)
	elif ch == 'r':
		x = int(input())
		print(bisect.bisect_right(arr, x)) # O(logn)
	else:
		break