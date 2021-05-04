// C++ code to demonstrate tuple, get() and make_pair()
#include<iostream>
#include<tuple> // for tuple
using namespace std;
int main() {
    // Declaring tuple
    tuple <char, int, float> mytuple;
  
    // Assigning values to tuple using make_tuple()
    mytuple = make_tuple('a', 10, 15.5);
  
    // Printing initial tuple values using get()
    cout << "The initial values of tuple are : ";
    cout << get<0>(mytuple) << " " << get<1>(mytuple);
    cout << " " << get<2>(mytuple) << endl;
  
    // Use of get() to change values of tuple
    get<0>(mytuple) = 'b';
    get<2>(mytuple) =  20.5;
  
     // Printing modified tuple values
    cout << "The modified values of tuple are : ";
    cout << get<0>(mytuple) << " " << get<1>(mytuple);
    cout << " " << get<2>(mytuple) << endl;
  
    return 0;
}