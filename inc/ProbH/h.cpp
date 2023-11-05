#include <bits/stdc++.h>
using namespace std;

int N, M, S[100009], smallest = 1000000000;
priority_queue<pair<int, int>> W;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    // input
    cin >> N >> M;
    // for(int i =0; N>i; i++) {
    //     cin >> W[i].second >> W[i].first;
    //     if(smallest>W[i].second) smallest = W[i].second;
    // } 
    // int smallest = INT_MAX;

    for (int i = 0; i < N; i++) {
        int val, inst;
        cin >> inst >> val;
        // smallest = min(smallest, inst);
        if(smallest > inst) smallest = inst;
        W.push({val, inst});
    }
    for(int i=0; M>i; i++) {
        cin >> S[i];
    }

    // sorting
    // sort(W, W+N);
    sort(S, S+M);
    
    
    // for(int i=0; N>i; i++) {
    //     // cout<<W[i].first<<" "<<W[i].second<<endl;
    //     cout << W.top().first << " " << W.top().second << endl;
    //     W.pop();
    // }
    // for(int i = 0; i < N; i++) {
    //     cout << S[i] << endl;
    // }

    // cari total Value
    long long totalValue=0;
    for(int i = 0; M>i; i++) {
    //  cout<<"masuk"<<endl;
        for(int j = N-1; j >= 0; j--) {
            if(S[i] < smallest) break;
            //   cout<<"masuk"<<endl;
            // if(S[i] >= W[j].second && W[j].second !=0) {
            // cout << "before " << S[i] << " " << W.top().second << " " << W.top().first << endl;
            if(S[i] >= W.top().second && W.top().second) {
                // cout << S[i] << " " << W[j].second << " " << W[j].first << endl;
                // cout << S[i] << " " << W.top().second << " " << W.top().first << endl;
                // totalValue += W[j].first;
                totalValue += W.top().first;
                // W[j].second =0;
                W.pop();
                break;
            } else {
                W.pop();
            }
        }
    }
    cout << totalValue << endl;
    
}