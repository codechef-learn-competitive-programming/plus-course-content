# TC - O(n)
n = int(input())
pos = []
spd = []
for i in range(n):
	x, y = input().split()
	x = int(x)
	y = int(y)
	pos.append(x)
	spd.append(y)

lo, hi = 0, 1e10

for j in range(0, 100):
	mid = lo + (hi - lo)/2 # some value of t
	main_lower_limit, main_upper_limit = -9999999999.0, 9999999999.0
	for i in range(n):
		lower_limit = pos[i] - mid*spd[i]
		upper_limit = pos[i] + mid*spd[i]
		main_upper_limit = min(main_upper_limit, upper_limit)
		main_lower_limit = max(main_lower_limit, lower_limit)

	if main_lower_limit <= main_upper_limit:
		hi = mid
	else:
		lo = mid


print("%0.6f"%hi)