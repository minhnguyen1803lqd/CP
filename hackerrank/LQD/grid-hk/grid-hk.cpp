//TODO: reCode this problem
// #include <bits/stdc++.h>

// #define fi first
// #define se second
// #define ii pair < int, int >
// #define vi vector < int >
// #define vii vector < ii >
// #define fast ios::sync_with_stdio(0);cin.tie(0);

// using namespace std;

// const int N = 1e3 + 10;
// const int oo = 1e9 + 7;

// const int dx[] = {0, 0, -1, 1};
// const int dy[] = {-1, 1, 0 ,0};

// int n;
// int color[N][N], steps[N][N];
// ii previous[N][N];
// ii s, e;

// bool Equal(ii a, ii b) {
// 	return (a.fi == b.fi && a.se == b.se);
// }

// bool Inside(int x, int y, int n, int m) {
// 	return (0 <= x && x < n && 0 <= y && y < m);
// }

// deque < ii > GetPath() {
// 	deque < ii > dq;
// 	ii tmp = e;
// 	while (true) {
// 		if (previous[tmp.fi][tmp.se].fi == -1 && previous[tmp.fi][tmp.se].se == -1) {
// 			dq.push_front(tmp);
// 			break;
// 		} else {
// 			dq.push_front(tmp);
// 			tmp = previous[tmp.fi][tmp.se];
// 		}
// 	}
// 	return (dq);
// }

// bool BFS(ii StartNode, ii EndNode) {
// 	queue < ii > q;
// 	q.push(StartNode);
// 	color[StartNode.fi][StartNode.se] = 1;
// 	steps[StartNode.fi][StartNode.se] = 1;
// 	previous[StartNode.fi][StartNode.se] = make_pair(-1, -1);

// 	while (q.empty() == false) {
// 		ii CurNode = q.front();
// 		q.pop();
// 		if (Equal(CurNode, EndNode)) {
// 			return true;
// 		} else {
// 			for (int i = 0; i < 4; i++) {
// 				int x = CurNode.fi + dx[i];
// 				int y = CurNode.se + dy[i];
// 				if (color[x][y] == 0 && Inside(x, y, n, n)) {
// 					q.push(make_pair(x, y));
// 					color[x][y] = 1;
// 					steps[x][y] = steps[CurNode.fi][CurNode.se] + 1;
// 					previous[x][y] = CurNode;
// 				}
// 			}
// 		}
// 	}
// 	return false;
// }

// int Move(ii Prev, ii Cur) {
// 	ii x = Prev, y = Cur;
// 	if (x.se == y.se) {
// 		if (x.fi < y.fi) {
// 			return (2);	//	Down;
// 		} else if (x.fi > y.fi) {
// 			return (1);	//	Up;
// 		}
// 	} else if (x.fi == y.fi) {
// 		if (x.se > y.se) {
// 			return (3);	//	Left;
// 		} else if (x.se < y.se) {
// 			return (4);	//	Rigth;
// 		}
// 	}
// 	return 0;
// }

// void Show(deque < ii > x) {
// 	while (x.size() != 0) {
// 		cout << x.front().fi << " " << x.front().se << ";\n";
// 		x.pop_front();
// 	}
// 	return;

// }

// void Connect() {
// 	deque < ii > path = GetPath();
// 	//Show(path);

// 	int cnt = 1;
// 	ii previous = path.front();
// 	path.pop_front();
// 	int PrevMove = Move(previous, path.front());
// 	previous = path.front();
// 	path.pop_front();
// 	while (path.size() != 0) {
// 		int CurMove = Move(previous, path.front());
// 		if (CurMove != PrevMove) cnt++;
// 		PrevMove = CurMove;
// 		previous = path.front();
// 		path.pop_front();
// 	}
// 	cout << cnt << endl;
// }

// int main()
// {
// 	fast;
// 	freopen ("grid-hk.inp", "r", stdin);
// 	freopen ("grid-hk.out", "w", stdout);
// 	cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			char tmp;
// 			cin >> tmp;
// 			if (tmp == '.') {
// 				color[i][j] = 0;
// 			} else {
// 				color[i][j] = 1;
// 			}
// 		}
// 	}
// 	cin >> s.fi >> s.se >> e.fi >> e.se;
// 	if (Equal(s, e)) {
// 		cout << 0 << endl;
// 		return 0;
// 	}
// 	if (!BFS(s, e)) {
// 		return 0;
// 	} else {
// 		Connect();
// 	}
// }
// #include<bits/stdc++.h>
// using namespace std;

// #define y1 as214
// #define ii pair < int , int >
// #define iii pair < int , ii >
// #define iv pair < ii , ii >

// #define fi first
// #define se second
// #define fr front()
// #define pb push_back
// #define t top()

// #define FOR(i , x , n) for(ll i = x ; i <= n ; ++i)
// #define REP(i , n) for(ll i = 0 ; i < n ; ++i)
// #define FORD(i , x , n) for(ll i = x ; i >= n ; --i)

// #define ll long long
// #define oo 1e17
// #define eps 1e-8
// #define div divv
// #define pow poww
// #define int long long

// const int N = 1e2 + 5;
// ii s , e;
// int n;
// int dist[N][N];
// ii pos[N][N][5];
// char f[N][N];
// queue < ii > q;
// int dx[] = {1 , 0 , -1 , 0} , dy[] = {0 , 1 , 0 , -1};

// bool ok(int u , int v)
// {
//     return u > 0 && u <= n && v > 0 && v <= n;
// }

// /// luoi cai n ^ 2 qua , n ^ 4 cx AC ma.(mong la vay)

// void BFS()
// {
//     q.push(ii(s.fi , s.se));
//     memset(dist , -1 , sizeof(dist));
//     dist[s.fi][s.se] = 0;
//     while(!q.empty())
//     {
//         int x = q.fr.fi;
//         int y = q.fr.se;
//         if(x == e.fi && y == e.se)
//         {
//             cout << dist[x][y];
//             exit(0);
//         }
//         q.pop();
//         REP(s , 4)
//         {
//             int u = pos[x][y][s].fi;
//             int v = pos[x][y][s].se;
//             FOR(i , min(x , u) , max(x , u))
//                 FOR(j , min(y , v) , max(y , v))
//                 {
//                     if(dist[i][j] == -1)
//                     {
//                         dist[i][j] = dist[x][y] + 1;
//                         q.push(ii(i , j));
//                     }
//                 }
//         }
//     }
//     cout << "-1";
// }

// int32_t main()
// {
//     //freopen("test1.inp","r",stdin);
//     cin >> n;
//     FOR(i , 1 , n)
//         FOR(j , 1 , n)
//             cin >> f[i][j];
//     cin >> s.fi >> s.se >> e.fi >> e.se;
//     s.fi++;
//     s.se++;
//     e.fi++;
//     e.se++;
//     FOR(i , 1 , n)
//         FOR(j , 1 , n)
//         {
//             REP(s , 4)
//             {
//                 int x = i;
//                 int y = j;
//                 while(true)
//                 {
//                     int u = x + dx[s];
//                     int v = y + dy[s];
//                     if(!ok(u , v) || f[u][v] == 'X')
//                     {
//                         pos[i][j][s] = ii(x , y);
//                         break;
//                     }
//                     x = u;
//                     y = v;
//                 }
//             }
//         }
//     BFS();
// }