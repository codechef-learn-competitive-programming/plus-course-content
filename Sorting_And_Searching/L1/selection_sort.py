def selection_sort(arr):
    n = len(arr)
    for i in range(n-1):
        min_id = i

        for j in range(i + 1, n):
            if arr[j] < arr[min_id]:
                min_id = j

        temp = arr[min_id]
        arr[min_id] = arr[i]
        arr[i] = temp


def main():
    n = int(input())
    arr = list(map(int, input().split(' ')))

    selection_sort(arr)

    for num in arr:
        print(num, end=" ")


if __name__ == "__main__":
    main()
