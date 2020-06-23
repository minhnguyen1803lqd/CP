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
const int N = 2e3 + 7;

string x, y;
int f[N][N];

string strReverse(string s) {
    string res = "";
    REP(i, s.length()) {
        res = s[i] + res;
    }
    return(res);
}

void backTrack(int i, int j) {
    if (x[i - 1] == y[j - 1]) {
        if (!(i - 1 >= 0 and j - 1 >= 0)) return;
        backTrack(i - 1, j - 1);
        cout << x[i - 1];
    } else {
        if (f[i - 1][j] == f[i][j]) {
            backTrack(i - 1, j);
        } else {
            backTrack(i, j - 1);
        }
    }
}

int main() {
    fileInput("nkpalin");
    fast;
    cin >> x;
    y = strReverse(x);
    
    FOR(i, 1, x.length()) {
        FOR(j, 1, y.length()) {
            if (x[i - 1] == y[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    //cout << f[x.length()][y.length()] << endl;
    backTrack(x.length(), x.length());
    
    return (0);
}