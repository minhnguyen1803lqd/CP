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

using namespace std;

string root, reve;
int n, m, pos, digit, len;

int main() {
    fileInput("chuso");
    fast;

    cin >> root >> n >> m;
    reve = root;
    reverse(reve.begin(), reve.end());

    len = (int)pow(2, n) * root.length();
    if (m > len) cout << -1 << endl;
    else {
        pos = m / root.length() + (m % root.length() != 0);
        digit = m % root.length();
        if (pos % 2 == 0) {
            if (digit % root.length() == 0) cout << reve[reve.length() - 1] << endl;
            else cout << reve[digit - 1] << endl;
        } else {
            if (digit % root.length() == 0) cout << root[root.length() - 1] << endl;
            else cout << root[digit - 1] << endl;
        }
    }

    return(0);
}
//  Problem's link:
//  Problem's solution:
//  GMCoder4811
//  Bà chủ vựa chanh with luv
//  2^5 = 33,554,432
/*
                            
    a[n] = |123|321|123|321|123|321|123|321|
    m = 12
    13/3 = 4, 13%3 = 1 => digit = 5->0
    14/3 = 4, 14%3 = 2 => digit = 5->1
    15/3 = 5, 15%3 = 0 => digit = 5->2

*/