def max_cows(k, x):
    n = len(x)
    ans = 1
    last_cow_pos = x[0]

    for i in range(1, n):
        if (x[i] - last_cow_pos >= k):
            ans += 1
            last_cow_pos = x[i]

    return ans


def main():
    t = int(input())
    while t:
        t -= 1
        n, c = map(int, input().split(' '))
        x = list(map(int, input().split(' ')))
        x.sort()

        beg = 0
        end = x[n - 1]
        ans = 0

        while (beg <= end):
            mid = (beg + end) / 2

            if (max_cows(mid, x) >= c):
                ans = mid
                beg = mid + 1
            else:
                end = mid - 1

        print(ans)


if __name__ == '__main__':
    main()
