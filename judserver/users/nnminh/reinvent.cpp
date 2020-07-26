#include<bits/stdc++.h>
using namespace std;

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , x) for(int i = 0 ; i < x ; ++i)

#define ii pair < int , int >
#define iii pair < int , ii >

#define fi first
#define se second
#define t front()
#define fr front()
#define pb push_back

const int N = 1e5 + 5;
int n , m , k;
int a[N];
ii dist[N][3];
vector < int > g[N];
queue < iii > q;

void dijk()
{
    while(!q.empty())
    {
        int val = q.t.fi;
        int u = q.t.se.fi;
        int uu = q.t.se.se;
        q.pop();
        if(val > dist[u][2].fi)
            continue;
        REP(s , g[u].size())
        {
            int v = g[u][s];
                    //cerr << val << " " << u << " " << uu << " " << v << endl;
            if(dist[v][1].fi > val + 1 && v != uu)
            {
                dist[v][2] = dist[v][1];
                dist[v][1].se = uu;
                q.push(iii(dist[v][1].fi = val + 1 , ii(v , uu)));
            }
            else if(dist[v][2].fi > val + 1 && v != uu && dist[v][1].se != uu)
                q.push(iii(dist[v][2].fi = val + 1 , ii(v , uu)));
        }
    }
}

main()
{
    freopen("reinvent.inp","r",stdin);
    freopen("reinvent.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    FOR(i , 1 , m)
    {
        int u , v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    FOR(i , 1 , n)
        FOR(j , 1 , 2)
            dist[i][j].fi = 1e6;
    FOR(i , 1 , k)
    {
        cin >> a[i];
        q.push(iii(0 , ii(a[i] , a[i])));
    }
    dijk();
    int res = 1e6;
    FOR(i , 1 , k)
        res = min(res , dist[a[i]][1].fi);
    cout << res;
}
