#include <iostream>
using namespace std;
int main() {
    int test[2][3][2] = {{{10, 20},{30, 40},{50, 60}},{{70, 80},{90, 100},{110, 120}}};
    /*
    int test[2][3][2] = {
                            {
                                {10, 20},
                                {30, 40},
                                {50, 60}
                            },
                            {
                                {70, 80},
                                {90, 100},
                                {110, 120}
                            }
                        };
    */
   cout << "Displaying the content of the array..." << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                cout<<"test["<<i<<"]["<<j<<"]["<<k<<"] = "<<test[i][j][k] << endl;
            }
        }
    }
    cout << endl << "End of the program..." << endl;
}