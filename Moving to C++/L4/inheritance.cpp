#include <iostream>

using namespace std;

class Animal {

public: 
	
	void eat(){
		cout << "Eating..." << endl;
	}

	void sleep(){
		cout << "Sleeping..." << endl;
	}
	void setColor(string c){
		color = c;
	}
	string getColor(){
		return color;
	}

private:
	string color;
protected:
	string type;

};

class Dog: public Animal {

public:
	void bark(){
		cout << "Barking..." << endl;
	}

	void setType(string t){
		type = t;
	}
	void display(string c){
		cout << type << endl;
		cout << c << endl;
	}
};
int main(){
	
	Dog d;
	d.eat();
	d.sleep();
	d.bark();	
	d.setColor("brown");
	//d.setType("Mumma");
	//d.type = "mumma";
	d.display(d.getColor());
	return 0;
}