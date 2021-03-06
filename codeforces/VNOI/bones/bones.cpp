#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define SET(x, val) memset(x, val, sizeof(x))
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pp pop_back

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e4 + 7;

int n1, n2, n3;
int cnt[N];

int main() {
    fileInput("bones");
    fast;
    cin >> n1 >> n2 >> n3;
    FOR(i, 1, n1) {
        FOR(j, 1, n2) {
            FOR(k, 1, n3) {
                cnt[i + j + k]++;
            }
        }
    }
    int id = 0;
    cnt[0] = 0;
    FOR(i, 3, n1 + n2 + n3) {
        if (cnt[id] < cnt[i]) {
            id = i;
        }
    }
    cout << id << endl;
    return (0);
}