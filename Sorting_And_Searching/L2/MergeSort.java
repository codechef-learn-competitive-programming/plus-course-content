import java.util.*;

class MergeSort {
    static void merge(int[] arr, int start, int end) {
        int mid = start + (end - start) / 2;
        int i = start, j = mid, k = 0;

        int[] temp = new int[end - start];

        while (i < mid && j < end) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i < mid)
            temp[k++] = arr[i++];

        while (j < end)
            temp[k++] = arr[j++];

        for (int l = 0; l < temp.length; l++) {
            arr[l + start] = temp[l];
        }

    }

    static void merge_sort(int[] arr, int start, int end) {
        if (start + 1 >= end)
            return;

        int mid = start + (end - start) / 2;

        merge_sort(arr, start, mid);
        merge_sort(arr, mid, end);

        merge(arr, start, end);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }

        merge_sort(arr, 0, n);

        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        in.close();
    }

}