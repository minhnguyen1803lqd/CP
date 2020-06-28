#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define SET(x, val) memset(x, val, sizeof(x))
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pp pop_back

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e4 + 7;
const int esp = 1e-9;

struct point {
    int x, y;
};

int n;
point a[N], b[N];
point p[N]; //  array contain convexhull

istream &operator>> (istream &cin, point &pt) {
    int _x, _y;
    cin >> _x >> _y;
    pt.x = _x;
    pt.y = _y;
    return (cin);
}

ostream &operator<< (ostream &cout, point &pt) {
    cout << pt.x << " " << pt.y;
}

int ccw(point a, point b, point c) {
    int a1, b1, a2, b2, t;
    a1 = b.x - a.x;
    b1 = b.y - a.y;
    a2 = c.x - b.x;
    b2 = c.y - b.y;
    t = a1 * b2 - a2 * b1;
    if (abs(t) < esp) return (0);
    else if (t < 0) return (-1);
    return (1);
}

bool cmp(point x, point y) {
    return (ccw(a[1], x, y) > 0);
}

void Swap(point &a, point &b) {
    point tmp;
    tmp.x = a.x;
    tmp.y = a.y;
    a.x = b.x;
    a.y = b.y;
    b.x = tmp.x;
    b.y = tmp.y;
}

double area(point p[N], int n) {
    double res = 0;
    p[n + 1] = p[1];
    REV(i, n, 1) {
        int j = i + 1;
        res += (p[i].x - p[j].x) * (p[i].y + p[j].y);
    }
    res = abs(res);
    return (res / 2);
}

void graham() {
    FOR(i, 1, n) {
        b[i] = a[i];
    }
    int id = 1;
    FOR(i, 2, n) {
        if ((a[i].y < a[id].y) or (a[i].y == a[id].y and a[i].x < a[id].y)) {
            id = i;
        }
    }
    Swap(a[id], a[1]);
    sort(a + 2, a + 1 + n, cmp);
    int k = 2;
    p[1] = a[1];
    p[2] = a[2];
    FOR(i, 3, n) {
        if (ccw(a[k - 1], a[k], a[i]) == 1) {
            p[++k] = a[i];
        } else {
            do {
                --k;
            } while (ccw(a[k - 1], a[k], a[i]) < 0);
            p[++k] = a[i];
        }
    }
    FOR(i, 1, k) {
        cout << p[i] << endl;
    }
    cout << "area: " << area(p, k) << endl;
}

int main() {
    fileInput("convexhull");
    fast;
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i];
    }
    graham();
    return (0);
}