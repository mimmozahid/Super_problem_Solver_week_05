#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
#define MOD 998244353

template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
int n;

void bfs (int src, vector<vector<int>> &adj_list, vector<int>& vis)
{
    ll cnt[2] = {0, 0};

    queue<int> q;
    q.push(src);
    vis[src] = 0;
    cnt[0]++;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (auto child : adj_list[par])
        {
            if (vis[child] == -1)
            {
                q.push(child);
                vis[child] = vis[par] ^ 1;
                cnt[vis[child]]++;
            }
        }
    }
    
    ll mx_ed = cnt[0]*cnt[1];
    ll ans = mx_ed - (n-1);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    cin >> n;
    vector<vector<int>> adj_list(n+1);
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    
    vector<int> vis(n+1, -1);
    bfs (1, adj_list, vis);
    
    return 0;
}