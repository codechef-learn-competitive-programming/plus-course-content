import java.util.*;

class QuickSort {
    static int partition(int[] arr, int l, int r) {
        int i = l;
        for (int j = l; j <= r; ++j)
            if (arr[j] <= arr[r]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
            }

        return i - 1;
    }

    static void quick_sort(int[] arr, int l, int r) {
        if (l >= r)
            return;

        int p_i = partition(arr, l, r);
        quick_sort(arr, l, p_i - 1);
        quick_sort(arr, p_i + 1, r);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }

        quick_sort(arr, 0, n - 1);

        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        in.close();
    }
}