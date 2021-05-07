#include <bits/stdc++.h>
using namespace std;

/*int maxElement(int arr[], int start, int end) {
    int sz = end - start + 1;
    // Base case
    if(sz == 1) {
        return arr[start];
    }
    int mid = start + (end - start)/2;
    int mxFromPart1 = maxElement(arr, start, mid);
    int mxFromPart2 = maxElement(arr, mid + 1, end);

    return max(mxFromPart1, mxFromPart2);
}*/

int procedure(int arr[], int start, int mid, int end) {
    int invCount = 0;
    int leftArrSize = mid - start + 1;
    int rightArrSize = end - mid;
    int leftArr[leftArrSize];
    int rightArr[rightArrSize];
    for(int i=0;i<leftArrSize; i++) {
        leftArr[i] = arr[start+i];
    }
    for(int i=0;i<rightArrSize; i++) {
        rightArr[i] = arr[mid+1+i];
    }
    int ptr1 = 0, ptr2 = 0, spot = start;
    while(ptr1 < leftArrSize && ptr2 < rightArrSize) {
        if(leftArr[ptr1] <= rightArr[ptr2]) {
            arr[spot] = leftArr[ptr1];
            spot++;
            ptr1++;
        } else {
            invCount += leftArrSize - ptr1;
            arr[spot] = rightArr[ptr2];
            spot++;
            ptr2++;
        }
    }
    if(ptr1 < leftArrSize) {
        for(int ptr = ptr1; ptr < leftArrSize; ptr++) {
            arr[spot] = leftArr[ptr];
            spot++;
        }
    }
    if(ptr2 < rightArrSize) {
        for(int ptr = ptr2; ptr < rightArrSize; ptr++) {
            arr[spot] = rightArr[ptr];
            spot++;
        }
    }
    return invCount;
}


int mergeSort(int arr[], int start, int end) {
    int sz = end - start +  1;
    if(sz == 1) {
        return 0;
    }
    int mid = start + (end - start)/2;
    int leftInvCount = mergeSort(arr, start, mid);
    int rightInvCount =  mergeSort(arr, mid+1,end);
    int conquerInverCount = procedure(arr, start, mid, end);
    return  leftInvCount + rightInvCount + conquerInverCount;
}


int main() {
    int arr[] = {2, 3, 12, 2, 4, 1, 17, 28};
    // Inversion: -> 2 -  1
    // 3 - 2
    // 12 - 3
    // 2 - 1
    // 4 - 1
    // Total = 8 inversions
    /*int ans = 0;
    //0^x = x
    //x^x = 0
    for(int i=0;i<5;i++){
        ans^=arr[i];
    }
     // Stable but not inplace
     // But inplace version of merge sort is possible
    cout<<ans<<endl;
    return 0;*/
    // Divide and conquer to find max element
    /*int ans = maxElement(arr, 0, 4);
    cout<<ans<<endl;*/
    int invCount = mergeSort(arr, 0, 7);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"The inversion count is: "<< invCount<<endl;
}

