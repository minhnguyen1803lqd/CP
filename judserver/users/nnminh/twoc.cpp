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

string deleteStr(string s, char a, char b) {
    string res = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == a or s[i] == b) res += s[i];
    }
    return (res);
}

bool check(string s) {
    int cnt[N];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < s.length(); i++) cnt[int(s[i])]++;
    int count = 0;
    for (int i = 'a'; i <= 'z'; i++) if (cnt[i]) count++;
    if (count != 2) return (false);
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1]) return (false);
    }
    return (true);
}

int main() {
    fileInput("twoc");
    fast;
    cin >> n >> s;
    int ans = 0;
    for (int i = 'a'; i <= 'y'; i++) {
        for (int j = i + 1; j <= 'z'; j++) {
            string tmp = deleteStr(s, char(i), char(j));
            if (check(tmp)) {
                int res = tmp.length();
                ans = max(ans, res);
            }
        }
    }
    cout << ans << endl;
    return (0);
}