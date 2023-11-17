#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;

int N;
long long T[MAXN + 5], L[MAXN + 5];
map<int, int> cnt;

int main() {
    cin >> N;
    long long maks = 0;

    for (int i = 0; i < N; i++) {
        cin >> T[i] >> L[i];
        cnt[T[i]]++;
    }

    long long cur = 0;

    for (auto &p : cnt) {
        int t = p.first;
        int l = p.second;
        if (cur < t) cur = t;
        cur = cur + l - 1;
    }

    cout << cur << endl;

    return 0;
}

