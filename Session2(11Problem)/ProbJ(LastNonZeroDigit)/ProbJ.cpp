#include <iostream>
using namespace std;

int lastNonZeroDigit(int N, int M) {
    int result = 1;

    for (int i = N; i > N - M; i--) {
        int x = i;

        // Remove powers of 5
        while (x % 5 == 0) {
            x /= 5;
        }

        // Remove powers of 2
        while (x % 2 == 0) {
            x /= 2;
            result *= 2;
        }

        result = (result * x) % 10;
    }

    return result % 10;
}

int main() {
    int N, M;

    while (cin >> N >> M) {
        int result = lastNonZeroDigit(N, M);
        cout << result << endl;
    }

    return 0;
}
