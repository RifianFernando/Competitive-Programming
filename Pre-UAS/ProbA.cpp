#include<bits/stdc++.h>

using namespace std;
 
// void print() {
//     while(!pq.empty()) {
//         pair<int, int> current = pq.top();
//         cout << current.first << " " << current.second << endl;
//         pq.pop();
//     }
//     cout << " printed";
// }
int W[10001], V[10001];
int N, M; 
int value = 0;

// int f(int curr, int count) {
//     // state
//     // state ada di curr
//     // curr = index w and v
//     if (curr > N) return 0;
//     // if (count > M) return -1;
    
//     // reccurence 
//     int &ret = W[curr];
//     if (ret <= M) {
//         count += ret;
//     } else {
//         count += max(f(0))
//     }


//     return count;
// }

int main() {
    cin >> N; cin >> M;
    for (int i = 0; i < N; i++) {
        cin >> W[i]; cin >> V[i];
    }

    


    return 0;
}