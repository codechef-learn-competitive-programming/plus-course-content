def main():
    n, m = map(int, input().split(' '))
    v = [[0] * m] * n

    for i in range(n):
        for j in range(len(v[i])):
            print(v[i][j], end=' ')
        print()


if __name__ == '__main__':
    main()
