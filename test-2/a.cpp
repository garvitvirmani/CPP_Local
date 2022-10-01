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
    ll tt = 1, n = 0, m = 0, k = 0, t = 0;
    cin >> tt;
    while (tt--)
    {
        ll alice, bob;
        cin >> alice >> bob;
        ll wins[2] = {0};
        ll d = abs(alice - bob);

        if (alice > bob)
        {
            wins[0] = alice - 1;
            wins[1] = bob;
        }
        else if (bob > alice)
        {

            wins[1] = bob;
            wins[0] += alice - 1;
        }
        else
            wins[0] = alice - 1, wins[1] = alice;

        cout << wins[0] << " " << wins[1] << '\n';
    }
    return 0;
}