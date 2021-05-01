#include <iostream>
#include <iomanip>

using namespace std;

//prototyping
void swap(int*, int*);
int main(){
	
	// int x = 27;
	// int *ip;
	// ip = &x;	
	// cout << "Value of x is: ";
	// cout << x << endl;
	// cout << "Value of ip is: ";
	// cout << ip << endl;
	// cout << "Value of *ip is: ";
	// cout << *ip << endl; 

	// int *ip;
	// int arr[] = {10, 34, 13, 76, 5, 46};

	// ip = arr;
	// for(int x = 0; x < 6; x++){
	// 	cout << *ip << endl;
	// 	ip++;

	// }

	// int *ip = NULL;
	// cout << "Value of ip is: " << ip;

	// int var, int *ip;
	// ip = var //wrong
	// *ip = &var; //wrong
	// ip = &var; //correct
	// *ip = var; //correct

	// int a = 1;
	// int b = 2;
	// cout << "Before Swap" << endl;
	// cout << "a = " << a << endl;
	// cout << "b = " << b << endl;

	// swap(&a, &b);

	// cout << "After Swap" << endl;
	// cout << "a = " << a << endl;
	// cout << "b = " << b << endl;   

	int *pInt;
	float *pfloat;

	pInt = new int;
	pfloat = new float;

	*pInt = 45;
	*pfloat = 45.45f;

	cout << *pInt << endl;
	cout << *pfloat << endl;

	delete pInt;
	delete pfloat;

	return 0;
}


void swap(int* n1, int* n2){

	int temp;
	temp = *n1; 
	*n1 = *n2;
	*n2 = temp;
}


//passing by value
void func1(int val) {
	//code
}

//passing by reference
void func2(int &val){
	//code
}

