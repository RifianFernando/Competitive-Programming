#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
const int MAXA = 1e6;

int N;
int A[MAXN + 5], ans[MAXN + 5], freq[MAXA + 5];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        freq[A[i]]++;
    }
    /*
    lemma: jawabannya pasti diantara 1..A_max
    proof: GCD gak mungkin naik jawabannya
    */
    for (int i = 1; i <= MAXA; i++) {
        int cnt = 0;
        for (int j = i; j <= MAXA; j += i) {
            cnt += freq[j];
        }
        ans[cnt] = max(ans[cnt], i);
    }
    /*
    lemma: jawabannya non-increasing
    proof: kalo sizenya lebih kecil, kita tinggal ambil subsetnya aja
    */
    for (int i = N - 1; i >= 1; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}