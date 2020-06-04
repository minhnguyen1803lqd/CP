#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".ans").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = 1e4 + 7;

ll n, ans = inf;
int x[N], a[N];
int res[N];

void make() {
    for (int i = 0; i <= 37; i++) {
        a[i] = int(pow(3, i));
    }
    return;
}

void update(int s, int x[N]) {
    if (ans > s) {
        ans = s;
        for (int i = 0; i <= 16; i++) {
            res[i] = x[i];
        }
        return;
    } else {
        return;
    }
}

bool check(int s) {
    for (int i = 1; i <= 37; i++) {
        if (s == a[i]) {
            return (true);
        }
    }
    return (false);
}

void backTrack(int id) {
    if (id == 17) {
        int tmp = 0;
        for (int i = 0; i <= 16; i++) {
            tmp += x[i] * a[i];
        }
        if (check(tmp + n)) {
            update(tmp + n, x);
        }
    } else {
        for (int i = 0; i <= 1; i++) {
            x[id] = i;
            backTrack(id + 1);
        }
    }
}

int main() {
    fileInput("can3");
    fast;
    make();
    cin >> n;
    backTrack(0);
    int cnt = 0;
    for (int i = 0; i <= 16; i++) {
        if (res[i]) cnt++;
    }
    cout << cnt << " ";
    for (int i = 0; i <= 16; i++) {
        if (res[i]) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
    cout << 1 << " " << ans << endl;
    return(0);
}