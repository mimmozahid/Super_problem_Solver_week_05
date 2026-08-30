#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
#define MOD 998244353

template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
int n;
vector<vector<char>> mat(1005, vector<char>(1005, '.'));
vector<vector<bool>> vis(1005, vector<bool> (1005, false));
int ax, ay, bx, by, cx, cy;
bool ans;

bool valid (int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >=n)
        return false;
    return true;
}

void dfs (int si, int sj)
{
    if (si == cx && sj == cy)
    {
        ans = true;
        return;
    }

    vis[si][sj] = true;

    for (int i = 0; i < 8; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid(ci, cj) && !vis[ci][cj] && mat[ci][cj] == '.')
            dfs (ci, cj);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    ax--, ay--, bx--, by--, cx--, cy--; 
    ans = false;

    for (int i = 0; i < n; i++)
    {
        mat[ax][i] = '#';
        mat[i][ay] = '#';
    }
    
    for (int i = 0; i < n; i++)
    {
        if(valid (ax+i, ay+i))
            mat[ax+i][ay+i] = '#';

    }
    int aax = ax , aay = ay;
    

    while (valid (aax, aay))
    {
        mat[aax][aay] = '#';
        aax--, aay--;
    }
    aax = ax, aay = ay;
    while (valid (aax, aay))
    {
        mat[aax][aay] = '#';
        aax++, aay--;
    }
    aax = ax, aay = ay;
    while (valid (aax, aay))
    {
        mat[aax][aay] = '#';
        aax--, aay++;
    }
    
    dfs (bx, by);
    
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}