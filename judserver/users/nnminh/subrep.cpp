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

string s1, s2;
int ans = 0;

int main() {
    fileInput("subrep");
    fast;
    cin >> s1 >> s2;
    int id = 0;
    for (int i = 0; i < s2.length(); i++) {
        if (s2[i] == s1[id]) {
            ans++;
            id++;
            if (id == s1.length()) id = 0;
        }
    }
    cout << ans / s1.length() << endl;
    return (0);
}