#include<bits/stdc++.h>
using namespace std;

//check apakah bilangan prima atau bukan
// cara lama
bool isPrime(long long int x){
//	komplexitas o(n)
	if(x < 2) return false;
	for (int i = 2; i < x; i++){
		if (x % i == 0) return false;
	}
	return true;
}

//	kita bisa pakai akar n agar lebih cepat
//    karena agar tidak time limit
bool isPrime(long long x){
//	komplexitas akar n
	if(x < 2) return false;
	for (long long i = 2; i * i <= x; i++){
		if (x % i == 0) return false;
	}
	return true;
}

// cara harmonik
bool prime[10000+5];
// cara generate prime aristoapalah itu
void generatePrime(int N){
	memset(prime, true, sizeof true);
	prime[0] = prime[1] = false;
	for (int i = 2; i*i <= N; i++) {
		if (!prime[i]) continue;
		for (int j = i*i; j <= N; j+= i) {
			prime[j] = false;
		}
	}
	for (int i = 1; i<= N; i++){
		
	}
}

int SPF[10000005];
void generatePrime(int N){
	memset(SPF, -1, sizeof SPF);
	for (int i = 2; i*i <= N; i++) {
		if ( SPF[i] != i) continue;
	}
}

void precompute(int N) {
	for (int i = 1; i <= N; i++) {
		SPF[i] = i;
	}
	for (int i = 2; i*i <= N; i++) {
		if (SPF[i] != i) continue;
		for (int j = i*i; j <= N; j += i) {
			SPF[j] = min(SPF[j], i);
		}
	}
}

map<int, int> primeFactorization(int N) { // O(sqrt(N))
	map<int, int> cnt;
	for (int i = 2; i*i <= N; i++) {
		while (N % i == 0) {
			cnt[i]++;
			N /= i;
		}
	}
	if (N != 1) cnt[N]++;
	return cnt;
}

bool isPrime(long long x) {	// O(sqrt(N))
	if (x < 2) return false;
	for (long long i = 2; i*i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

//map<int, int> primeFactorization(int N) {	// O(log N)
//	map<int, int> cnt;
//	while (N != 1) {
//		cnt[SPF[N]]++;
//		N /= SPF[N];
//	}
//	return cnt;
//}
bool isPrime(long long x) {	// O(sqrt(N))
	if (x < 2) return false;
	for (long long i = 2; i*i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
//	precompute(1000);
	map<int,int> ans = primeFactorization(1000000007);
	for (auto data:ans) {
		cout << data.first << " " << data.second << endl;
	}


	
}


