#include <iostream>
using namespace std;

class Student {
	public:
	 double marks;
	 Student(double m){
	 	marks = m;
	 }
};

void calAvg(Student s1, Student s2){
	double avg = (s1.marks + s2.marks) / 2;

	cout << avg;
}
int main(){

	Student s1(44.0), s2(52.4);

	calAvg(s1, s2);

}