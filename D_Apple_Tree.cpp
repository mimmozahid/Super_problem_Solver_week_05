#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 


#define MOD 998244353

int power (int x, int n)
{
    int ans = 1%MOD;
    while (n)
    {
        if (n & 1)
        {
            ans = (1LL * ans%MOD * x%MOD);
        }
        x = 1LL * x * x % MOD;
        n>>=1;
    }
    return ans;
}

vector<ll> cnt_leaf(2e5+9);

ll dfs (int src, vector<vector<int>>& adj_list, vector<bool>& vis, vector<int>& parent)
{
    cnt_leaf[src] = 0;
    vis[src] = true;

    bool lf = true;
    for (auto child : adj_list[src])
    {
        if (!vis[child])
        {
            lf = false;
            parent[child] = src;
            cnt_leaf[src] += dfs(child, adj_list, vis, parent);
        }
    }

    if (lf)
    {
        cnt_leaf[src] = 1;
    }

    return cnt_leaf[src];
}

void solve ()
{
    int n; cin >> n;
    vector<vector<int>> adj_list(n+1);
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    vector<bool> vis(n+1, false);
    vector<int> parent(n+1, -1);
    int a = dfs (1, adj_list, vis, parent);

    int q; cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        cout << cnt_leaf[x]*cnt_leaf[y] << endl;
    }
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

