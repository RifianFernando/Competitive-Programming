#include <bits/stdc++.h>

using namespace std;

int main() {
    // constraint
    // 1 < A < M

    // GCD adalah
    // n, m, k
    int n; cin >> n;
    int arr[n], temp = 0;
    long long count = n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        // new implement
        if (i > 0) {
            if (arr[i-1] < arr[i]) {
                temp++;
            } else {
                temp = 0;
            }
            count += temp;
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = i+1; j < n; j++){
    //         if (arr[i] < arr[j]) {
    //             // cout << arr[i] << " " << arr[j] << endl;
    //             count++;
    //         } else {
    //             break;
    //         }
    //         if (arr[j] < arr[j+1]) {
    //             continue;
    //         } else {
    //             break;
    //         }
    //     }
    // }
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }

    cout << count << endl;


    return 0;
}
