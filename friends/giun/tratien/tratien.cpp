#include <bits/stdc++.h>

#define ii pair < int, int >
#define vi vector < int >
#define vii vector < ii >
#define fi first
#define se second
#define pb push_back
#define pp pop_back
#define fr front
#define mp make_pair
#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);

const int inf = 1e9 + 7;
const int N = 1e6 + 7;

using namespace std;

int n, d, a[N], x[N];

void backTrack(int id) {
    if (id == n + 1) {
        int s = 0;
        for (int i = 1; i <= n; i++) {
            s += (x[i] * a[i]);
        }
        if (s == d) {
            for (int i = 1; i <= n; i++) {
                if (x[i]) {
                    cout << a[i] << " ";
                }
            }
            cout << endl;
            exit(0);
        }
    } else {
        for (int i = 0; i <= 1; i++) {
            x[id] = i;
            backTrack(id + 1);
        }
    }
}

int main() {
    fileInput("tratien");
    fast;

    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    backTrack(1);
    cout << -1 << endl;

    return(0);
}