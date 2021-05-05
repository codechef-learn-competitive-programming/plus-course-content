#include <iostream>

using namespace std;

class Base {

public:
	void print(){
		cout << "Base" << endl;
	}
};

class Derived : public Base {
public:
	void print(){
		//Base::print();
		cout << "Derived" << endl;
	}
};
int main(){
	
	Derived d;	
	Base *ip = &d;
	ip->print();
	//d.print();
	//d.Base::print();
	return 0;
}