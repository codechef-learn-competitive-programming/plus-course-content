from random import randrange
def partition(arr, left, right):
	m = left
	pivot_index = randrange(left, right)# we chose the pivot randomly
	pivot = arr[pivot_index]
	arr[right], arr[pivot_index] = arr[pivot_index], arr[right]
	for i in range(left, right):
		if(arr[i] <= pivot):
			arr[i], arr[m] = arr[m], arr[i]
			m += 1

	arr[m], arr[right] = arr[right], arr[m]
	return m

def quicksort(arr, left, right):
	if left >= right:
		return

	pivot_index = partition(arr, left, right)
	quicksort(arr, left, pivot_index - 1)
	quicksort(arr, pivot_index+1, right)

	return

li = [1,9,3,4,1, 0]
n = len(li)
quicksort(li, 0, n-1)

print(li)
