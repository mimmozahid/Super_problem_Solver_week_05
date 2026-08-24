#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;

template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

vector<int> g[5000];
vector<int> w(5000), b(5000);
int ans;

void dfs (int src)
{
    for (auto child : g[src])
    {
        dfs(child);
        w[src] += w[child];
        b[src] += b[child];
    }

    if (w[src] == b[src]) ans++;
}

void solve ()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
        w[i] = 0;
        b[i] = 0;
    }

    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        g[x].push_back(i);
    }

    string s;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'W') w[i+1]++;
        if (s[i] == 'B') b[i+1]++;
    }
    
    ans = 0;
    
    dfs (1);

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--)
        solve ();

    return 0;
}