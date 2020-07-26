#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 3e3 + 7;

string s1, s2, ans = "";
int n, m;
int f[N][N];

void modString(string &s) {
    s = '*' + s;
    return;
}

main() {
    fileInput("lcs");
    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();
    modString(s1);
    modString(s2);
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i] == s2[j]) f[i][j] = f[i - 1][j - 1] + 1;
            else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    }
    int i = n, j = m;
    while (i >= 1 and j >= 1) {
        if (s1[i] == s2[j]) ans = s1[i] + ans, i--, j--;
        else {
            if (f[i - 1][j] > f[i][j - 1]) i--;
            else j--;
        }
    }
    cout << ans << endl;
}