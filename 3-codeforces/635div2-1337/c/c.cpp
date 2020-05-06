#include <bits/stdc++.h>#define range(i, l, r) for (int i = l; i <= r; i++)#define loop(i, time) for (int i = 0; i < time; i++)#define rev(i, l, r) for (int i = r; i >= l; i--)#define ii pair < int, int >#define iii pair < ii, int >#define iiii pair < ii, ii >#define vi vector < int >#define vii vector < ii >#define viii vector < iii >#define viiii vector < iiii >#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);const int inf = 1e9 + 7;const int N = 2e5 + 7;using namespace std;int n, k, ans = 0;vi g[N];int color[N], depth[N];vi branch;int slot = 0;int amount[N];bool cmp(int a, int b) {	return (a > b);}void DFS(int u) {	color[u] = 1;	int flag = 0;	loop(i, g[u].size()) {		int v = g[u][i];		if (!color[v]) {			depth[v] = depth[u] + 1;			flag = 1;			DFS(v);		}	}	if (!flag) {		branch.push_back(depth[u] + 1);	}}int main() {    fileInput("c");    cin >> n >> k;    loop(i, n - 1) {    	int u, v;    	cin >> u >> v;    	g[u].push_back(v);    	g[v].push_back(u);    }    memset(color, 0, sizeof(color));    memset(depth, 0, sizeof(depth));    DFS(1);    sort(branch.begin(), branch.end(), cmp);        for (int i = 1; i <= k; i++) {    	if (branch[slot] - amount[slot] > 1) {    		amount[slot] += 1;    		slot++;    	}    	if (slot == branch.size()) slot = 0;    }   	loop(i, branch.size()) {   		ans += (branch[i] - amount[i]) * amount[i];   	}   	cout << ans << endl;    return(0);}//  Problem's link://  Problem's solution://  GMCoder4811//  Bà chủ vựa chanh with luv