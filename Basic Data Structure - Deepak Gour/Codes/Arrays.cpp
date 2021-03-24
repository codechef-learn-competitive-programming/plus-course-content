#include<bits/stdc++.h>
using namespace std;
template <typename T>
class vec {
    T *a;
    int size;
    int capacity;
public:
    vec(int x){
        a = new T[x];
        capacity = x;
        size = 0;
    }

    void resize(){
        T *temp = new T[capacity*2];
        capacity *= 2;

        for(int i=0;i<size;i++){
            temp[i] = a[i];
        }
        delete [] a;
        a = temp;
    }

    void push_back(T val){
        if(size + 1 > capacity) resize();
        a[size++] = val;
    }

    T get(int index){
        if(index >= 0 && size > index){
            return a[index];
        }else{
            cout<<"Array out of bound index\n";
            return -1;
        }
    }

    int get_capacity(){
        return capacity;
    }

    int get_size(){
        return size;
    }

    void print(){
        cout<<"Size of array is: "<<size<<", capacity is: "<<capacity<<endl;
        for(int i=0;i<size;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

    void pop(){
        if(size == 0){
            cout<<"Array out of bound error\n";
            return;
        }
        size--;
    }
    void sort(){
        sort(a, a+size);
    }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 


    vec<char> v(1);

    v.push_back('a');
    v.print();
    v.push_back('c');
    v.print();
    v.push_back('d');
    v.print();


    return 0;
}