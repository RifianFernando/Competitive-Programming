#include<bits/stdc++.h>

using namespace std;

// map<long long, long long> primeFactorization(long long N) { // O(sqrt(N))
// 	map<long long, long long> cnt;
// 	for (long long i = 2; i*i <= N; i++) {
// 		while (N % i == 0) {
// 			cnt[i]++;
// 			N /= i;
// 		}
// 	}
// 	if (N != 1) cnt[N]++;
// 	return cnt;
// }

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// int findGCD(vector<string>& arr) {
//     int result = stoi(arr[0]);
    
//     for(int i = 1; i < arr.size(); i++) {
//         result = gcd(result, stoi(arr[i]));
//     }
    
//     return result;
// }

int main() {
    string b; cin >> b;
    string c; cin >> c;
    vector<string> arr = {b, c};
    int result = findGCD(arr);
    cout << result << endl;
    return 0;
}
