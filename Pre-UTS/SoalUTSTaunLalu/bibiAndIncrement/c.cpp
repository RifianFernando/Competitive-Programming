#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K, X;
    cin >> N >> K >> X;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < N; ++i) {
        int Ai;
        cin >> Ai;
        minHeap.push(Ai);
    }

    while (K--) {
        int smallest = minHeap.top();
        minHeap.pop();
        smallest += X;
        minHeap.push(smallest);
    }

    cout << minHeap.top() << endl;

    return 0;
}
