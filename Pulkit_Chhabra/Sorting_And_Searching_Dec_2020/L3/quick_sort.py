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


def quick_sort(arr,  l,  r):
    if (l >= r):
        return

    p_i = partition(arr, l, r)
    quick_sort(arr, l, p_i - 1)
    quick_sort(arr, p_i + 1, r)


n = int(input())
arr = list(map(int, input().strip().split()))

quick_sort(arr, 0, n-1)

print(*arr)
