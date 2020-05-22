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
    for (int i = 0; i < s.length() - 1;) {
        int id = i + 1;
        while (s[i] == s[id] and id < s.length()) id++;
        int tmp = (id - i);
        i = id;
    }
    return (0);
}