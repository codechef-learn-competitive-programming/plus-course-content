def main():
    n = int(input())
    a = [0] + list(map(int, input().split(' ')))
    b = [0] * (n+2)

    m = int(input())
    while m:
        m -= 1
        l, r, x = map(int, input().split(' '))
        b[l] += x
        b[r + 1] -= x

	for i in range(1, n + 1):
		b[i] += b[i - 1]

	for i in range(1, n + 1):
		print(a[i] + b[i], end=' ')


if __name__ == '__main__':
    main()
