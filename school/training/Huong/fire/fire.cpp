#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define iii pair < int, ii >
#define ll long long
#define fi first
#define se second

const double inf = 1e9 + 7;
const int N = 1e3 + 10;

struct point {
	int x, y;
};

struct vecter {
	int a, b;
};

struct segment {
	point head, tail;
};

struct line {
	int a, b, c;
};

struct fraction	{
	int t, m;
};

struct crossPoint {
	fraction x, y;
};

int n, m, cnt = 0;
int node[N][N];
point cord[N];
double g[N][N];
double f[N][N];

vecter CreateVecter(point A, point B) {
	vecter res;
	res.a = A.y - B.y;
	res.b = B.x - A.x;
	return res;
}

line Line(point A, point B) {
	vecter u = CreateVecter(A, B);
	line res;
	res.a = u.a;
	res.b = u.b;
	res.c = (- u.a) * A.x + (- u.b) * A.y;
	return res;
}

bool Intersect(line d1, line d2) {
	int a1 = d1.a, b1 = d1.b, c1 = d1.c;
	int a2 = d2.a, b2 = d2.b, c2 = d2.c;
	if (a1 * b2 != a2 * b1) {
		return true;
	}
	else {
		return false;
	}
}

bool PointIdentical(point a, point b) {
	return (a.x == b.x && a.y == b.y);
}

int sqr(int x) {
    return (x * x);
}

int dis(point a, point b) {
    return (sqr(abs(a.x - b.x)) + sqr(abs(a.y - b.y)));
}

bool SegmentIntersect(segment AB, segment CD) {
	line d1 = Line(AB.head, AB.tail);
	line d2 = Line(CD.head, CD.tail);
	if (Intersect(d1, d2)) {
		point a = AB.head, b = AB.tail;
		point c = CD.head, d = CD.tail;
		int a1 = d1.a, b1 = d1.b, c1 = d1.c;
		int a2 = d2.a, b2 = d2.b, c2 = d2.c;
		if ((a2 * a.x + b2 * a.y + c2) * (a2 * b.x + b2 * b.y + c2) < 0) {
			if ((a1 * c.x + b1 * c.y + c1) * (a1 * d.x + b1 * d.y + c1) < 0) {
				return true;
			}
		}

		if (PointIdentical(a, c) || PointIdentical(a, d) || PointIdentical(b, c) || PointIdentical(b, d)) {
			return true;
		}

	}
	return false;
}

crossPoint FindCrossPoint(line d1, line d2) {
	int a1 = d1.a, b1 = d1.b, c1 = d1.c;
	int a2 = d2.a, b2 = d2.b, c2 = d2.c;
	
	crossPoint res;
	res.x.t = b1 * c2 - b2 * c1;
	res.x.m = a1 * b2 - a2 * b1;
	res.y.t = a2 * c1 - a1 * c2;
	res.y.m = a1 * b2 - a2 * b1;
	return res;
}

void deleteEdge(point a, point b) {
    int u = node[a.x][a.y];
    int v = node[b.x][b.y];
    g[u][v] = g[v][u] = 0;
}

void mergeEdge(point a, point b, double W) {
    int u = node[a.x][a.y];
    int v = node[b.x][b.y];
    g[u][v] = g[v][u] = W;
}

void Try(int x1, int x2, int x3, int x4) {
    point a = cord[x1];
    point b = cord[x2];
    point c = cord[x3];
    point d = cord[x4];
    
    if (PointIdentical(a, b) == false and PointIdentical(a, c) == false and PointIdentical(a, d) == false and PointIdentical(b, c) == false and PointIdentical(b, d) == false and PointIdentical(c, d) == false) {
        segment AC, BD;
        AC.head = a;
        AC.tail = c;
        BD.head = b;
        BD.tail = d;
        if (SegmentIntersect(AC, BD) and dis(a, c) == 8 and dis(b, d) == 8) {
            line d1 = Line(a, c);
            line d2 = Line(b, d);
            crossPoint gd = FindCrossPoint(d1, d2);
            fraction x = gd.x, y = gd.y;
            point newNode;
            newNode.x = x.t / x.m;
            newNode.y = y.t / y.m;
            if (node[newNode.x][newNode.y] == 0) {
                node[newNode.x][newNode.y] = ++cnt;
                cord[cnt] = newNode;
                int u1 = node[a.x][a.y];
                int v1 = node[c.x][c.y];
                int u2 = node[b.x][b.y];
                int v2 = node[d.x][d.y];
                mergeEdge(a, newNode, g[u1][v1] / 2);
                mergeEdge(newNode, c, g[u1][v1] / 2);
                mergeEdge(b, newNode, g[u2][v2] / 2);
                mergeEdge(newNode, d, g[u2][v2] / 2);
                deleteEdge(a, c);
                deleteEdge(b, d);
            }
        }
    }
}

int main() {
    fileInput("fire");
    fast;
    memset(node, 0, sizeof(node));
    cin >> m;
    n = 0;
    for (int i = 1; i <= m; i++) {
        point u, v;
        int w;
        cin >> u.x >> u.y >> v.x >> v.y >> w;
        u.x *= 2;
        u.y *= 2;
        v.x *= 2;
        v.y *= 2;
        if (node[u.x][u.y] == 0) {
            cord[++n] = u;
            node[u.x][u.y] = n;
        }
        if (node[v.x][v.y] == 0) {
            cord[++n] = v;
            node[v.x][v.y] = n;
        }
        g[node[u.x][u.y]][node[v.x][v.y]] = w;
        g[node[v.x][v.y]][node[u.x][u.y]] = w;
    }
    cnt = n;
    cout << n << " " << m << endl;
    for (int i = 1; i <= n; i++) {
        cout << cord[i].x << " " << cord[i].y << endl;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                for (int h = 1; h <= n; h++) {
                    Try(i, j, k, h);
                    Try(j, i, k, h);
                    Try(j, k, i, h);
                }
            }
        }
    }
    n = cnt;
    cout << n << " " << m << endl;
    for (int i = 1; i <= n; i++) {
        cout << cord[i].x << " " << cord[i].y << endl;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = inf;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j]) f[i][j] = g[i][j];
        }
    }

    for (int i = 1; i <= n; i++) f[i][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (f[i][j] > f[i][k] + f[k][j]) {
                    f[i][j] = f[i][k] + f[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }

    return (0);
}