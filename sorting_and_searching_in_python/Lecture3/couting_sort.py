def counting_sort(arr):
	# in this implementation we will assume that we get only positive values
	# Space complexity O(n+k)
	# Time complexity O(n + k)
	max_element = max(arr)
	frequency = [0]*(max_element+1)

	# this loop will help to create the frequency list
	for i in range(0, len(arr)):
		frequency[arr[i]] += 1

	# now we need to prepare prefix sum
	for i in range(1, len(frequency)):
		frequency[i] = frequency[i] + frequency[i-1]

	# frequency[arr[i]] -> the position of the current value arr[i]

	output = [0]*len(arr)
	for i in range(len(arr)-1, -1, -1): # going from previous
		output[frequency[arr[i]] - 1] = arr[i]
		frequency[arr[i]] -= 1

	return output


li = [3,4,3,2,7,1,6,3]

output = counting_sort(li)

print(output)

