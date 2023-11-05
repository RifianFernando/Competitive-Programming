#include <bits/stdc++.h>
using namespace std;

int N, M, S[100009], smallest = 1000000000;
pair <int, int> W[100009];

int main() {
 ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
 // input
 cin>>N>>M;
 for(int i =0; N>i; i++) {
  cin>>W[i].second>>W[i].first;
  if(smallest>W[i].second) smallest = W[i].second;
 }
 for(int i=0; M>i; i++) {
  cin>>S[i];
 }

 // sorting
 sort(W, W+N);
 sort(S, S+M);
 
 
// for(int i=0; N>i; i++) {
//  cout<<W[i].first<<" "<<W[i].second<<endl;
// }

 // cari total Value
 long long totalValue=0;
 for(int i=0; M>i; i++) {
//  cout<<"masuk"<<endl;
  for(int j = N-1; j>=0; j--) {
   if(S[i] < smallest) break;
//   cout<<"masuk"<<endl;
                cout << "before " << S[i] << " " << W[j].second << " " << W[j].first << endl;
   if(S[i] >= W[j].second && W[j].second !=0) {
                cout << S[i] << " " << W[j].second << " " << W[j].first << endl;
    totalValue += W[j].first;
    W[j].second =0;
    break;
   }
  }
 }
 cout<<totalValue<<endl;
 
}