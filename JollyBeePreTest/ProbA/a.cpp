#include <bits/stdc++.h>

using namespace std;

long long checkMove(int x, int y)
{
    if (abs(x) < abs(y))
    {
        return abs(y);
    }
    else if (abs(x) > abs(y))
    {
        return abs(x);
    }
    return abs(x);
}

int main()
{

    int tc;
    cin >> tc;

    while (tc != 0)
    {
        long long x, y;
        cin >> x;
        cin >> y;
        // x = abs(x);
        // y = abs(y);
        
        cout << checkMove(x, y) << endl;

        tc--;
    }

    return 0;
}
