#9 23 30 44 58 72 73 78
#5

def good(arr, s, mid):
	students_req = 1
	pages_read_by_curr_student = 0
	for i in range(len(arr)):
		if arr[i] > mid:
			return False
		if pages_read_by_curr_student + arr[i] > mid:
			students_req += 1
			pages_read_by_curr_student = arr[i]

			if students_req > s:
				return False
		else:
			pages_read_by_curr_student += arr[i]

	return True

def books(arr, s):
	lo, hi = 0, sum(arr)
	ans = 10**9
	while lo <= hi:
		mid = lo + (hi - lo)//2
		if good(arr, s, mid):
			hi = mid - 1
			ans = mid
		else:
			lo = mid + 1
	return ans

arr = [int(x) for x in input().split()]
m = int(input())
print(books(arr, m))
