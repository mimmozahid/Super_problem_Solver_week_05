#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;

template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

const int maxN = 3e5 + 9;
vector<int> mat[maxN], operation(maxN);
string s;

void dfs (int u)
{
    if (mat[u][0] != 0)
    {
        int v = mat[u][0];

        if (s[u-1] != 'L')
            operation[v] = operation[u]+1;
        else
            operation[v] = operation[u];

        dfs(v);
    }

    if (mat[u][1] != 0)
    {
        int v = mat[u][1];

        if (s[u-1] != 'R')
            operation[v] = operation[u]+1;
        else
            operation[v] = operation[u];

        dfs(v);
    }
}

void solve ()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        mat[i].clear();
        operation[i] = 0;
    }
    cin >> s;

    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        mat[i].push_back(a);
        mat[i].push_back(b);
    }
    dfs (1);

    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        if (mat[i][0] == 0 && mat[i][1] == 0)
            ans = min (ans, operation[i]);
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