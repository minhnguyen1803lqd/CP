#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e5 + 10;
const int oo = 1e9 + 7;

#define setup freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);
#define StartCountTime clock_t t;   t = clock();
#define StopCountTime t = clock() - t;    cerr << ((float)t) / CLOCKS_PER_SEC << endl;
#define ii pair < int, int >
#define fi first
#define se second

int n, ans = -oo;
ii a[N];

bool cmp(ii a, ii b) {
    return ((a.fi < b.fi) || (a.fi == b.fi && a.se < b.se));
}

int main() {
    setup;
    StartCountTime;
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    int l = oo, r = -oo;
    for (int i = 1; i <= n; i++) {
        if (a[i].fi == a[1].fi) {
            l = min(l, a[i].se);
        }   
        if (a[i].fi == a[n].fi) {
            r = max(r, a[i].se);
        }
    }
    ans = max(ans, r - l);
    l = -oo, r = oo;
    for (int i = 1; i <= n; i++) {
        if (a[i].fi == a[1].fi) {
            l = max(l, a[i].se);
        }   
        if (a[i].fi == a[n].fi) {
            r = min(r, a[i].se);
        }
    }
    ans = max(ans, l - r);
    cout << ans << endl;

    StopCountTime;
}
