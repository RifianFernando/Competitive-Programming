#include<bits/stdc++.h>
#include<map>
using namespace std;

map cnt;

int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string nama;
        cin >> nama;
        if (!cnt.count(nama)) {
        cout << "OK" << endl;
        }
        else {
        cout << nama << cnt[nama] << endl;
        }
        cnt[nama]++;
    }
    return 0;
}