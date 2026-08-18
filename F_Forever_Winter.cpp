#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;

template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

void solve ()
{
    int n, e;
    cin >> n >> e;
    map<int, pbds<int>> g;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].insert (b);
        g[b].insert (a);
    }
    
    int leaf = -1, parent = -1;
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() == 1)
        {
            leaf = i;
            break;
        }
    }
    
    int x , y;
    for (int i = 1; i <= n; i++)
    {
        if (g[i].find (leaf) != g[i].end ())
        {
            parent = i;
            y = g[i].size()-1;
            break;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (g[i].find(parent) != g[i].end() && g[i].size() > 1)
        {
            x = g[i].size ();
            break;
        }
    }
    
    cout << x << " " << y << endl;
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