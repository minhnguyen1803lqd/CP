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

int n, d, s = 0;
int a[N];
int x[N];

void backTrack(int id) {
    if (id == n + 1) {
        int tmp = 0;
        for (int i = 1; i <= n; i++) {
            tmp += (x[i] * a[i]);
        }
        if (tmp == d) {
            for (int i = 1; i <= n; i++) {
                if (x[i]) cout << a[i] << " ";
            }
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
        s += a[i];
    }
    sort(a + 1, a + 1 + n);
    if (s < d) {
        cout << -1 << endl;
        return (0);
    }
    else if (s == d) {
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return (0);
    }
    else {
        backTrack(1);
    }
    cout << -1 << endl;

    return (0);
}
