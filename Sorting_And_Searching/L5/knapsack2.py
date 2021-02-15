def main():
    t = int(input())
    while t:
        t -= 1
        n, k = map(int, input().split(' '))
        a = list(map(int, input().split(' ')))
        a.sort()

        i = 0
        j = n - 1
        ans = 0

        while (i <= j):
            if (a[i] + a[j] > k):
                j -= 1
            else:
                i += 1
                j -= 1
            ans += 1

        print(ans)


if __name__ == '__main__':
    main()
