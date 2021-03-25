def ternary_search(arr, el):
	lo, hi = 0, len(arr) - 1
	while lo <= hi:
		m1 = lo + (hi - lo) // 3
		m2 = hi - (hi - lo) // 3
		if arr[m1] == el:
			return m1
		if arr[m2] == el:
			return m2
		if arr[m1] > el:
			hi = m1 - 1
		elif arr[m2] < el:
			lo = m2 + 1
		else:
			lo = m1 + 1
			hi = m2 - 1

	return -1


