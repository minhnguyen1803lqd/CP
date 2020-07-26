#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 3e3 + 7;
const ll M = 1e6 + 7;

struct point {
    int x, y;
};

istream &operator>> (istream &cin, point &pt) {
    cin >> pt.x >> pt.y;
    pt.x += 1000;
    pt.y += 1000;
    return (cin);
}

ostream &operator<< (ostream &cout, point pt) {
    cout << "point: (" << pt.x << ", " << pt.y << ") ";
}

int n;
vector < point > pts;
int fx[M], fy[M], ans = 0;

main() {
    fileInput("trianglesub1");
    cin >> n;
    pts.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i];
        fx[pts[i].x]++;
        fy[pts[i].y]++;
    }
    for (int i = 0; i < n; i++) {
        ans += (fx[pts[i].x] - 1) * (fy[pts[i].y] - 1);
    }
    cout << ans << endl;
}