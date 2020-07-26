#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e4 + 7;

string s;
int cnt[N], x[N];
vector < vector < char > > ans;

void backTrack(int id) {
    if (id == s.length()) {
        vector < char > res;
        for (int i = 0; i < s.length(); i++) res.push_back(char(x[i]));
        ans.push_back(res);
    } else {
        for (int i = 'A'; i <= 'Z'; i++) {
            if (cnt[i]) {
                x[id] = i;
                cnt[i]--;
                backTrack(id + 1);
                cnt[i]++;
            }
        }
    }
}

main() {
    fileInput("qbhv");
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        cnt[int(s[i])]++;
    }
    backTrack(0);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        vector < char > res = ans[i];
        for (int j = 0; j < res.size(); j++) {
            cout << res[j];
        }
        cout << "\n";
    }
}