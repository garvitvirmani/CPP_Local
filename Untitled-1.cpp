#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "DEBUG.h"
#else
#define debug(x)
#endif

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mod 998244353 // 1000000007
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define make_unique(x) \
    sort(all((x)));    \
    (x).resize(unique(all((x))) - (x).begin())
#define ar array
#define vc vector
#define vi vector<int>
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
ll _ceil(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }
/*---------------------------------------------------------------------*/
const int mxn = 1e5;
ll n, m, k, t;

void solve()
{
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    ll ans = 0;
    sort(a.begin(), a.end());
    for (int i = 1; i < n; ++i)
    {
        if (a[i] > (2 * a[0] - 1))
            ans += _ceil(a[i], ((2 * a[0] - 1))) - 1;
    }
    cout << ans << '\n';
}

int main()
{
    fastio();
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}