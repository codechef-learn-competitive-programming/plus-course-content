def main():
    n = int(input())
    a = list(map(lambda x: bool(int(x)), input().split(' ')))
    a = [False] + a
    b = [False] * (n + 2)

    q = int(input())
    while q:
        q -= 1
        l, r = map(int, input().split(' '))
        b[l] ^= True
        b[r + 1] ^= True

    for i in range(n + 1):
        b[i] ^= b[i - 1]

    for i in range(n + 1):
        a[i] ^= b[i]

    a = a[1:]
    print(a)


if __name__ == '__main__':
    main()
