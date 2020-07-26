#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e3 + 5e2 + 7;
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

ostream &operator<< (ostream &cout, point &pt) {
    cout << "point: (" << pt.x << ", " << pt.y << ") ";
    return (cout);
}

ll sqr(ll x) {
    return (x * x);
}

ll getDistance(point A, point B) {  //  this function is return sqr(the distance between point A and point B)
    return (sqr(A.x - B.x) + sqr(A.y - B.y));
}

int n, ans = 0;
vector < point > pts;

main() {
    fileInput("trianglesub2");
    cin >> n;
    pts.resize(n);
    for (int i = 0; i < n; i++) cin >> pts[i];
    //for (int i = 0; i < n; i++) cout << pts[i] << endl;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                ll AB = getDistance(pts[i], pts[j]);
                ll BC = getDistance(pts[j], pts[k]);
                ll AC = getDistance(pts[i], pts[k]);
                if (AB + BC == AC or AB + AC == BC or BC + AC == AB) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}