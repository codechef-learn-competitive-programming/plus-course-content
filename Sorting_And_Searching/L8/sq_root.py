def f2(n, p):
    beg = 1.0
    end = min(n,  2e9)
    range_of_p = 10 ** (-p)

    while (end - beg > range_of_p):
        mid = (beg + end) / 2.0

        print(beg, end, mid)

        if (mid * mid <= n):
            beg = mid

        else:
            end = mid

    return end


def main():
    n, p = map(int, input().split(' '))
    ans = f2(n, p)
    print('{0:.{1}f}'.format(ans, p))


if __name__ == '__main__':
    main()
