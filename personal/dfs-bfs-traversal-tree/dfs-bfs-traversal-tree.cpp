#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e4 + 10;
const int oo = 1e9 + 7;

#define setup freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);
#define StartCountTime clock_t t;   t = clock();
#define StopCountTime t = clock() - t;    cerr << ((float)t) / CLOCKS_PER_SEC << endl;

struct node {
    vector < int > adj;
    int color;
    int level;
    int parent;
};

int n, m;
node g[N];
int DFSstep;
int BFSstep;

void DFS(int u, int &step) {
    step++;
    cout << u << " " << g[u].level << " " << g[u].parent << " " << step << endl;
    g[u].color = 1;
    for (int i = 0; i < g[u].adj.size(); i++) {
        int v = g[u].adj[i];
        if (!g[v].color) {
            g[v].level = g[u].level + 1;
            g[v].parent = u;
            DFS(v, step);
        }
    }
}

void BFS(int s, int &step) {
    queue < int > q;
    q.push(s);
    g[s].color = 1;
    g[s].level = 0;
    g[s].parent = 0;

    while (q.empty() == false) {
        int u = q.front();
        step++;
        cout << u << " " << g[u].level << " " << g[u].parent << " " << step << endl;
        q.pop();
        for (int i = 0; i < g[u].adj.size(); i++) {
            int v = g[u].adj[i];
            if (!g[v].color) {
                g[v].color = 1;
                g[v].level = g[u].level + 1;
                g[v].parent = u;
                q.push(v);
            }
        }
    }
}

int main() {
    setup;
    StartCountTime;
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].adj.push_back(v);
        g[v].adj.push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        g[i].color = 0;
        g[i].parent = i;
        g[i].level = 0;
    }
    DFSstep = 0;
    DFS(1, DFSstep);
    cout << endl;
    for (int i = 1; i <= n; i++) {
        g[i].color = 0;
        g[i].parent = i;
        g[i].level = 0;
    }
    BFSstep = 0;
    BFS(1, BFSstep);

    StopCountTime;
}
