#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    if (k > n/2) {
        cout << "-1\n";
    } else {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = 2*i+1;
        }
        for (int i = 0; i+1 < n && k > 0; i += 2) {
            swap(a[i], a[i+1]);
            k--;
        }
        for (int x : a) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
