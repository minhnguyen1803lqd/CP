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
const int N = 1e6 + 10;

using namespace std;

int n, a[N];

int main() {
    fileInput("counting-valleys");
    fast;

    cin >> n;
    FOR(i, 1, n) {
        char tmp;
        cin >> tmp;
        if (tmp == 'D') a[i] = -1;
        else a[i] = 1;
    }

    int currHeight = 0;
    int ans = 0;

    FOR(i, 1, n) {
        currHeight += a[i];
        if (currHeight == 0) ans++;
        cerr << currHeight << " ";
    }
    cout << ans / 2 << endl;

    return(0);
}
//  Problem's link:
//  Problem's solution:
//  GMCoder4811
//  Bà chủ vựa chanh with luv
