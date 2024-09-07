#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a;
    cin >> b;

    int count = 0;
    while (a != b)
    {
        // if a dikurang tidak = 1              
        if ((a * 2) - b > 3)
        {
            a--;
            count++;
        }
        else
        {
            a *= 2;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}