#include<bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define fr front()
#define pb push_back
#define t top()

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define oo 1e18
#define eps 1e-8
#define pow poww
#define int long long

const int N = 1e5 + 5;
int n , m , res;
int f[N] , F[N] , c[N];
vector < ii > g[N];

bool is_lucky(int u)
{
    while (u) {
        if(u % 10 != 4 && u % 10 != 7) return (false);
        u /= 10;
    }
    return (true);
}

void DFS1(int u , int e)
{
    c[u] = 1;
    REP(s , g[u].size()) // for (int i = 0; i < g[u].size(); ++i)
    {
        int v = g[i][s].fi;
        int w = g[i][s].se;
        if(v != e)
        {
            DFS1(v , u);
            c[u] += c[v];
            if(w == 1)
                f[u] += c[v];
            else
                f[u] += f[v];
        }
    }
}

void DFS2(int u , int e)
{
    REP(s , g[u].size())
    {
        int v = g[u][s].fi;
        int w = g[u][s].se;
        if(v != e)
        {
            if(w == 1)
                F[v] = n - c[v];
            else
                F[v] = F[u] + f[u] - f[v];
            DFS2(v, u);
        }
    }
}

main()
{
    freopen ("lucky.inp", "r", stdin);
    freopen ("lucky.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i , 1 , n - 1)
    {
        int u , v , k;
        cin >> u >> v >> k;
        k = is_lucky(k);
        g[u].pb(ii(v , k));
        g[v].pb(ii(u , k));
    }
    DFS1(1 , -1);
    DFS2(1 , -1);
    FOR(i , 1 , n)
        res += f[i] * (f[i] - 1) + (F[i] * (F[i] - 1)) + 2 * f[i] * F[i];
    cout << res;
}
