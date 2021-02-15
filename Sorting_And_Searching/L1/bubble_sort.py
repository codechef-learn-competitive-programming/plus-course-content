def bubble_sort(arr):
    n = len(arr)
    for itr in range(n):
        swapped = False
        for i in range(n - itr - 1):
            if arr[i] > arr[i + 1]:
                temp = arr[i]
                arr[i] = arr[i + 1]
                arr[i + 1] = temp
                swapped = True

        if not swapped:
            break


def main():
    n = int(input())
    arr = list(map(int, input().split(' ')))

    bubble_sort(arr)

    for num in arr:
        print(num, end=" ")


if __name__ == "__main__":
    main()
