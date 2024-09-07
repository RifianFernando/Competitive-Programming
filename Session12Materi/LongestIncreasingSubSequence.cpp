// state-space search in acyclic
// a.k.a DP

// Longest Increasing Subsequence

// Hint: O(N^2)
// 6 2 3 7 4 5 8

// f(idx, prev) = LIS
// State
// 1. idx sekarang
// 2. previous idx
// Rekurens
// 1. Ambil, if (A[idx] > A[prev]) f(idx+1, idx)+1
// 2. Skip, f(idx+1, prev)

// Definisi
// f(idx) = LIS dari A[1..idx] dan A[idx] harus diambil
// State
// - idx: indeks sekarang
// Rekurens
// for prev = 1 to idx - 1
// if A[idx] > A[prev]
// ret = max(ret, f(prev) + 1);
// Base Case

// Bellman-Ford Algorithm O(V*E)
// Define f(u, step) = shortest path dari start ke u dan kita udah jalan berapa step
// State
// u = current node
// step = udah jalan berapa langkah
// Rekurens
// for v: adj[u]
// ans = min(ans, f(v, step + 1) + W[u][v])
// Base Case
// if (step > N) return INVALID
// if (u == finish) return 0

// Lemma
// Suatu shortest path pasti ngelewatin at most semua node

// -> kalo kita step nya N+1 dan actually masih ngeimprove shortest pathnya, berarti ada negative cycle (jawabannya -INF)

// for u: all nodes
// if (f(u, N) > f(u, N+1))
// ada negative cycle -> return -INF

// ans = 0;
// for
//     i = 0 to N
//         ans = min(ans, f(finish, i)) return ans;

// Kode Knapsack

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 100;
const int MAXC = 100;

int N, C;
int W[MAXN + 5], V[MAXN + 5];
int DP[MAXN + 5][MAXC + 5];

int f(int idx, int cap)
{
    // base case invalid
    if (cap < 0)
        return -INF;
    // base case valid
    if (idx == N)
        return 0;
    // memoisasi
    int &ret = DP[idx][cap];
    if (ret != -1)
        return ret;
    // rekurens
    ret = f(idx + 1, cap);
    ret = max(ret, f(idx + 1, cap - W[idx]) + V[idx]);
    return ret;
}

int main()
{
    // cin >> N >> C;
    N = 50;
    C = 50;
    for (int i = 0; i < N; i++)
    {
        // cin >> W[i] >> V[i];
        W[i] = 1;
        V[i] = 1;
    }
    memset(DP, -1, sizeof DP);
    cout << f(0, C) << endl;
    return 0;
}

/*
4 10
4 6
7 10
5 5
1 2
*/

// Kode LIS (Longest Increasing Subsequence)

const int INF = 1e9;
const int MAXN = 100;

int N;
int A[MAXN + 5];
int DP[MAXN + 5][MAXN + 5];

int f(int idx, int prev)
{
    if (idx > N)
        return 0;
    int &ret = DP[idx][prev];
    if (ret != -1)
        return ret;
    ret = f(idx + 1, prev);
    if (A[idx] > A[prev])
        ret = max(ret, f(idx + 1, idx) + 1);
    return ret;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    A[0] = 0;
    memset(DP, -1, sizeof DP);
    cout << f(1, 0) << endl;
    return 0;
}

/*
7
6 2 3 7 4 5 8
*/

// Kode LIS(bottom up + 1 state)

const int INF = 1e9;
const int MAXN = 100;

int N;
int A[MAXN + 5];
int DP[MAXN + 5];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
    {
        DP[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j])
            {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = max(ans, DP[i]);
    cout << ans << endl;
    return 0;
}

/*
7
6 2 3 7 4 5 8
*/