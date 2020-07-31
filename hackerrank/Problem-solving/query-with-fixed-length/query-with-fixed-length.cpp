#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long
#define ii pair < int, int >
#define fi first
#define se second

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 0;

int query, n;
vector < int > a;
deque < ii > dq;

main() {
    fileInput("query-with-fixed-length");
    cin >> n >> query;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    while (query--) {
        int d = -inf;
        cin >> d;
        
    }
}