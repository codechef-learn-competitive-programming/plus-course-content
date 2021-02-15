def merge(arr,  start,  end):
    mid = start + (end - start) // 2
    i = start
    j = mid
    k = 0

    temp = list(range(end - start))

    while i < mid and j < end:
        if (arr[i] <= arr[j]):
            temp[k] = arr[i]
            k += 1
            i += 1
        else:
            temp[k] = arr[j]
            k += 1
            j += 1

    while (i < mid):
        temp[k] = arr[i]
        k += 1
        i += 1

    while (j < end):
        temp[k] = arr[j]
        k += 1
        j += 1

    for idx, num in enumerate(temp):
        arr[idx + start] = num


def merge_sort(arr,  start,  end):
    if (start + 1 >= end):
        return 0

    mid = start + (end - start) // 2

    merge_sort(arr, start, mid)
    merge_sort(arr, mid, end)

    merge(arr, start, end)


n = int(input())
arr = list(map(int, input().strip().split()))

merge_sort(arr, 0, n)

print(arr)
