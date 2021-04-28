def main():
    n, m = map(int, input().split(' '))
    arr = [[0] * (m + 1)] * (n + 1)
    dp = [[0] * (m + 1)] * (n + 1)

    for i in range(1, n+1):
        arr[i] = list(map(int, input().split(' ')))
        for j in range(1, n+1):
            dp[i][j] = arr[i][j] + dp[i - 1][j] + \
                dp[i][j - 1] - dp[i - 1][j - 1]

    q = int(input())
    while q:
        q -= 1
        i1, j1, i2, j2 = map(int, input().split(' '))
        ans = (dp[i2][j2] - dp[i2][j1 - 1] -
               dp[i1 - 1][j2] + dp[i1 - 1][j1 - 1])
        print(ans)


if __name__ == '__main__':
    main()
