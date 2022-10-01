#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#include "DEBUG.h"
#else
#define debug(x)
#endif
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt = 1, n = 0, m = 0, k = 0, x = 0;
    cin >> tt;
    while (tt--)
    {
        cin >> n >> k;
        vector<ll> a(k);
        for (auto &e : a)
            cin >> e;

        vector<ll> b;
        int q = 0;
        for (int i = k - 1; i > 0; --i)
        {
            b.push_back(a[i] - a[i - 1]);
            q++;
        }
        b.push_back(a[0]);

        reverse(b.begin(), b.end());
        //       debug(b);
        if (is_sorted(b.begin(), b.end()))
            cout << "YES";
        else
        {
            reverse(b.begin(), b.end());
            b.pop_back();
            int sz = b.size();

            while (sz < n && a[0] != 0)
            {
               
                if (a[0] > 0)
                    a[0]--, b.push_back(-1);
                else if (a[0] < 0)
                    a[0]++, b.push_back(1);
                sz++;
            }
            if (q < (int)b.size())
                b[q] += a[0];

            reverse(b.begin(), b.end());

            if (is_sorted(b.begin(), b.end()))
                cout << "YES";
            else
                cout << "NO";
        }
        cout << '\n';
    }
    return 0;
}