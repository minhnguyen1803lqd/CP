#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;

ll n, a, b;

int main() {
    fileInput("onum");
    fast;
    scanf("%lld%lld%lld", &n, &a, &b);
    if (a > b) {
        cout << 0 << endl;
        exit(0);
    }
    ll ans = (n - 2) * b - (n - 2) * a + 1; 
    printf("%lld", ans);
    return (0);
}