#include<bits/stdc++.h>

using namespace std;

int main() {
    while (true) {
        vector<int> v;
        while(true) {
            int x; cin >> x;
            if (x == 0) break;
            v.push_back(x);
        }
        if (v.empty()) return 0;
        sort(v.begin(), v.end());
        for (int i = 1; v.size() >= i; i++) {
            v[i] -= v[0];
        }
        int result = v[1];
        for (int i = 1; v.size() > i; i++) {
            result = __gcd(result, v[i]);
        }
        cout << result << endl;
    }
}
