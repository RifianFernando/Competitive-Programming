#include<bits/stdc++.h>
using namespace std;

vector<int> prime_factors(int u) {
    vector<int> factors;
    for (int i = 2; i <= u; ++i) {
        if (u % i == 0) {
            factors.push_back(i);
            while (u % i == 0) {
                u /= i;
            }
        }
    }
    return factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> res(n);
        map<int, int> factor_to_index;

        for (int i = 0; i < n; ++i) {
            int u;
            cin >> u;

            vector<int> factors = prime_factors(u);

            for (int factor : factors) {
                if (factor_to_index.find(factor) == factor_to_index.end()) {
                    factor_to_index[factor] = factor_to_index.size() + 1;
                }

                res[i] = factor_to_index[factor];
            }
        }

        cout << factor_to_index.size() << "\n";
        for (int i : res) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}
