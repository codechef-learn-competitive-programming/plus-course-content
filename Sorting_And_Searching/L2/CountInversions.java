import java.util.*;

class CountInversions {
    static int merge(int[] arr, int start, int end) {
        int mid = start + (end - start) / 2;
        int i = start, j = mid, k = 0, count = 0;

        int[] temp = new int[end - start];

        while (i < mid && j < end) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                count += mid - i;
                temp[k++] = arr[j++];
            }
        }

        while (i < mid)
            temp[k++] = arr[i++];

        while (j < end) {

            temp[k++] = arr[j++];
        }

        for (int l = 0; l < temp.length; l++) {
            arr[l + start] = temp[l];
        }

        return count;
    }

    static int merge_sort(int[] arr, int start, int end) {
        if (start + 1 >= end)
            return 0;

        int mid = start + (end - start) / 2;

        int left = merge_sort(arr, start, mid);
        int right = merge_sort(arr, mid, end);

        int cross = merge(arr, start, end);

        return left + cross + right;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }

        int inversions = merge_sort(arr, 0, n);

        System.out.println(inversions);

        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        in.close();
    }

}