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

int n, m;
ll a;
vector<vector<int>> mat(1005, vector<int> (1005));
vector<vector<bool>> vis;
vector<pair<int, int>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool vaild (int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs (int si, int sj)
{
    a += mat[si][sj];
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si+d[i].first;
        int cj = sj+d[i].second;

        if (vaild(ci, cj) && !vis[ci][cj] && mat[ci][cj] != 0)
            dfs (ci, cj);
    }
}

void solve ()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    vis.assign (n, vector<bool>(m, false));
    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && mat[i][j] != 0)
            {
                a = 0;
                dfs (i, j);
                ans = max (ans, a);
            }
        }
        
    }
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

