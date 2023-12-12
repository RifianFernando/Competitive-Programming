#include <bits/stdc++.h>

using namespace std;

// string result(long long x, long long y)
// {
//     long long max = 0;
//     if (x < y)
//     {
//         max = y / 2;
//         if (max - 1 > 0) {
//             max--;
//         }
//     } else {
//         max = x / 2;
//         if (max - 1 > 0) {
//             max--;
//         }
//     }
//     // for (int i = 0; i < max; i++) {
//         if (max > x || max > y) {
//             return "Tidak";
//         }

//         // perkalian 2
//         if (2 * max == y || 2 * max == x) {
//             return "Ya";
//         } else if (2 * max > y && 2 * max < x) {
//             x -= (max * 2);
//             if (1 * max < y) {
//                 y -= max;
//             }
//             cout << "perkalian 2: " << x << " " << y << endl;
//         } else if (2 * max > x && 2 * max < y) {
//             y -= (max * 2);
//             if (1 * max < x) {
//                 x -= max;
//             }
//             cout << "perkalian 2: " << x << " " << y << endl;
//         }
//     // }
//     if (x == y) {
//         if (x %2 != 0 && x < 2) return "Tidak";
//         return "Ya";
//     }
//     result(x, y);
//     // return "Ya";
// }

string result(long long x, long long y)
{
    if (x == 0 && y == 0) {
        return "Ya";
    }
    
    if (x % 3 != 0 || y % 3 != 0) {
        return "Tidak";
    }

    if ((2 * x) >= y && (2 * y) >= x) {
        return "Ya";
    }

    return "Tidak";
}

int main()
{
    int tc;
    cin >> tc;

    while (tc != 0)
    {
        long long x, y;
        cin >> x; cin >> y;

        cout << result(x, y) << endl;

        tc--;
    }

    return 0;
};
