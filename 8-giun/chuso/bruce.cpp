#include <bits/stdc++.h>

#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, l, r) for (int i = l; i >= r; i--)
#define ii pair < int, int >
#define vi vector < int >
#define vii vector < ii >
#define fi first
#define se second
#define pb push_back
#define pp pop_back
#define fr front
#define mp make_pair
#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".ans").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);

const int inf = 1e9 + 7;

using namespace std;

string root, reve, ans;
int n, m;

int main() {
    fileInput("chuso");
    fast;

    cin >> root >> n >> m;
    n = (int)pow(2, n);
    reve = root;
    reverse(reve.begin(), reve.end());

    FOR(i, 1, n) {
        if (i % 2 == 0) {
            ans += reve;
        } else {
            ans += root;
        }
    }

    cout << ans[m - 1] << endl;

    return(0);
}
//  Problem's link:
//  Problem's solution:
//  GMCoder4811
//  Bà chủ vựa chanh with luv
