def first_index(arr, x):
	ans = -1 # no valid candidate yet
	n = len(arr)
	lo, hi = 0, n - 1
	while lo <= hi:
		mid = lo + (hi - lo) // 2
		if arr[mid] >= x:
			# we have found new valid candidate to become ans
			ans = mid
			hi = mid - 1
		else:
			# here we dont find any new candidate so no update to the ans
			lo = mid + 1

	return ans

li = [int(x) for x in input().split()]
el = int(input())
print(first_index(li, el))
