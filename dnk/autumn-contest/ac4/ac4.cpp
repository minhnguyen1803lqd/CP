#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long
#define si pair < string, int >
#define fi first
#define se second

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 0;

int query, n, m;
map < string, int > mp;
map < string, int >::iterator mp_i;
string const_val[] = {"Do", "Re", "Mi", "Fa", "Son", "La", "Si"};

main() {
    fileInput("ac4");
    for (int i = 0; i < 7; i++) {
        mp.insert(const_val[i], i);
    }
    cin >> query;
    while (query--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >>
        }
    }
}
