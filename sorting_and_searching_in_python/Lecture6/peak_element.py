def find_peak(arr):
	lo, hi = 0, len(arr) - 1
	while lo < hi :
		mid = lo + (hi - lo) // 2
		if arr[mid] > arr[mid+1]:
			# case 2
			hi = mid
		else:
			lo = mid + 1

	return lo