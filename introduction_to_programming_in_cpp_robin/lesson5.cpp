#include <iostream>
#include <vector>


using namespace std;

// This is global but stack memory

int main() { // main function// This a
    // Scope concept in cpp
    /*for(int i=0; i <a;i++) {
         //  this a is differrn
         int a;
         a = 4;
        cout<<a<<endl;

        cout<<"Hi I am inside: "<<a<<endl;
    }
    cout<<"Hi I am outside: " <<a<<endl;*/
    // Pointer and references in cpp
   /* int *a = nullptr;
    int b = 10;
    int &d = b;
    int *c = &b;
    a = c;
    (*a)++;
    cout<<a<<" "<<b<<" "<<c<< " " << d<<endl;
    d = 15;
    cout<<(*a)<<" "<<b <<" "<< (*c) <<" "<< d<<endl;*/

   //Heap section
// If we declare anything in heap memory we can use it outside the scope as well
   /*double *a = nullptr;
   int number;
   cin>>number;
   if((number%2) == 0){
       a = new double;
       (*a) = 5;
   }
    cout<<(*a)<<endl;*/
   //int arr[5]; // memory is allocated in stack section
   /*for(int i=0;i<5;i++){
       //arr[i] = i+1;
   }*/
   // Not a desirable thing
   /*arr[6] =3;
   cout<<arr[6]<<endl;// Wrong*/
    // arrays
/*   int arr[] = {1,2,3,4};
    //arr //pointer to an array first value
    cout<<*(arr + 8)<<" "<<*(arr + 3)<<endl;

    int *a;
    a = arr;
    cout<<*(a+8)<<" "<<*(a + 2)<<endl;*/

    // 2d arrays
  /*  int a[2][3] = {{1, 2, 3}, {3, 4, 5}};
    int k = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cout<<a[i][j]<<" "<<*(*(a+i)+j)<<endl;
            k++;
        }
    }*/

    //Homework
    //Read about how tp allocate arrays in heap memory

    // Vector in cpp
    vector<int>v(5);
    for(int i=0;i<5;i++){
        v[i] = i+1;
    }
    for(int i=0;i<5;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<5;i++){
        v.at(i) = i-1;
    }
    for(int i=0;i<5;i++){
        cout<<v.at(i)<<" ";
    }
    cout<<endl;

    return 0;
}
