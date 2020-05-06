/*

 */
#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e5 + 10;
const int inf = 1e9 + 7;

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);
#define fi first
#define se second

int a[4], b[4];
pair < int, int > ans;

main() {
    FileOpen;
    cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
    ans = pair < int, int > (0, 0);
    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) ans.fi++;
        else if (a[i] < b[i]) ans.se++;
    }
    cout << ans.fi << " " << ans.se << endl;

}
