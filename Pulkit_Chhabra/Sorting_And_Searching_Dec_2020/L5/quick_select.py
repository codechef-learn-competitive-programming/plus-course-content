import random


def partition(arr, l, r):
    idx = random.randint(l, r)

    def swap(a, b):
        temp = arr[b]
        arr[b] = arr[a]
        arr[a] = temp

    swap(r, idx)

    i = l
    for j in range(l, r + 1):
        if arr[j] <= arr[r]:
            swap(i, j)
            i += 1

    return i - 1


def quick_select(arr, l, r, k):
    if (l > r):
        return -1

    p_i = partition(arr, l, r)

    if (p_i == k - 1):
        return arr[p_i]

    if (p_i > k - 1):
        return quick_select(arr, l, p_i - 1, k)

    return quick_select(arr, p_i + 1, r, k)


def main():
    t = int(input())
    while t:
        t -= 1
        n = int(input())
        arr = list(map(int, input().split(' ')))
        k = int(input())

        print(quick_select(arr, 0, n - 1, k))


if __name__ == '__main__':
    main()
