#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e4 + 7;

ll a;
int n;
int x[N], ans = 0;

int getLength(ll x) {
    int res = 0;
    while (x) {
        res += 1;
        x /= 10;
    }
    return (res);
}

bool check(int x[N], int _x, int _y) {
    int cnt = 0;
    int flag1 = 1;
    int flag2 = 1;
    for (int i = 1; i <= n; i++) {
        if (x[i] == _x and flag1) cnt++, flag1 = 0;
        if (x[i] == _y and flag2) cnt++, flag2 = 0;
    }
    return (cnt == 2);
}

void backTrack(int id, int _x, int _y) {
    if (id == n + 1) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res = res * 10 + x[i];
        }
        if (check(x, _x, _y) and res <= a) {
            cout << res << endl;
            ans++;
        }
    } else {
        for (int i = 0; i <= n; i++) {
            x[id] = i;
            backTrack(id + 1, _x, _y);
        }
    }
}

int main() {
    fileInput("ulnumber");
    fast;
    cin >> a;
    n = getLength(a);
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (i != j) {
                backTrack(1, i, j);
            }
        }
    }
    cout << ans << endl;
    return (0);
}