import java.util.*;

class BubbleSort {
  static void bubble_sort(int[] arr) {
    int n = arr.length;
    for (int iter = 0; iter < n - 1; ++iter) {
      boolean swapped = false;

      for (int i = 0; i + 1 < n - iter; ++i)
        if (arr[i] > arr[i + 1]) {
          int temp = arr[i];
          arr[i] = arr[i + 1];
          arr[i + 1] = temp;
          swapped = true;
        }

      if (!swapped)
        break;
    }
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
      arr[i] = in.nextInt();
    }

    bubble_sort(arr);

    for (int i = 0; i < n; i++) {
      System.out.print(arr[i] + " ");
    }
    in.close();
  }

}