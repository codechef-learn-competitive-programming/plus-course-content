# O(t*n*logmax)
def good(mid, barn, cows):
	count = 1
	last_pos = barn[0]# the last stall where you put a cow
	for i in range(1, len(barn)):
		if barn[i] - last_pos >= mid: #dist between the last cow and current cow is atleast mid 
			count += 1 # yes put a cow here
			last_pos = barn[i]
		if count >= cows:
			return True

	return False

t = int(input())
for i in range(t):
	n, c = [int(x) for x in input().split()]
	barn = []
	for i in range(n):
		x = int(input())
		barn.append(x)


	barn.sort()	
	lo = 1
	hi = barn[len(barn) - 1]
	ans = -1
	while lo <= hi:
		mid = lo + (hi - lo)//2
		if good(mid, barn, c):
			ans = mid
			lo = mid + 1
		else:
			hi = mid - 1

	print(ans)



