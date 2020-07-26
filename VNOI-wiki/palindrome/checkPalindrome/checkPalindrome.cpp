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

bool isPalindrome(string s) {
    int n = s.length() - 1;
    FOR(i, 0, n) {
        if (s[i] != s[n - i]) return (false);
    }
    return (true);
}

int main() {
    fileInput("checkPalindrome");
    fast;
    cin >> s;
    if (isPalindrome(s)) cout << "YES\n";
    else cout << "NO\n";
    return (0);
}