def subset(li, idx, output):
	"""
	li -> input list
	idx -> is used to point to current element
	output -> output string
	"""

	# base case
	if(idx == len(li)):
		print("[" +output+ "]")
		return

	subset(li, idx + 1, output) #exclude
	subset(li, idx + 1, output + str(li[idx]) + ", ") #include
	
	return


def subset_by_list(li, idx, output):
	if(idx == len(li)):
		print(output)
		return

	subset_by_list(li, idx+1, output)
	output.append(li[idx])
	subset_by_list(li, idx+1, output)
	# revert the action done on list
	output.pop()
	return



li = [1,2,3]
output = []
subset_by_list(li, 0, output)