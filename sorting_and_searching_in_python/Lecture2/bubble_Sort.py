def bubble_sort(arr):
	for i in range(0, len(arr)):
		swapped = False # this variable ensures that as soon as the list is sorted we stop the algorithm
		for j in range(0, len(arr) - i - 1):
			if arr[j] > arr[j+1]:
				arr[j], arr[j+1] = arr[j+1], arr[j]
				swapped = True
		print(arr)
		if not swapped:
			return # why ?? because now the list will be sorted
	return

li = [5, 4, 3, 2, 1]

bubble_sort(li)

print(li)