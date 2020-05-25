#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef pair <int,int> ii;
vector <ii> a[1001];
int f[1001][1001];
int n,s,t;
int level[1001];
bool bfs(int s, int t)
{
    memset(level,0,sizeof(level));
    queue <int> q;
    q.push(s);
    level[s]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=0;i<a[u].size();i++)
        {
            int v=a[u][i].fi;
            if(level[v]==0 and f[u][v]<a[u][i].se)
            {
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
    return level[t];
}
int dfs(int s, int t, int flow)
{
	//cout<<s<<endl;
    if(s==t) return flow;
    for(int i=0;i<a[s].size();i++)
    {
        int v=a[s][i].fi;
        if(level[v]==level[s]+1 and f[s][v] < a[s][i].se)
        {
            int currf=min(flow,a[s][i].se - f[s][v]);
            int tmpf=dfs(v,t,currf);
            if(tmpf>0)
            {
                f[s][v]+=tmpf;
                f[v][s]-=tmpf;
                return tmpf;
            }
        }
    }
    return 0;
}
int main()
{
    //freopen("maxflow.inp","r",stdin);
    int m;
    cin>>n>>m>>s>>t;
    //cout<<n<<" "<<m<<" "<<s<<" "<<t<<endl;
    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        a[u].push_back(mp(v,c));
        a[v].push_back(mp(u,0));
    }
 
    int ans=0;
    while(bfs(s,t))
    {
        while(int incf=dfs(s,t,999999999)) ans+=incf;
    }
    cout<<ans;
    return 0;
}