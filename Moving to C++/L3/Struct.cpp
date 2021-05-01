#include <iostream>
#include <iomanip>

using namespace std;


struct Person {
	char name[50];
	int age;
	float salary;

};
void display(Person);
Person get(Person);
int main(){

	Person p;
	Person newP = get(p);	
	display(newP);
 
	return 0;
}

Person get(Person p){
	cin >> p.name;
	cin >> p.age;
	cin >> p.salary;

	return p;
}

void display(Person p){

	cout << "----------------------" << endl;
	cout << p.name << endl;
	cout << p.age << endl;
	cout << p.salary << endl;
}
