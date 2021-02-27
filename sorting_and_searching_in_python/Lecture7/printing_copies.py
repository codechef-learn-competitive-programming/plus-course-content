def good(mid, n, x, y):
	return (mid//x) + (mid//y) >= n - 1

def printing_copies(n, x, y):
	if n == 1:
		return min(x, y)

	lo = 0
	hi = max(x, y)*n
	ans = -1
	while lo <= hi:
		mid = lo + (hi - lo) // 2
		if good(mid, n, x, y):
			ans = mid
			hi = mid - 1
		else:
			lo = mid + 1

	return ans + min(x, y)


n, x, y = [int(x) for x in input().split()]
print(printing_copies(n, x, y))
