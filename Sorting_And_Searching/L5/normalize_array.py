def main():
    t = int(input())
    while t:
        t -= 1
        n = int(input())
        v = list(map(int, input().split(' ')))
        v.sort()

        p = [0]
        for i in range(1, n + 1):
            p.append(p[-1] + v[i - 1])

        ans = 1e18

        for i in range(1, n + 1):
            ans = min(
                ans,
                (i - 1) * v[i] - p[i - 1] + p[n] - p[i] - (n - i) * v[i]
            )

        print(ans)


if __name__ == '__main__':
    main()
