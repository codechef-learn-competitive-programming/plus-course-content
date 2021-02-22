def binary_search_on_rotated_list(arr, target):
	n = len(arr)
	start, end = 0, n - 1

	while(start <= end):
		mid = start + (end - start) // 2
		if(arr[mid] == target):
			return mid
		elif arr[mid] >= arr[start] :
			# case 1
			if target >= arr[start] and target < arr[mid] :
				end = mid - 1
			else:
				start = mid + 1
		else:
			# case 2
			if target <= arr[end] and target > arr[mid] : 
				start = mid + 1
			else:
				end = mid - 1

	return -1


li = [int(x) for x in input().split()] # take input of integer list in single line

target = int(input())

print(binary_search_on_rotated_list(li, target))
