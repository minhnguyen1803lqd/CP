#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define SET(x, val) memset(x, val, sizeof(x))
#define vi vector < int >
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

string s;
bool f[N][N];
int ans = -inf;

int lcp(string s) {
    SET(f, false);  
    FOR(i, 1, s.length()) f[i][i] = true;
    FOR(i, 1, s.length()) {
        FOR(j, 1, s.length()) {
            if (i <= j) {
                f[i][j] = (f[i + 1][j - 1] and (s[i - 1] == s[j - 1]));
            }
        }
    }
    FOR(i, 1, s.length()) {
        FOR(j, 1, s.length()) {
            if (i <= j and f[i][j] == true) ans = max(ans, j - i + 1);
        }
    }
    return (ans);
}

int linear(string s) {
    
}

int main() {
    fileInput("longest-continue-palindrome");
    fast;
    cin >> s;
    int res = linear(s);
    cout << res << endl;
    return (0);
}