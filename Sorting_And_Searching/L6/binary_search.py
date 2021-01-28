def bin_search_rec(arr, beg, end, target):
    if (beg > end):
        return -1

    mid = (beg + end) / 2

    if (arr[mid] < target):
        return bin_search_rec(arr, mid + 1, end, target)

    if (arr[mid] > target):
        return bin_search_rec(arr, beg, mid - 1, target)

    return mid


def bin_search_iter(arr, n, target):
    beg = 0
    end = n - 1

    while (beg <= end):
        mid = (beg + end) / 2

        if (arr[mid] == target):
            return mid

        elif (arr[mid] > target):
            end = mid - 1

        else:
            beg = mid + 1

    return -1


def main():
    n = int(input())
    arr = list(map(int, input().split(' ')))
    x = int(input())

    print(bin_search_rec(arr, 0, n - 1, x))
    print(bin_search_iter(arr, n, x))


if __name__ == '__main__':
    main()
