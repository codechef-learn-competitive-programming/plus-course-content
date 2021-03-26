#include<bits/stdc++.h>
using namespace std;

template<typename T>
class StackArray{
private:
    int size, capacity;
    T *a;
public:
    StackArray(int x){
        a = new T[x];
        size = 0;
        capacity = x;
    }

    void push(T val){
        if(size == capacity){
            cout<<"Stack Overflow\n";
            return;
        }
        a[size++] = val;
    }

    T pop(){
        if(size == 0){
            cout<<"Stack Underflow\n";
            return T();
        }

        return a[--size]; 
    }

    T top(){
        if(size == 0){
            cout<<"Stack Underflow\n";
            return T();
        }

        return a[size-1];
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size==0;
    }
};


template<typename T>
struct node {
    T data;
    node *next;
};

template<typename T>
class StackLL{
private:
    node<T>* head;
    int size;
public:
    StackLL(){
        head = NULL;
        size = 0;
    }

    void push(T val){
        node<T> *temp = new node<T>;
        temp -> data = val;
        temp -> next = NULL;

        if(head == NULL){
            head = temp;
        }else{
            temp -> next = head;
            head = temp;
        }

        size++;
    }

    T top(){
        if(size == 0){
            cout<<"Stack UnderFlow\n";
            return T();
        }

        return head -> data;
    }

    T pop(){
        if(size == 0){
            cout<<"Stack UnderFlow\n";
            return T();
        }
        node<T> *temp = head;
        T ret = head -> data;

        head = head -> next;
        free(temp);
        size --;

        return ret;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 

    StackArray<char> st(10);

    st.push('c');
    st.push('z');
    st.push('y');

    cout<< st.top() <<endl;
     cout<< st.pop() <<endl;
     cout<< st.top() <<endl;

     cout<< st.getSize() <<endl;

     cout << st.pop() <<endl;
     cout<< st.pop() <<endl;

    // cout<<st.pop() <<endl;


    return 0;
}