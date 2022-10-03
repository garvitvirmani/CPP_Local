#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#include "DEBUG.h"
#else
#define debug(x)
#endif
const int MAX = 1000;

// Create an array for memoization
ll f[MAX] = {0};
ll fib(ll n)
{
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);

    // If fib(n) is already computed
    if (f[n])
        return f[n];

    ll k = (n & 1) ? (n + 1) / 2 : n / 2;

    // Applying above formula [Note value n&1 is 1
    // if n is odd, else 0].
    f[n] = (n & 1) ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1))
                   : (2 * fib(k - 1) + fib(k)) * fib(k);

    return f[n];
}
/*

fib(n) -> log(n) gives F(n)
s(n) -> f(n+2)-1
s**(n)-> s(n-1) + (n&1)
// 1 1 2 3 5 8
// 1 2 3 4 5 6


*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt = 1, n = 0, m = 0, k = 0, x = 0;
    cin >> tt;
    while (tt--)
    {
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        ll sum = accumulate(a.begin(), a.end(), 0ll);
    }
    return 0;
}