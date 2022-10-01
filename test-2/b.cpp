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
    int tt = 1, n = 0, x, m = 0, k = 0, t = 0;
    cin >> tt;
    while (tt--)
    {
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        int ops = 0;

        vector<int> faulty;
        for (int i = 0; i < n - 1; ++i)
        {
            if (a[i] > a[i + 1])
                faulty.push_back(i);
        }
        reverse(faulty.begin(), faulty.end());

        for (int i = 0; i < n && faulty.size() > 0; ++i)
        {
            int to_fix = faulty.back();

            if (x < a[i])
            {
                swap(x, a[i]);
                ops++;
            }
            if (i == to_fix)
            {
                assert(i + 1 < n);
                if (a[i] > a[i + 1]) // not possible to fix
                    break;
                else
                    faulty.pop_back();
            }
        }
        if (is_sorted(a.begin(), a.end()))
            cout << ops;
        else
            cout << -1;
        cout << '\n';
    }
    return 0;
}