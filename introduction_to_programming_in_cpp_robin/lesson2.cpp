#include <iostream>// Input and Output operations


using namespace std;

int main() { // main function
    cout<<"Yipee!! This is lesson 2!"<<endl;
   /* int a = 10;
    cout<<(a^0)<<endl;*/

    // Somebody Asked Hi Write a program which takes number from a user and
    // evaluate is this number power of 2 or not
/*    int num;
    cout<<"Hi user Please give me a number!"<<endl;
    cin>>num;
    //2^num with the left shift operator
    //cout<<(1<<num)<<endl;
    // How many bits do we have up if number is power of 2?
    int expression =  (num & (num-1));
    if(expression == 0) {
        cout<<"Hi You have entered a power of 2"<<endl;
        cout<<"You are awesome buddy, You just wrote a program as well"<< endl;
    } else {
        cout<<"Hi This number is not a power of 2"<<endl;
        cout<<"You are awesome as always"<<endl;
    }*/
    // If this expression gives me 0 my answer is power of 2 otherwise it is not
    // The question is We have a marks of a student we need to tell the
    // grade
    // (90, 100] -> Grade A
    // (70 ,90] -> Grade B
    // (40, 70] -> Grade C
    // less than  40 -> Failed

    // else if

   /* int marks;
    cout<<"Hi User Please Enter your marks!"<<endl;
    cin>>marks;
    if(marks >= 90) {
        cout<<"Hi! You achieved Grade A"<<endl;
    } else if (marks > 70 && marks <= 90) {
        cout <<"Hi! You have achieved Grade B"<<endl;
    } else if (marks > 40 && marks <= 70) {
        cout<<"Hi, You have achieved Grade C"<<endl;
    } else {
      cout<<"Hi, Sorry to Say But You failed the exam"<<endl;
      cout<<"Please do hard work next time"<<endl;
    }
*/
    // Monday -> I want to do somtthing
    // Tuesday -> I want to do something else
    // Wednesday -> I want to do something else

   /* cout << " Please enter day of a week"<<endl;
    int day;
    cin>> day;*/
    // This approach is slow
   /* if(day == "monday") {

    } else if (day == "tuesday") {

    }

    .
    .
    .
     else if (day == "fri") {

     }*/

   /* switch (day) {
        case 0:
            cout<<"Here I will do activities of Monday!"<<endl;
            break;
        case 1:
            cout<<"Here I will do activities of Monday!"<<endl;
            break;
        case 2:
            cout<<"Here I will do activities of Tuesday"<<endl;
            break;
        default:
            cout<<"Here I will take care of other days of the week"<<endl;
    }*/

    //  Ternary Operators
    //logical expresion
    (4 < 5) ? cout<< "Hi I am true one" : cout<< "Hi I am false one";
    return 0;
}

// Operators -> Different Types of operators
// How to convert decimal to binary
// We have solved some questions to appreciate bit wise operators
// Decision control system
// if else else if switch and ternary operators
