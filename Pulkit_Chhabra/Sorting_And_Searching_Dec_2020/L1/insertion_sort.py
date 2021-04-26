def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        x = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > x:
            arr[j+1] = arr[j]
            j -= 1

        arr[j+1] = x


def main():
    n = int(input())
    arr = list(map(int, input().split(' ')))

    insertion_sort(arr)

    for num in arr:
        print(num, end=" ")


if __name__ == "__main__":
    main()
