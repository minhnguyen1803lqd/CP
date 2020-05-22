#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;

int n, a, b;

int main() {
    fileInput("onum");
    fast;
    cin >> n >> a >> b;
    cout << (n - 2) * b - (n - 2) * a + 1 << endl;
    return (0);
}