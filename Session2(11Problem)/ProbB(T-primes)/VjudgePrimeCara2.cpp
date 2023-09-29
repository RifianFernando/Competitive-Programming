#include<bits/stdc++.h>
using namespace std;


bool prime[1000006];
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

void checkTPrime(long long a) {
	if (a < 2) {
		cout << "NO" << endl;
	} else if (sqrt(a) == (int)sqrt(a)) {
		if(prime[(int)sqrt(a)] == true) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	} else {
		cout << "NO" << endl;
	}
}

int main() {
    sieve(1000005);
	long long a; cin >> a;
	for (int i = 0; i < a; i++) {
		long long b; cin >> b;
		checkTPrime(b);
	}
}
