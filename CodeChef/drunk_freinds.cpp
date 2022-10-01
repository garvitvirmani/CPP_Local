#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int query = 1, n = 0, k = 0, t = 0, x, nxt, y, val1, val2, idx1, idx2;

    cin >> n >> query;

    map<int, int> bottel, pos; // pos takes bottel no. gives positon
                               // bottel takes index and gives bottel no.

    for (int i = 1; i <= n; ++i)
    {

        cin >> x;
        bottel[i] = x,
        pos[x] = i;
    }

    while (query--)
    {
        cin >> x >> y;

        idx1 = pos[x];
        idx2 = pos[y];

        val1 = bottel[idx1];
        val2 = bottel[idx2];

        // now do swaping in O(1)

        bottel[idx1] = y;
        bottel[idx2] = x;

        pos[val1] = idx2;
        pos[val2] = idx1;
    }

    for (int i = 1; i <= n; ++i)
        cout << bottel[i] << " ";

    return 0;
}