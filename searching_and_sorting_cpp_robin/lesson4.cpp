#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p1;

void func(vector<int>&a){
    a[0] = 10;
}

void fact(int num, int& ans) {
    if(num == 1) {
        ans *= 1;
        return;
    }
    ans*=num;
    fact(num-1, ans);
}

int middleElement(int arr[], int n) {
    int mn = 10000000, mx = -10000000;
    for(int i=0;i<n;i++){
        mn = min(arr[i], mn);
        mx = max(arr[i], mx);
    }
    for(int i=0;i<n;i++) {
        if(arr[i] != mn and arr[i] != mx){
            return arr[i];
        }
    }
}

void sortIt(int arr[], int start, int end, int pivot) {
    int leftPlaced = 0, rightPlaced = 0;
    for(int i=start;i<=end;i++) {
        if(arr[i] < pivot) {
            swap(arr[i], arr[leftPlaced + start]);
            leftPlaced++;
        } else if (arr[i] > pivot and i < (end - rightPlaced)) {
            swap(arr[i], arr[end - rightPlaced]);
            i--;
            rightPlaced++;
        }
    }
}
// Iterative QUICK SORT

void sortQuick(int arr[], int start, int end) {
    stack<pair<int, int>>stk;
    stk.push({start, end});
    while(!stk.empty()){
        pair<int, int> p1 = stk.top();
        stk.pop();
        int s = p1.first;
        int e = p1.second;
        if(s >= e) {
            continue;
        }
        int pivot = arr[e];
        int elementPlaced = 0;
        for(int i=s; i < e;i++) {
            if(arr[i] < pivot) {
                swap(arr[i], arr[s + elementPlaced]);
                elementPlaced++;
            }
        }
        swap(arr[e], arr[s + elementPlaced]);
        stk.push({s, s + elementPlaced - 1});
        stk.push({s + elementPlaced + 1, e});
    }
}

int main() {
    /*p1 a;
    a.first = 5;
    a.second = 7;
    int ans = 1;
    fact(5, ans);
    cout<<ans<<endl;
    int arr[] = {1, 2, 2, 3, 3, 1, 2};
    int x = middleElement(arr, 7);
    sortIt(arr, 0, 6, x);
    cout<<x<<endl;
    for(int i=0;i < 7;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;*/
    int arr[] = {1, 6, 1, 2, 9, 11, 4};
    sortQuick(arr, 0, 6);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

