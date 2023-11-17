#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int N, Q;
long long A[MAXN + 5], B[MAXN + 5];

long long query(int l, int r) {
    return (B[r] - B[l - 1]) - 1ll * (l - 1) * (A[r] - A[l - 1]);
}

int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        B[i] = A[i] * i;
    }

    for (int i = 1; i <= N; i++) {
        A[i] += A[i-1];
        B[i] += B[i-1];
    }
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }

    return 0;
}
