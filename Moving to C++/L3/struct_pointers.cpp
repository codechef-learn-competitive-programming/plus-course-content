#include <iostream>

using namespace std;

// struct Distance {
// 	int feet;
// 	float inch;
// };

enum week {Sunday = 2, Monday = 5, Tuesday = 6, Wednesday = 13, Thursday = 23, Friday = 32, Saturday = 51};
enum cards {
	club = 0,
	diamonds = 10,
	hearts = 20,
	spades = 3
} card;
int main(){

	// Distance *ip, d;

	// ip = &d;

	// cin >> (*ip).feet;
	// cin >> (*ip).inch;

	// cout << (*ip).feet << " " << (*ip).inch << endl; 
	// cout << d.feet << " " << d.inch << endl; 

	// week today;
	// today = Wednesday;
	// cout << today ;
	int d = club | diamonds;
	cout << d;
	cout << sizeof(card);
	return 0;
}