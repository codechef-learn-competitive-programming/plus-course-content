#include <iostream>// Input and Output operations
#include<cstring>
// Pre processing directives
using namespace std;

struct ReportCard {
    int marksInMath, marksInPhysics, marksInBio;
    float percentage;

    // Associate functions with the user defined data type
};

// Red, green Blue
enum color {red, green, blue};

#define M 5
#define  fr(n)  for(int i=0; i<n;i++)

typedef int it;

it main() { // main function
    /*int rollNumber;
    char a;
    a = 'a';
    float percentage;
    percentage = 54.4;
    long long l;

    cout << "Size of Int is:" << sizeof(rollNumber) << endl;
    cout << "Size of Char is:" << sizeof(a) << endl;
    cout << "Size of Float is: " << sizeof(percentage) << endl;
    cout << "Size of Long long is:" << sizeof(l) <<endl;
    // data types
    // int, float, double, string,

    *//* This code outputs the
     sum of two numbers
     *//*
    cout << "Please Enter Number 1:"<< endl;
    int number1;
    cin >> number1;
    cout<< "Please Enter Number 2:" <<endl;
    int number2;
    cin >> number2;
    cout <<"The result is:" << number1 + number2 << endl;*/



    // Marks of a user of Physics, Cs, Maths, Bio and gives Percentage
/*    int marksInPhysics, marksInCs, marksInMaths, marksInBio;
    cout << "Enter your marks in Physics" <<endl;
    cin >> marksInPhysics;
    cout << "Enter your marks in Cs" << endl;
    cin >> marksInCs;
    cout << "Enter your marks in Maths" << endl;
    cin >> marksInMaths;
    cout << "Enter your marks in Bio" <<endl;
    cin >>marksInBio;

    float percentage;

    percentage = float(marksInPhysics + marksInBio + marksInMaths + marksInCs)/ float(4);
    cout << "The Percentage of user is:" << percentage<<endl;*/

    // Each Data type has a size limit
    //4 bytes -> 32 bits
    //1 bit [It can be up or It can  be down] -> 2 [1 -> 1, 0-> 2 ]
    // 2 bits [10, 01, 11, 00]
    //32 bits [2^32] -> 2^31 -> 10^9
    // 2^30 => 10^9
    //long long has 64 bits -> 8 2^63 -> 10^18

    // Understanding size in Cpp
/*    int a, b;
    a = 2e9; // 2000000009
    b = 2e9;

    int c  = a + b;
    cout << c<< endl;

    // 2 bits
    //-1 0 1 2 => (2+2) ->3*/

    // User defined Datatype
    // ReportCard -> marks in each Subject and Percentage

    ReportCard r;
    r.marksInBio = 63;
    r.marksInPhysics = 95;
    r.marksInMath = 100;
    r.percentage = float(r.marksInBio + r.marksInPhysics + r.marksInMath) / 3;

    color c;
    c = red;
    c = blue;
    c = green;
    // this will give error
    //c = yellow;
    // Class is one more way to create user defined data type

    //Summarize
    /*
     * -> Introduction on Programming
     * Demystify hello world program [Pre processing directives]
     * Syntax datatypes and variables
     * Size in Variables, data types
     * Program
     * User defined Data types [enum, struct, classes]
     * typedef, define
     */
    it a = M;
    cout<< a <<endl;
    fr(3) {
       cout <<"Hello "<<endl;
    }
    return 0;
}


//class
    // func( parameter)

    // Class -> Country
    // India.f1()
    // India.f1


//std -> namespace

// fb

// +, -, *, /, %,


//Compiler - Machine level code
// Platform dependent
// Object Oriented Programming // Classes Bottom up
// Statically typed

