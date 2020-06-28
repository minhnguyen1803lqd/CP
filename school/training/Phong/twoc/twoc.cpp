#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e4 + 7;

int n;
string s;
char a[N];

string Delete(int a, int b, string s) {
    string res = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != char(a) and s[i] != char(b)) {
            res += s[i];
        }
    }
    return (res);
}

bool Check(string s) {
    int cnt[N];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < s.length(); i++) {
        cnt[int(s[i])]++;
    }
    int count = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        if (cnt[i] != 0) count++;
    }
    return (count == 2);
}

int main() {
    fileInput("twoc");
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            if (i != j) {
                string res = Delete(i, j, s);
                if (Check(res)) {
                    cout << res.length() << endl;
                }
            }
        }
    }
    cout << ans << endl;
    return (0);
}