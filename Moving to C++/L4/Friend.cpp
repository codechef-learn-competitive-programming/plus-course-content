#include <iostream>
using namespace std;

class Distance {
private:
	int meter;

	friend int add(Distance);
public:
	Distance(){
		meter = 0;
	}
};

int add(Distance d){
	d.meter += 5;
	return d.meter;
}

int main(){

	Distance d;
	cout << "Distance: " << add(d);
	return 0;
}