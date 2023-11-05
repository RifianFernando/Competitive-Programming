#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    if(N<M) {
        int temp =N;
        N=M; 
        M=temp;
    }
    
    if(N * M == K) cout << "0" << endl;
    else if(K % N == 0 || K % M == 0) cout << "1" << endl;
    else if(K < N || K > (N * M) - N) cout << "2" << endl;
    else {
        int count = 0;
        if (M < N) {
            int visited[N][M] = {0};
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (count < K) {
                        visited[i][j] = 1;
                        count++;
                    }
                }
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    cout << visited[i][j];
                }
                cout << endl;
            }
        } else {
            int visited[M][N] = {0};
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (count < K) {
                        visited[i][j] = 1;
                        count++;
                    }
                }
            }

            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    cout << visited[i][j];
                }
                cout << endl;
            }
        }
    }
    
    // else if(__gcd((N*M) ))

}