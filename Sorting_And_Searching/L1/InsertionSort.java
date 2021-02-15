import java.util.*;

class InsertionSort {
  static void insertion_sort(int[] arr) {
    int n = arr.length;
    for (int i = 1; i <= n - 1; ++i) {
      int x = arr[i];
      int j = i - 1;

      while (j >= 0 && arr[j] > x) {
        arr[j + 1] = arr[j];
        j--;
      }

      arr[j + 1] = x;
    }
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
      arr[i] = in.nextInt();
    }

    insertion_sort(arr);

    for (int i = 0; i < n; i++) {
      System.out.print(arr[i] + " ");
    }
    in.close();
  }

}