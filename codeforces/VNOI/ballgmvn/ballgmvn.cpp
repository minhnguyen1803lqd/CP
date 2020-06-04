#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = 1e3 + 7;

struct point {
    int x, y, id;
    void show() {
        cout << "point: (" << x << "; " << y << ")\n";
    }
};

bool operator < (const point &a, const point& b) {
    return tie(a.x, a.y) < tie(b.x, b.y);
}
bool operator == (const point &a, const point& b) {
    return a.x==b.x && a.y==b.y;
}

int n;
point a[N], b[N];

int GCD(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    int r;
    while (b > 0) r=a%b, a=b, b=r;
    return a;
}

void formalize(point &a) {
    if (a.y == 0) a.x = 1;
    else if (a.x == 0) a.y = 1;
    else {
        if (a.y < 0) a.y = -a.y, a.x = -a.x;
        int g = GCD(a.x, a.y);
        a.x /= g;
        a.y /= g;
    }
}

bool Try(point x, point a[N]) {
    point c[N];
    for (int i = 1; i <= n; i++) {
        c[i].x = a[i].x - x.x;
        c[i].y = a[i].y - x.y;
        c[i].id = a[i].id;
        formalize(c[i]);
    }

    sort(c + 1, c + 1 + n);
    for (int i = 2; i <= n; i++) {
        if (c[i] == c[i - 1]) {
            cout << c[i].id << " " << c[i - 1].id << " " << x.id << endl;
            return (true);
        }
    }
    return (false);
}

int main() {
    fileInput("ballgmvn");
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i].x >> b[i].y;
        b[i].id = i + n;
    }

    for (int i = 1; i <= n; i++) {
        if (Try(a[i], b)) return (0);
    }
    for (int i = 1; i <= n; i++) {
        if (Try(b[i], a)) return (0);
    }
    cout << -1 << endl;

    return (0);
}