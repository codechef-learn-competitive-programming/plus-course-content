import java.util.*;

class SelectionSort {
  static void selection_sort(int[] arr) {
    int n = arr.length;
    for (int i = 0; i < n - 1; ++i) {
      int min_id = i;

      for (int j = i + 1; j < n; ++j)
        if (arr[j] < arr[min_id])
          min_id = j;

      int temp = arr[min_id];
      arr[min_id] = arr[i];
      arr[i] = temp;
    }
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
      arr[i] = in.nextInt();
    }

    selection_sort(arr);

    for (int i = 0; i < n; i++) {
      System.out.print(arr[i] + " ");
    }
    in.close();
  }

}