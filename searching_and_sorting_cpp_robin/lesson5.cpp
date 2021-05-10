#include <bits/stdc++.h>
using namespace std;

struct student {
    int score;
    string name;
};

void countSort(int arr[], int start, int end) {
    int mxElement = *max_element(arr+start, arr+end);
    // MxElement is kind of in comparable to n
    int occArr[mxElement + 1];
    memset(occArr, 0, sizeof(occArr));
    for(int i=start;i<=end;i++){
        occArr[arr[i]]++;
    }
    int idx = start;
    for(int i=0;i<=mxElement;i++) {
        for(int j=0;j<occArr[i];j++){
            arr[idx] = i;
            idx++;
        }
    }
}

vector<student>occArr[100];

void countSortOnObj(student arr[], int start, int end) {
    int mx = 0;
    for(int i=start; i<=end;i++){
        mx=max(mx,arr[i].score);
    }
    for(int i=start;i<=end;i++){
        occArr[arr[i].score].push_back(arr[i]);
    }
    int idx = start;
    for(int i=0;i<=mx;i++){
        for(int j=0;j<occArr[i].size();j++){
            arr[idx] = occArr[i][j];
            idx++;
        }
    }
}

vector<float>bucketArr[100];

void bucketSort(float arr[], int start, int end) {
    float mx = *max_element(arr+start, arr+end+1);
    float mn = *min_element(arr+start, arr+end+1);
    int totalElements = end - start + 1;
    mx+=1;
    int range = (mx - mn)/totalElements;
    for(int i=start;i<=end;i++){
        int idx = (arr[i]-mn)/range;
        bucketArr[idx].push_back(arr[i]);
    }

    for(int i=0;i<totalElements;i++){
        sort(bucketArr[i].begin(), bucketArr[i].end());
    }

    int idx = 0;
    for(int i=0;i<totalElements;i++){
        for(int j=0;j<bucketArr[i].size();j++){
            arr[idx] = bucketArr[i][j];
            idx++;
        }
    }
}

// Radix Sort

void sortRadix(int arr[], int start, int end){
    //{234, 123454, 6789, 12, 908, 45}
    int occArr[10];
    int mx = *max_element(arr+start, arr + end + 1);
    for(int i=1;i<=mx; i*=10){ // number of digits
        memset(occArr, 0, sizeof(occArr));
        for(int j=start;j<=end;j++){
            occArr[(arr[j]/i)%10]++;
        }
        for(int j=1;j<10;j++){
            occArr[j]+=occArr[j-1];
        }
        int newArr[end-start+1];
        for(int j=end;j>=start;j--){
            newArr[occArr[(arr[j]/i)%10] - 1] = arr[j];
            occArr[(arr[j]/i)%10]--;
        }
        for(int j=start;j<=end;j++){
            arr[j] = newArr[j];
        }
    }
}

int main() {
   int arr[] = {1, 3, 4, 6, 4, 6, 0};
   countSort(arr, 0, 6);
   for(int i=0;i<7;i++) {
       cout<<arr[i]<<" ";
   }
   cout<<endl;
   student arrStudent[] = {{2, "Rohini"}, {5, "Dhrumil"}, {1, "Aritra"}};

   countSortOnObj(arrStudent, 0, 2);
   for(int i=0; i<3;i++){
       cout<<arrStudent[i].score << " " <<arrStudent[i].name<<endl;
   }
   // Bucket Sort
   float bucketArr[] = {2.3, 4.8, 3.6, 4.9, 5.7, 9.8, 7.2, 7.9};
   bucketSort(bucketArr, 0, 7);
   for(int i=0;i<8;i++){
       cout<<bucketArr[i]<<" ";
   }
   cout<<endl;
   int radixArr[] = {234, 123454, 6789, 12, 908, 45};
   sortRadix(radixArr, 0, 5);
   for(int i=0;i<6;i++){
       cout<<radixArr[i]<<" ";
   }
   cout<<endl;
}

