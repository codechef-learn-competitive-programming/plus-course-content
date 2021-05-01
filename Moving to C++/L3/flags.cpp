#include <iostream>
using namespace std;

// enum designFlags {
// 	italics = 1, //0000000001
// 	bold = 2,    //0000000010
// 	underline = 4//0000000100
// };
class Room {
public:
	double length;
	double breadth;
	double height;
	Room() {
		cout << "Creating a room" << endl;
	}
	//copy constructor with Room object as paramter
	Room(Room &obj){
		length = obj.length;
		breadth = obj.breadth;
		height = obj.height;
	}

	Room(double len, double bre, double hei){
		length = len;
		breadth = bre;
		height = hei;
	}
	double Area(){
		return length * breadth;
	}

	double Volume(){
		return length * breadth * height;
	}
	
};
int main(){

	//desigFlags design;
	// int design = bold | underline;
	// cout << design;

	// cout << design | italics;
	Room r1(10.2, 12, 13);


	// r1.length = 10.2;
	// r1.breadth = 12;
	// r1.height = 13;
	
	cout << r1.Area() << endl;
	//cout << r1.Volume() << endl;

	//copy the contents of room1 to another object room2
	Room r2 = r1;
	cout << r2.Area() << endl;
	r1.length = 2;
	cout << r1.Area() << endl;
	cout << r2.Area() << endl;
	return 0;


}