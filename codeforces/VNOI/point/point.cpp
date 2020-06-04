//  TODO: not accepted
#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = 1e4 + 7;

struct point {
    int x, y;
    void show() {
        cout << "point: (" << x << "; " << y << ")\n";
    }
};

int n, query;
vector<point> a;

bool cmp(point a, point b) {

}

int main() {
    fileInput("point");
    fast;
    cin >> query;
    for (int qq = 1; qq <= query; qq++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].x >> a[i].y;
        }
    }

    sort(a + 1, a + 1 + n, cmp);

    return (0);
}