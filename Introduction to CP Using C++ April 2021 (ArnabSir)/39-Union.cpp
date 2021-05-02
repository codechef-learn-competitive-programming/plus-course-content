/*
              776   264
1800 = 1024 + 512 + 256 + 8 = 0000 0000 0000 0000 0000 0111 0000 1000
                              --------- --------- --------- ---------
65 = 64 + 1 =                                               0100 0001
                                                            ---------
1800 - 8 + 65 = 1792 + 65 = 1857
*/
                                                
#include <iostream>
using namespace std;

union test {
	int data;
	char ch;
};

int main() {
	union test t;
	t.data = 1800;
	cout << "\n\nt.data = " << t.data << ", " << t.ch << endl;
	t.ch = 'A';
	cout << "\n\nt.data = " << t.data << ", " << t.ch << endl;
	
	cout << "\n\nEnd of the program..." << endl;
    return 0;
}
