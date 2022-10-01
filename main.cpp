#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#include "DEBUG.h"
#else
#define debug(x)
#endif
const int mxn = 100 + 10;
int dp[mxn][mxn][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt = 1, n = 0, m = 0, k = 0, x = 0;
    //..................

    for (int e = 0; e < mxn; ++e)
    {
        for (auto o = 0; o < mxn; ++o)
        {
            for (int p : {0, 1})
            {
                if (e == 0)
                {
                    if ((o - p + 4) % 4 == 0 || (o - p + 4) % 4 == 3)
                        dp[e][o][p] = 1;
                    else
                        dp[e][o][p] = 0;

                    continue;
                }

                if (o == 0)
                {
                    dp[e][o][p] = 1;
                    continue;
                }
            }
        }
    }
    for (int e = 1; e < mxn; ++e)
    {
        for (int o = 1; o < mxn; ++o)
        {

            // // p1 takes e
            // bool p1e = 0; // it will result in p1 win

            // p1e |= dp[e - 1][o - 1][0];
            // if (e - 2 >= 0)
            //     p1e |= dp[e - 2][o][0];

            // // if (!p1e)
            // //     dp[e][o][0] = 0; // no matter p2 does p1 wins
            // // else
            // //     dp[e][o][0] = 1;

            // bool p1o = 0; // it will result in p1 wins

            // if (o - 2 >= 0)
            //     p1o |= dp[e][o - 2][0];

            // p1o |= dp[e - 1][o - 1][0];

            // // if (!p1o)
            // //     dp[e][o][p] = p; // no matter p2 does p1 wins
            // // else
            // //     dp[e][o][p] = p ^ 1;

            // if (p1e == 0 || p1o == 0)
            //     dp[e][o][0] = 0;
            // else
            //     dp[e][o][0] = 1;
            bool p1 = 0; // it will result in p2 win

            p1 |= dp[e - 1][o][1];

            p1 |= dp[e][o - 1][1];

            if (p1 == 0)
                dp[e][o][0] = 1;
            else
                dp[e][o][0] = 0;
            //......Bob........
            bool p2 = 0; // it will result in p2 win

            p2 |= dp[e - 1][o][0];

            p2 |= dp[e][o - 1][0];

            if (p2 == 1)
                dp[e][o][1] = 1;
            else
                dp[e][o][1] = 0;
        }
    }
    //...............
    cin >> tt;
    while (tt--)
    {
        cin >> n;
        int cnt[2] = {0};
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            cnt[abs(x) % 2]++;
        }
        for (int i = 0; i <= 2; ++i)
        {
            for (int j = 0; j <= 2; ++j)
            {
                cout << dp[i][j][0] << " " << dp[i][j][1] << " * ";
            }
            cout << '\n';
        }
        cout << '\n';
        if (!dp[cnt[0]][cnt[1]][0])
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
    return 0;
}