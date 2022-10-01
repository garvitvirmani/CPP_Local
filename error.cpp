#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "DEBUG.h"
#else
#define debug(x)
#endif

#define fastio()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define mod 998244353 // 1000000007
#define endl "\n"

#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define make_unique(x) \
  sort(all((x)));      \
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
ll n, m, k, t, c, q;
string s;
map<pair<ll, ll>, pair<ll, ll>> mp;

char path(ll x)
{
  if (x >= 0 && x < n)
    return s[x];

  for (auto e : mp)
  {

    auto fi = e.first, sec = e.second;

    ll len = fi.second - fi.first + 1;

    if (x >= fi.first && x <= fi.second)
    {

      ll map_ = sec.first + x - fi.first;

      return path(map_);
    }
  }
  assert(0);
  return '$';

  cout << '$' << "failed" << '\n';
}

void solve()
{

  cin >> n >> c >> q >> s;
  ll next = n, l, r;

  mp.clear();

  for (int i = 0; i < c; ++i)
  {
    cin >> l >> r;
    l--, r--;
    ll len = r - l + 1;
    mp[{next, next + len - 1}] = {l, l + len - 1};
    next += r - l + 1;
  }
  mp[{0ll, n - 1}] = {0ll, n - 1};

  ll k;
  for (int i = 0; i < q; ++i)
  {
    cin >> k;

    cout << path(k - 1ll);
    cout << '\n';
  }
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