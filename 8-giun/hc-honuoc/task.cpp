#include <bits/stdc++.h>

#define ii pair < int, int >
#define vii vector < ii >
#define fi first
#define se second

using namespace std;

const int N = 1e6 + 7;

int n, t;
vii type1, type2;
int type1Day[N], type2Day[N], day[N];

int main() {
    freopen("task.inp", "r", stdin);
    freopen("task.out", "w", stdout);
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        if (x >= y * t) type1.push_back(ii(x, y));
        else type2.push_back(ii(x, y));
    }
    int a = 0, b = 0;
    for (int i = 0; i < type1.size(); i++) {
        a += type1[i].fi;
        b += type1[i].se;
    }
    type1Day[0] = a;
    for (int i = 1; i <= t; i++) {
        type1Day[i] = type1Day[i - 1] - b;
    }
    a = 0, b = 0;
    for (int i = 0; i < type2.size(); i++) {
        a += type2[i].fi;
        b += type2[i].se;
    }
    int cnt = 0;
    type2Day[cnt] = a;
    while (true) {
        if (a - b > 0) {
            cnt++;
            type2Day[cnt] = a - b;
            a -= b;
        } else {
            break;
        }
    }
    type2Day[cnt + 1] = 0;
    for (int i = 0; i < type2.size(); i++) {
        int tmp = (type2[i].fi = type2[i].fi - type2[i].se * (cnt + 1));
        if (tmp >= 0) type2Day[cnt + 1] += tmp;
    }
    for (int i = 0; i <= cnt + 1; i++) {
        day[i] = type1Day[i] + type2Day[i];
    }
    for (int i = cnt + 2; i <= t; i++) {
        day[i] = type1Day[i];
    }
    for (int i = 0; i <= t; i++) {
        cout << day[i] << endl;
    }
}