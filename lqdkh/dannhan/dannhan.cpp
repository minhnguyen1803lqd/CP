#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 0;

int n;
vector < int > a, ans;

main() {
    fileInput("dannhan");
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    ans.push_back(a[0]);
    for (int i = 1; i < n; ++i) if (ans[ans.size() - 1] != a[i]) ans.push_back(a[i]);
    cout << a.size() - ans.size() << endl;
}