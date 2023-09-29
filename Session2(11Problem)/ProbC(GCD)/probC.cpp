#include<bits/stdc++.h>

using namespace std;

long long findDivisors(long n) {
    long long count = 0;
    for (long i = 1; i < int(sqrt(n) + 1); i++) {
        if (n % i == 0) {
            count++;
            if (i != n / i) {
                count++;
            }
        }
    }
    return count;
}

long long answerArray[1000005];
void preCompute (){
    for (int i = 1; i <= 1000; i++) {
        answerArray[i] = findDivisors(i);
    }
}

int main() {
    preCompute();
	long long a; cin >> a;
	for (int i = 0; i < a; i++) {
		long long b; cin >> b;
        if (answerArray[b] == 3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
	}
    return 0;
}
