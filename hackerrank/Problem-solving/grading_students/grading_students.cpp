#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pp pop_back

const int inf = 1e9 + 7;
const int esf = 1e-9;

int main() {
    fileInput("grading_students");
    fast;
    int n;
    cin >> n;
    FOR(i, 1, n) {
        int x, tmp;
        cin >> x;
        if (x < 38) {
            cout << x << endl;
        } else {
            tmp = 0;
            while (tmp < x) tmp += 5;
            if (tmp - x < 3) x = tmp;
            cout << x << endl;
        }
    }    

    return (0);
}