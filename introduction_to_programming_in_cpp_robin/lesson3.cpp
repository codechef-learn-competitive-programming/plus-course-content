#include <iostream>// Input and Output operations


using namespace std;

int main() { // main function
    cout<<"Yipee!! This is lesson 3!"<<endl;
    // We want to implement password checker
   /* // I have 5 attempts
    int attempt;
    cout<<"Please Enter number of attempts";
    cin>>attempt;
    int correctPassword = 60;
    int password;*/
  /*  cout<<"Please enter the password";
    cin>>password;
    if (password == correctPassword) {
        cout<<"Hurray The device has been unlocked"<<endl;
        return 0;
    } else if (attempt == 0) {
        cout<<"Hi No more attempts left";
        return 0;
    } else {
        attempt--;
    }
    cout<<"Please enter the password";
    cin>>password;
    if (password == correctPassword) {
        cout<<"Hurray The device has been unlocked"<<endl;
        return 0;
    } else if (attempt == 0) {
        cout<<"Hi No more attempts left";
        return 0;
    } else {
        attempt--;
    }
    cout<<"Please enter the password";
    cin>>password;
    if (password == correctPassword) {
        cout<<"Hurray The device has been unlocked"<<endl;
        return 0;
    } else if (attempt == 0) {
        cout<<"Hi No more attempts left";
        return 0;
    } else {
        attempt--;
    }
    cout<<"Please enter the password";
    cin>>password;
    if (password == correctPassword) {
        cout<<"Hurray The device has been unlocked"<<endl;
        return 0;
    } else if (attempt == 0) {
        cout<<"Hi No more attempts left";
        return 0;
    } else {
        attempt--;
    }
    cout<<"Please enter the password";
    cin>>password;
    if (password == correctPassword) {
        cout<<"Hurray The device has been unlocked"<<endl;
        return 0;
    } else if (attempt == 0) {
        cout<<"Hi No more attempts left";
        return 0;
    } else {
        attempt--;
    }*/

    // I am writing same piece of code everytime
    // if the number of attempts if it is more than 1000
    // So much repetitions

    // loop=> When we want apply same set of instruction for some number of times
    // while
  /*  while(attempt != 0) {
        cout<<"Please enter the password";
        cin>>password;
        if (password == correctPassword) {
            cout<<"Hurray The device has been unlocked"<<endl;
            return 0;
        } else {
            attempt--;
        }
    }*/
    // 3

    // do while loop
    //
    /*int time;
    cin>>time;
    do {
        // There will be list and I need to show the elements
        // Sleep for 5 minutes
    } while (time >= 7 and time<=12);*/

    // This is the beauty of while loop
   /* int a = 1;
    do {
        cout<<"Hello";
        a--;
    } while(a!=0);*/

    // Important => Number of iterations for while as well as do while
    // It will be similar

    // for loop

    /*for(int i=0; i<5; i++) {
        cout<<"Yes"<<endl;
    }*/

    /*int i = 10;*/
   /* int j = i++; //= [Right to left]

    cout<<j<<endl;*/
  /*  cout<<i++<<endl; // 10 ++i
    cout<<i<<endl; //
*/
    // i++ => i+=1 => i = i+1
  /*  int i=0;
    while(i<5){
        cout<<"Yes"<<endl;

        i++;
    }
*/
    // What for loop is doing it is basically ease out our work
    //Nested loops
    // m as well as n
    //print hello m*n times
   /* int n,m;
    cout<<"Please input the value of m and n"<<endl;
    cin>>m>>n;
    // Nested loop
    //m = 2, n = 3
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) {
            cout<<"Hi"<<endl;
        }
        cout<<"Inside for loop just got ended"<<endl;
    }*/

 /*   for(int i=0;i<5;i++){
        int j=0;
        while(j<3){
            cout<<"Hi I am inner loop"<<endl;
            break;
            j++;
        }
        cout<<"I am outer loop"<<endl;
    }*/

 // Lets say user gives input 7
 // Hello Hello Hello Hello Hello

   /* int n;
    cout<<"Please enter number n";
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i%5==0){
            continue;
        }
        cout<<"Hello  I am: "<<i<<endl;
    }*/

   /* for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            cout<<"Hi I am j: "<<j<<endl;
            if(j==3){
                break;
            }
        }
        cout<<"Hi I am i: "<<i<<endl;
    }*/

   /*int n;
   cin>>n;
   while(n=7){
       cout<<"Yes"<<endl;
   }*/

   // RED FLAG -> Please Do n't Write program which will end up in an
   // infinite loop

   // Given a number we want to check whether the number is prime or not
  // % is giving us remainder

  int number;
  cin>>number;
  bool isPrime = true;
  for(int i=2; i * i <= number;i++){
      if (number%i == 0) {
          isPrime = false;
          break;
      }
  }

  if(isPrime) {
      cout<<"Hi The number is Prime"<<endl;
  } else {
      cout<<"Hi The number is not prime"<<endl;
  }


/*  number =  2 * (number/2); - 1
  number = 3 * (number/3); -
            4 * (num

            (number/4) * 4

        = (number/2) * 2/ - last
                // Useless computations

                36
    36 ->  2 * 18
           3 * 12
           4 * 9
           6 * 6 ->
           9 * 4
           12 * 3
           18 * 2*/
  return 0;

  // Homework
  // You need to build a calculator using switch statement
  // -> program to convert decimal into binary
  // Program to convert binary into decimal
}

