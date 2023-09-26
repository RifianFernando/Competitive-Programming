#include<bits/stdc++.h>

using namespace std;

bool prime[100005];
long long primeArr[100005];
void sieve(int n){
    memset(prime, true, sizeof prime);
    for (int p=2; p * p <= n; p+=1){
        if (prime[p]==true) {
            for (int i=p*p;i<=n;i+=p){
                prime[i]=false;
            }
        }
    } 
}

void primeArray(int n) {
    int j = 0;
    for (int i = 2; i <= n; i++) {
        if (prime[i] == true) {
            primeArr[j] = i;
            j++;
        }
    }
}

long long checkHexPrime(long long b) {
    if (b < 2) return 0;
    long long loop = 2;
    long long count = 0;
    // while (loop < b) {
    //     if (prime[loop] == true && prime[loop + 6] == true) {
    //         count++;
    //     };
    //     loop++;
    // }
    for (int i = 0; i < 100005; i++) {
        if (primeArr[i] > b) break;
        if (prime[primeArr[i]] == true && prime[primeArr[i] + 6] == true) {
            count++;
        }
    }
    return count;
}

int main() {
    sieve(100005);
    primeArray(100005);
	long long a; cin >> a;
    
	for (int i = 0; i < a; i++) {
		long long b; cin >> b;
		cout << checkHexPrime(b) << endl;
	}
}
