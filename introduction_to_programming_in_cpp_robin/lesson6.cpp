#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void swap(int &a, int &b);

int main() { // main function// This a
    /*vector<int>v; // creation of a bag

    vector<int>v1(5);
    vector<int>::iterator it;
    // iterate over vectors
    for(int i=0; i < v1.size(); i++) {
        v1[i] = i;
    }
    // Pointer and reference
    cout<<v1[3]<<endl;
    v1.at(0) = 100;
    cout<<v1[0]<<endl;
    cout<<v1.at(3)<<endl;
    v1[0] = 26;
    it = v1.begin();
    cout<<(*it)<<endl;

    for(it = v1.begin(); it != v1.end(); it++) {
        cout<<(*it)<<endl;
    }
    vector<int>::reverse_iterator rit;
    for(rit = v1.rbegin(); rit != v1.rend(); rit++) {
        cout <<*rit<<endl;
    }
    // What is the data type of a
    int a = 5;
    // auto
    // This is iterator with auto syntax
    cout<<"Yes"<<endl;
    for(auto it2 = v1.end() - 1; it2 != v1.begin() - 1; it2--) {
        cout<<*it2<<endl;
    }
    v1.push_back(100);
    v1.push_back(120);
    cout<<v1.size()<<endl;
    cout<<v1.capacity()<<endl;
    v1.pop_back();
    cout<<v1.front()<<endl;
    cout<<v1.back()<<endl;
    cout<<v1.capacity()<<endl;
    *//*v1.clear();
    cout<<v1.capacity()<<endl;
    v1.swap(v);
    cout<<v1.capacity()<<endl;*//*
    it = v1.begin() + 2;
    v1.erase(it);  //-> O(n)
    cout<<v1.size()<<endl;
    cout<<v1[2]<<endl;

   *//* -> v1.empty() // 1
    -> v1.size() == 0 // 2*/
    int element1 = 23;
    int element2 = 43;
    int& e = element1;
    swap(element1, element2);

    cout<<element1<< " "<<element2<<endl;
    e = 26;
    cout<<element1<<" "<<element2<<endl;

    return 0;
}

void swap(int& a, int& b) {
    int temp = a; // a =100  b  = 20 // temp 100
    a = b; //a 20
    b = temp; // b 100
}
