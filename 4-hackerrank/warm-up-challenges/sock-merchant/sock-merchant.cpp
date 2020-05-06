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
#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);

const int inf = 1e9 + 7;
const int N = 1e3 + 10;

using namespace std;

int n, cnt[N], ans = 0;

int main() {
    fileInput("sock-merchant");
    fast;

    cin >> n;
    FOR(i, 1, n) {
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
    }
    FOR(i, 1, 100) {
        ans += (cnt[i] / 2);
    }
    cout << ans << endl;

    return(0);
}
//  Problem's link:
//  Problem's solution:
//  GMCoder4811
//  Bà chủ vựa chanh with luv
