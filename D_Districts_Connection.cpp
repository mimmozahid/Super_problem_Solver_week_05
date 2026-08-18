#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;

template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

void solve ()
{
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    
    bool flg = false;
    for (int i = 2; i <=n; i++)
    {
        if (v[1] != v[i])
        {
            flg = true;
            break;
        }
    }
    
    if (flg)
    {
        int dis = -1;
        cout << "YES\n";
        for (int i = 2; i <= n; i++)
        {
            if (v[1] != v[i])
            {
                cout << 1 << " " << i << endl;
                dis = i;
            }
        }
        
        for (int i = 2; i <= n; i++)
        {
            if (v[1] == v[i])
                cout << dis << " " << i << endl;
        }
    }
    else
        cout << "NO" << endl;
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