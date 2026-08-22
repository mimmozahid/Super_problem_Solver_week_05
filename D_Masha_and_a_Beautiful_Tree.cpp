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
    vector<int> v(n);
    for (auto &x : v) cin >> x;

    int ans = 0;

    for (int i = 2; i <= n; i*=2)
    {
        for (int j = 0; j < n; j+= i)
        {
            if (v[j] > v[j+(i/2)])
            {
                swap_ranges(v.begin()+j, v.begin()+j+(i/2), v.begin()+j+(i/2));
                        //!|<-------first array--------->|  |<--2nd Array-->|
                ans++;
            }
        }
    }
    bool ok = true;
    for (int i = 1; i < n; i++)
    {
        if (v[i-1] > v[i])
        {
            ok = false;
            break;
        }
    }

    if (ok)
        cout << ans << endl;
    else
        cout << -1 << endl;
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