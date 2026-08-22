#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;

template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, root;
    cin >> n;
    vector<int> g[n+1], bad(n+1), a(n+1);
    for (int i = 1; i <= n; i++)
    {
        int p, c;
        cin >> p >> c;
        
        if (p != -1)
            g[p].push_back(i);
        else
            root = i;
        
        if (c == 1)
        {
            bad[p]++;
            a[i] = 1;
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (i == root) continue;

        if (g[i].size() == bad[i] && a[i] == 1)
            ans.push_back(i);
    }

    if (ans.empty())
        cout << -1 << endl;
    else
    {
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}