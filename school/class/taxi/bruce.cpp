#include <bits/stdc++.h>

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".ans").c_str(), "w", stdout);

using namespace std;

const int N = (int)1e3;

int tc, p, t;
vector <int> g[N];
int flow[N][N], cap[N][N], dis[N], work[N], speed, limit;
pair <int, int> a[N], b[N];

bool bfs()
{
    memset(dis, 0, sizeof dis);
    dis[0] = 1;
    queue <int> q; q.push(0);

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        if(u == p + t + 1) return 1;
        for(int s = 0; s < g[u].size(); s++)
        {
            int v = g[u][s];
            if(!dis[v] && flow[u][v] < cap[u][v])
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return 0;
}

int dfs(int u, int mini)
{
    if(u == p + t + 1) return mini;

    for(int s = work[u]; s < g[u].size(); s++)
    {
        int v = g[u][s], f;
        if(dis[v] == dis[u] + 1)
        if(flow[u][v] < cap[u][v])
        if(f = dfs(v, min(mini, cap[u][v] - flow[u][v])))
        {
            flow[u][v] += f;
            flow[v][u] -= f;
            return f;
        }
    }
    return 0;
}

int main()
{
    fileInput("taxi");
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> tc;
    while(tc--)
    {
        memset(flow, 0, sizeof flow);
        memset(cap, 0, sizeof cap);

        cin >> p >> t >> speed >> limit;
    	for(int i = 0; i <= p + t + 1; i++) g[i].clear();
        for(int i = 1; i <= p; i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        for(int i = 1; i <= t; i++)
        {
            cin >> b[i].first >> b[i].second;
            for(int j = 1; j <= p; j++)
            {
                int dis = abs(a[j].first - b[i].first) + abs(a[j].second - b[i].second);
                int time = dis / speed;
                cerr << "dis: " << dis << endl;
                cerr << time << endl;
                if(dis <= limit)
                {
                    //cout << "\n:D" << j << ' ' << i + p << '\n';
                    g[j].push_back(i + p);
                    g[i + p].push_back(j);
                    cap[j][i + p] = 1;
                }
            }
        }

        for(int i = 1; i <= p; i++)
        {
                    g[0].push_back(i);
                    g[i].push_back(0);
                    cap[0][i] = 1;
        }
        for(int i = p + 1; i <= p + t; i++)
        {
                    g[i].push_back(t + p + 1);
                    g[t + p + 1].push_back(i);
                    cap[i][t + p + 1] = 1;
        }

        int ans = 0;
        //cout << cap[3][6];
        while(bfs())
        {
            //cout << "3\n";
            while(int flow = dfs(0, INT_MAX))
            {
                //cout << flow << '\n';
                ans += flow;
            }
        }
        cout << ans << '\n';
    }
}
