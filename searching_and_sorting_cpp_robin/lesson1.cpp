#include <bits/stdc++.h>
using namespace std;

/*struct Student {
    int marks;
    int att;
};

bool comp(Student a, Student b) {
    int score_of_a = a.att + a.marks;
    int score_of_b = b.att + b.marks;
    if(score_of_a  <= score_of_b ) {
        return false;
    } else {
        return true;
    }
}*/

int main() {
    /*int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr + 0, arr + n); // O(nlogn)*/
    // Simple sorting print
    /*for(int i=0;i<n;i++) {
        cout<<arr[i]<< " ";
    }
    cout<<endl;*/
    /*bool isEqualFound = false;
    for(int i=0;i<n-1;i++){
        if(arr[i] == arr[i+1]){
            isEqualFound = true;
        }
    }
    if(isEqualFound == true) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }*/

    /*vector<Student>s(5);
    for(int i=0;i<5;i++){
        s[i].marks = (i+1)*10;
        s[i].att = (i+1)*10;
    }

    cout<<"Before Sorting..... " <<endl;

    for (int i=0;i<5; i++) {
        cout<<s[i].marks << " "<<s[i].att <<endl;
    }

    sort(s.begin(), s.end(), comp);

    cout<<"After Sorting....... "<<endl;
    for (int i=0;i<5; i++) {
        cout<<s[i].marks << " "<<s[i].att <<endl;
    }*/
    int n = 5;
    int arr[] = {1, 4, 2, 3, 5};

    // Selection sort // inplace sort
   /* for(int i=0;i<n;i++){
       // i denotes basically the point of interest
       int priority_element = i;
       for(int j = i+1;j<n; j++) {
           if(arr[j] < arr[priority_element]) {
               priority_element = j;
           }
       }
       swap(arr[i], arr[priority_element]);
    }*/

   // Bubble Sort Algorithm // inplace
  /* for(int i=0;i< n-1;i++) {
       for(int j=0;j < n-i-1;j++) {
           if(arr[j] > arr[j+1]) {
               swap(arr[j], arr[j+1]);
           }
       }
   }*/

  // Insertion Sort Algorithm
//  2 4 7 3
//  element  = 3
//2 4 7 7
// 2 4 4 7
// 2 3 4 7
// Insertion Sort // inplace
  /*for(int i=1;i<n;i++) {
      int j = i-1; // 7
      int element = arr[i];
      while(j>=0 && arr[j] >= element) {
          arr[j + 1] = arr[j];// move it into one step right
          j--; // one step in to left to check
      }
      arr[j+1] = element;
  }
*/
   /* for(int i=0;i<n;i++) {
        cout<<arr[i] <<" ";
    }
    cout<<endl;*/

    return 0;
}

