/*
#include <iostream>


using namespace std;

int main() { // main function
    cout<<"Yipee!! This is lesson 4!"<<endl;
    int number;
    cout<<"Please enter the number for which you are interested in:";
    cin>>number;
    for(int i=1;i<=((1<<number)-1);i++) {
        int infoNumber = i;
        cout<<"Subset Number: "<<i<<endl;
        for(int j=0;j<number;j++){
            if(((1<<j) & infoNumber) > 0) {
                cout<<j+1<< " ";
            }
        }
        // (4*number + 3)*(2^(number - 1) + 1) + 4
        cout<<endl;
    }

    // Time complexity of this question

    // CODECHEF QUESTION:
#include <iostream>
    using namespace std;

    int main() {
        // -> two types of barrier
        // -> I can cross the barrier sequentially
        // ->  I have L life form of alchemic
        // -> L should always greater than 0
        // T test cases
        // Type1 and xi >= h-y1 otherwise I need to use al* life [life > 1]
        // Type 2 and xi <= y2 otherwise I need to use a1 *life

        int numberofTestCases;
        cin>>numberofTestCases;
        for(int i=0;i<numberofTestCases;i++) { //->2 + 1 +2*numberofTestCases*(2 + 20*N) -> 
            // 3 + 4*numberofTestCases  + 40*numberofTestCases *N -> O(numberofTestCases * N)
            int ans = 0;
            int N, H, Y1, Y2, L;
            cin>>N>>H>>Y1>>Y2>>L;
            int isAheadPowerPossible = true;
            for(int barrier=0;barrier<N;barrier++){
                int type, xi;
                cin>>type>>xi;
                if(type == 1) {
                    if(xi >= H-Y1 and isAheadPowerPossible){
                        ans++;
                    } else {
                        if(L > 1) {
                            L--;
                            ans++;
                        } else {
                            isAheadPowerPossible = false;
                        }
                    }
                } else {
                    if (xi <= Y2 and isAheadPowerPossible) {
                        ans++;
                    } else {
                        if(L > 1) {
                            L--;
                            ans++;
                        } else {
                            isAheadPowerPossible = false;
                        }
                    }
                }
            }
            cout<<ans<<endl;
        }

        return 0;
    }

    return 0;
}
*/

