#include<bits/stdc++.h>

using namespace std;

long long countPairs(vector<long long>& arr) {
    int n = arr.size();
    unordered_map<long long, int> xor2_count, xor4_count;

    long long result = 0;

    for (int i = 0; i < n; ++i) {
        xor2_count[arr[i] % 2]++;
        xor4_count[arr[i] % 4]++;
    }

    for (int i = 0; i < n; ++i) {
        xor2_count[arr[i] % 2]--;
        xor4_count[arr[i] % 4]--;

        // Calculate the XOR for both bases
        long long xor2_result = (arr[i] % 2 == 0) ? (arr[i] ^ 2) : (arr[i] ^ 0);
        long long xor4_result = (arr[i] % 4 == 0) ? (arr[i] ^ 4) : (arr[i] ^ 0);

        result += xor2_count[xor2_result % 2] + xor4_count[xor4_result % 4];
    }

    return result / 2;  // Each pair is counted twice
}

int main() {
    int n; cin >> n;
    vector<long long> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    long long result = countPairs(A);

    cout << result << endl;

    return 0;
};
