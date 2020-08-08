#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 7;

int n, m;
vector < int > a, b;
int ok1[N], ok2[N];

int Find(int L, int R, int val) {
    int res = -1;
    int l = L, r = R;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] < val) 
    }
    return (res);
}

main() {
    fileInput("dance");
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    for (int i = 0; i < n; ++i) cin >> a[i], ok1[i] = 0;
    for (int i = 0; i < m; ++i) cin >> b[i], ok2[i] = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 1; i <= n; ++i) {
        int id = Find(1, m, a[i]);
        cout << a[i] << " " << b[id] << endl;
    }
}