#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ad = a*d, bc = b*c;
    if (ad <= bc) {
        int e = bc - ad;
        int g = gcd(e, bc);
        cout << e/g << "/" << bc/g << "\n";
    } else if (ad >= bc) {
        int e = ad - bc;
        int g = gcd(e, ad);
        cout << e/g << "/" << ad/g << "\n";
    } else {
        cout << "0\n";
    }

    return 0;
}

