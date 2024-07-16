#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int N;
int A[100010];
int DP[100010];



int f (int cur) {
    // state: cur
    if (cur >= N) return INF;
    if (cur == N - 1) return 0;
    // reccurence: f(cur) = min(f(cur + 1) + abs(A[cur] - A[cur + 1]), f(cur + 2) + abs(A[cur] - A[cur + 2]))
    int &ret = DP[cur];
    if (ret != -1) return ret;
    ret = min(f(cur + 1) + abs(A[cur] - A[cur + 1]), f(cur + 2) + abs(A[cur] - A[cur + 2]));
    // base case: cur == N - 1

    return ret;
}

// State
// - idx: indeks sekarang
// Rekurens
// for prev = 1 to idx - 1
// if A[idx] > A[prev]
// ret = max(ret, f(prev) + 1);
// Base Case


int main () {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    memset(DP, -1, sizeof DP);
    cout << f(0) << endl;


    return 0;
}

int main() {
    int N;
    cin >> N;

    vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    vector<int> dp(N, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < N; ++i) {
        if (i - 1 >= 0) {
            dp[i] = min(dp[i], dp[i - 1] + abs(heights[i] - heights[i - 1]));
        }
        if (i - 2 >= 0) {
            dp[i] = min(dp[i], dp[i - 2] + abs(heights[i] - heights[i - 2]));
        }
    }

    cout << dp[N - 1] << endl;

    return 0;
}


