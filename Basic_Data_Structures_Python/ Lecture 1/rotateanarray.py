def reverse(li, s, e):
	while s < e:
		temp = li[s]
		li[s] = li[e]
		li[e] = temp
		s += 1
		e -= 1

def rotate_by_k(li, k):
	n = len(li)
	k = k%n
	reverse(li, 0, n-1)
	reverse(li, 0, k-1)
	reverse(li, k, n-1)


li = [int(x) for x in input().split()]

k = int(input())

rotate_by_k(li, k)

print(li)