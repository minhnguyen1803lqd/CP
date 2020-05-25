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

int n, k, ans = 0;
int x[N], cnt[N];

int counter(int x[N]) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (x[i] > x[j] and i < j) {
                cnt++;
            }
        }
    }
    return (cnt);
}

void backTrack(int id) {
    if (id == n + 1) {
        int tmp = counter(x);
        if (tmp == k) {
            ans++;
            for (int i = 1; i <= n; i++) {
                cerr << x[i] << " ";
            }
            cerr << endl;
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (cnt[i]) {
                x[id] = i;
                cnt[i]--;
                backTrack(id + 1);
                cnt[i]++;
            }
        }
    }
}

int main() {
    fileInput("order");
    fast;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) cnt[i]++;
    backTrack(1);
    cout << ans << endl;

    return(0);
}