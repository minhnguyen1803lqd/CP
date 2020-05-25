#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;

string s;

int main() {
    fileInput("srstring");
    fast;
    cin >> s;
    while (true) {
        int flag = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i + 1]) {
                s.erase(i, 2);
                flag = 1;
                break;
            }
        }
        if (s.length() == 0) break;
        if (flag == 0) break;
    }
    if (s.length() == 0) {
        cout << "Empty String\n";
    } else {
        cout << s << endl;
    }
    return (0);
}