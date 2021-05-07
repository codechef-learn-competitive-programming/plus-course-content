#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end, int pivot) {
    int placedCount = 0;
    for(int i=start; i < end;i++) {
        if(arr[i] < pivot) {
            swap(arr[start+placedCount], arr[i]);
            placedCount++;
        } else if(arr[i] == pivot) {
            swap(arr[i], arr[end]);
            i--;
        }
    }
    swap(arr[end], arr[start + placedCount]);
    return placedCount;
}

void sortBothArrays(int arr1[], int arr2[], int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = arr1[end];
    int pivotIdx = partition(arr2, start, end, pivot);
    partition(arr1, start, end, arr2[pivotIdx]);
    sortBothArrays(arr1, arr2, start, pivotIdx - 1);
    sortBothArrays(arr1, arr2, pivotIdx + 1, end);
}

void quickSort(int arr[], int start, int end) {
    if (start >= end){
        return;
    }
    srand(time(0));// this will basically set the seed to the current timestamp
    int pivotIdx = start + rand()%(end - start + 1);
    swap(arr[pivotIdx], arr[end]);
    int placedCount = 0;
    int pivot = arr[end];
    for(int i=start; i < end; i++) {
        if(arr[i] < pivot) {
            swap(arr[i], arr[placedCount + start]);
            placedCount++;
        }
    }
    swap(arr[end], arr[start + placedCount]);
    quickSort(arr, start, start + placedCount - 1);
    quickSort(arr, start + placedCount + 1, end);
}

int findMedian(int arr[], int start, int end, int position) {
    if(start == end) {
        return arr[start];
    }
    srand(time(0));// this will basically set the seed to the current timestamp
    int pivotIdx = start + rand()%(end - start + 1);
    swap(arr[pivotIdx], arr[end]);
    int placedCount = 0;
    int pivot = arr[end];
    for(int i=start; i < end; i++) {
        if(arr[i] < pivot) {
            swap(arr[i], arr[placedCount + start]);
            placedCount++;// NUMBER OF ELEMENT EXACTLY IN THE LEFT SIDE
        }
    }
    swap(arr[end], arr[start + placedCount]);
    // start + placedCount
    if(placedCount == position ) {
        return arr[start + placedCount];
    }
    else if(placedCount > position) {
        return findMedian(arr, start, start + placedCount - 1, position);
    } else {
        return findMedian(arr, start + placedCount + 1, end,  position - (placedCount + 1));
    }
}


int main() {
   /*int arr1[] = {2, 1, 3, 18, 16, 7};
   int arr2[] = {3, 1, 18, 7, 16, 2};
   sortBothArrays(arr1, arr2, 0, 5);
   for(int i=0;i<6;i++) {
       cout<<arr1[i] <<" "<<arr2[i]<<endl;
   }
   // Randomized Quick Sort
   int arr3[] = {1, 3, 2, 14, 6, 8, 12};
   quickSort(arr3, 0, 6);
   for(int i=0;i<7;i++){
       cout<<arr3[i]<<" ";
   }
   cout<<endl;*/
   /*srand(time(0));
   cout<<rand()%10<<endl;*/
   // Median of the array
   int arr[] = {1, 12, 6, 2, 7, 11, 14};
   int position = 3;
   // Quick Select
   int median = findMedian(arr, 0, 6, position);
   cout<<median<<endl;
}

