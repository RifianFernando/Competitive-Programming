// DP (Coin Change + Knapsack)
// Coin Change

// f(x) = banyaknya pecahan uang minimum jika uang kita "x"

// Ada 3 kemungkinan, minimum dari:
// 1. Ambil pecahan 1: 1+f(x-1)
// 2. Ambil pecahan 3: 1+f(x-3)
// 3. Ambil pecahan 4: 1+f(x-4)

// f(x) = min(1+f(x-1), 1+f(x-3), 1+f(x-4))

// Base Case
// 1. x = 0, return 0
// 2. x < 0, return INVALID

// DP itu cuma Shortest Path?

// DP -> rekursi -> stack -> DFS
// Shortest Path -> queue -> BFS

// 1. Solusi DP salah? Tidak
// 2. Argumen "DP itu cuma Shortest Path" itu salah? Bener
// 3. Shortest Path bisa pake DFS? Bener, jika graph tidak ada cycle
// 4. Berarti bisa solve Shortest Path pake DP? Kalo DP tadi gak bisa. Apakah ada DP lain yang bisa solve ini? Bellman-Ford Algorithm.

// "DP hanya bisa jalan kalo dia gak ada cycle"
// 1. Tree
// 2. DAG

// Kesimpulan: DP itu algo state-space search in DAG

// State?
// Rekurens?
// Base Case?

// Knapsack
// N barang, ada tas kapasitas C
// Barang ke-i value V[i] berat W[i]
// Total value maximum tapi total berat <= C

// f(idx, c) = total value maximum jika kapasitas tas "c" dan kita skrg di barang "idx"
// rekurens:
// - ambil barang idx, f(idx+1, c-W[idx])+V[idx]
// - skip, f(idx+1, c)
// Base case
// if c < 0, return INVALID
// if idx > N, return 0

// Coin Change (Top Down)

#include <bits/stdc++.h>
using namespace std;

const int INVALID = 1e9;

int DP[10000000];

int f(int x)
{
    if (x < 0)
        return INVALID;
    if (x == 0)
        return 0;

    if (DP[x] != -1)
        return DP[x];

    int ret = 1 + f(x - 1);
    ret = min(ret, 1 + f(x - 3));
    ret = min(ret, 1 + f(x - 4));

    DP[x] = ret;
    return ret;
}

int main()
{
    int N = 9999999;
    // cin >> N;

    memset(DP, -1, sizeof DP);
    cout << f(N) << endl;
    return 0;
}

// Coin Change(Bottom Up)

const int INVALID = 1e9;

int DP[10000000];

int main1()
{
    int N = 9999999;
    // cin >> N;

    DP[0] = 0;
    for (int x = 1; x <= N; x++)
    {
        DP[x] = 1 + DP[x - 1];
        if (x >= 3)
            DP[x] = 1 + DP[x - 3];
        if (x >= 4)
            DP[x] = 1 + DP[x - 4];
    }

    cout << DP[N] << endl;
    return 0;
}