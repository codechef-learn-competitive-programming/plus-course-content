def merge(arr, left, mid, right):
	temp = [0]*(right - left + 1)
	i, j, k, count = left, mid+1, 0, 0
	while i <= mid and j <= right:
		if arr[i] <= arr[j]:
			temp[k] = arr[i]
			i += 1
			k += 1
		else:
			count += (mid - i + 1)
			temp[k] = arr[j]
			j += 1
			k += 1

	while i <= mid:
		temp[k] = arr[i]
		i += 1
		k += 1
	while j <= right:
		temp[k] = arr[j]
		j += 1
		k += 1

	k = 0
	for i in range(left, right+1):
		arr[i] = temp[k]
		k += 1

	return count


def mergesort(arr, left, right):
	if left < right:
		mid = (left + right) // 2
		count_left = mergesort(arr, left, mid)
		count_right = mergesort(arr, mid+1, right)
		count_mergers = merge(arr, left, mid, right)
		return count_left + count_right + count_mergers

	return 0


t = int(input())

for i in range(0, t):
	ch = input()
	n = int(input())
	li = []
	for j in range(0, n):
		x = int(input())
		li.append(x)

	inv_cnt = mergesort(li, 0, n-1)
	print(inv_cnt)

