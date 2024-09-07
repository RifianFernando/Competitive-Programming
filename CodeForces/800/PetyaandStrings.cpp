#include <bits/stdc++.h>
using namespace std;
 
int main () {
    string firstLetter;
    string secondLetter;

    cin >> firstLetter;
    cin >> secondLetter;

    int countFirstLetter = 0;
    int countSecondLetter = 0;

    for (int i = 0; i < firstLetter.length(); i++) {
        if (firstLetter[i] > 90) {
            countFirstLetter += (firstLetter[i] - 32);
        } else {
            countFirstLetter += firstLetter[i];
        }
        if (secondLetter[i] > 90) {
            countSecondLetter += (secondLetter[i] - 32);
        } else {
            countSecondLetter += secondLetter[i];
        }
    }
    int ans;
    if (countFirstLetter < countSecondLetter) {
        ans = -1;
    } else if (countFirstLetter == countSecondLetter) {
        ans = 0;
    } else ans = 1;

    cout << ans << endl;

    return 0;
}