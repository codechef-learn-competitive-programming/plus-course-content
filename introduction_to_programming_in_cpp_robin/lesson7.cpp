#include <bits/stdc++.h>
using namespace std;

struct abc {
    int a;
    float b;
};

typedef pair<int, float> K;



int main() { // main function// This a
    /*cout<<"Welcome to lesson 7"<<endl;
    char str[5] = {'H', 'E', 'L', 'L', 'O'};
    cout<<strlen(str)<<endl;
    char* s = "HELLO"; // I just declARED THE MEMORY
    if (strcmp(str, s) == 0) {
        cout<< "Hi They are same"<<endl;
    } else {
        cout<<" They are not same"<<endl;
    }

    cout<<s<< " "<<strlen(s)<< endl;
    char str1[10] = {'N', 'I', 'K' , 'H'};
    cout<<str1<<endl;
    strcat(s, str);
    cout<<s[-1]<<endl;
    cout<<str1<<endl;*/
// string
    /*string s;
    // Abstraction
    s = "Hello";
    s += "World";
    cout<<s.size()<<endl;
    string s1("True");
    cout<<s1<<endl;
    string s2 = "Nikhal";
    string s3 = "Tejas";
    // s3 = s3 + s2
    // s3 += s2;
    string s4 = "Nikhil is my student";
    swap(s4, s3);
    cout<<s3<< " "<<s4<<endl;
    s3.swap(s4);
    cout<<s3<<" "<<s4<<endl;*/

    /*abc arr[100];

    K g = make_pair(1, 2.3); // {1, 2.3}
    vector<K> v;
    cout<<g.first <<" "<<g.second<<endl;
    v.push_back(make_pair(1, 2));
    v.push_back({1, 4.5});

    for(auto element: v) {
        cout<<element.first<< " "<<element.second<<endl;
    }
    */

    // Sets
 /*   // unordered_set
    vector<int>v = {1, 2, 2 , 17, 17, 4, 17, 13, 12, 2, 4};
    cout<<v.size()<<endl;
    unordered_set<int>us;
    set<int>s;
    for(auto element: v) {
        s.insert(element); // O(logn)
        us.insert(element);// O(1)
    }

    cout<<"I am iterating over unordered_Set: "<< us.size()<<endl;
    for(auto element: us) { // hashing techniques
        cout<<element<< " ";
    } // O(n)
    cout<<endl;

    cout<<"I am iterating over set: "<< s.size()<<endl;
    for(auto element: s) { // Using self balancing BST
        cout<<element<<" ";
    } // IT CAN TAKE O(nlogn)
    cout<<endl;
    s.erase(2);
    us.erase(17);
    cout<<"I am iterating over unordered_Set: "<< us.size()<<endl;
    for(auto element: us) { // hashing techniques
        cout<<element<< " ";
    } // O(n)
    cout<<endl;

    cout<<"I am iterating over set: "<< s.size()<<endl;
    for(auto element: s) { // Using self balancing BST
        cout<<element<<" ";
    } // IT CAN TAKE O(nlogn)*/

    // Map in Cpp
/*
  map<int, string>mp;
    mp[11] = "Robin"; //  O(logn)
    mp[12] = "Nikhil";
    mp[27] = "Tejas";
    mp[16] = "Aritra";
    mp[21] = "kiran";

    for(auto element: mp) {
        cout<<element.first<< " "<<element.second<<endl;
    }

    cout<<"**************************"<<endl;

    unordered_map<int, string>mp1;
    mp1[11] = "Robin"; //  O(1)
    mp1[12] = "Nikhil";
    mp1[27] = "Tejas";
    mp1[16] = "Aritra";
    mp1[21] = "kiran";

    for(auto element: mp1) {
        cout<<element.first<< " "<<element.second<<endl;
    }

    if(mp.find(100) != mp.end()) {
        cout<<"Element Found!!";
    } else {
        cout<<"Element Not Found!!";
    }*/

    // 1 2 3 4
    // (1, 2), (2, 3), (3, 4) (1, 4), (1, 3)
    // 1*2 + 2*3
    // (1+ 2+ 3+4)*(1+2+3+4) = 1^2 + 2^2 ...... + 2*Ans
    // Ans  = ((Sum of Array)^2 - (sum of each element^2)) /2

    int n;
    long long ans, sumOfArray = 0, sumOfElementSq = 0;
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        sumOfArray += x;
        sumOfElementSq += (x*x);
    }

    ans  = ((sumOfArray*sumOfArray) - sumOfElementSq)/ 2;
    cout<<ans<<endl;

    return 0;
}

// 2 3 1 4
// 2*3 + 2*1 + 2*4 + 3*1 + 3*4 + 1*4
// 6 + 2 + 8 + 3 + 12 + 4 = 35
