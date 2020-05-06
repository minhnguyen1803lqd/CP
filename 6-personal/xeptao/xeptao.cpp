#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e4 + 10;
const int oo = 1e9 + 7;

#define setup freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);
#define StartCountTime clock_t t;   t = clock();
#define StopCountTime t = clock() - t;    cerr << ((float)t) / CLOCKS_PER_SEC << endl;

int tmp;
string s, s1, s2;
int f[N][N];
int n;
int m;

int LCS(string a, string b) {
    n = a.length();
    m = b.length();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    return (f[n][m]);
}

int main() {
    setup;
    StartCountTime;

    cin >> tmp;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (i % 2 != 0) {
            s1 += '1';
            s2 += '0';
        } else {
            s1 += '0';
            s2 += '1';
        }
    }
    int tmp1 = s.length() - LCS(s, s1);
    int tmp2 = s.length() - LCS(s, s2);
    cout << min(tmp1, tmp2) << endl;

    StopCountTime;
}
