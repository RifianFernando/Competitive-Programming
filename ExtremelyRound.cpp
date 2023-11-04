#include<bits/stdc++.h>

using namespace std;

int main(){
    int a; cin >> a;

    for (int i = 0; i < a; i++) {
        int input; cin >> input;
        if (input <= 10) {
            cout << input << endl;
        } else {
            // 500
            int count = 9;

            for (int j = 10; j < input; j*=10) {
                for (int k = j; k < j*10; k+=j) {
                    if (k <= input) {
                        count++;
                    } else {
                        break;
                    }
                    // cout <<k<< endl;
                }
                if ((j*10) == input) {
                    count++;
                }
            }
            cout << count << endl;

            // if (input % 10 == 0) {
                // cout << 9 + (input / 10) << endl;
            // } 
            // else {
            //     cout << 9 + (input / 10)
            // }
        }
    }
    
    return 0;
}
