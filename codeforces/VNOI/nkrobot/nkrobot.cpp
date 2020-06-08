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
const int N = 15;
 
vector < int > a[N];
int target[N];
int x[N];
string query;
int ans[N];
bool haveAnswer = false;

bool check(int x[N]) {
    int s[N];
    FOR(i, 1, 9) {
        FOR(j, 1, x[i]) {
            REP(k, a[i].size()) {
                
            }
        }
    }
}

void backTrack(int id) {
    if (id == 10) {
        FOR(i, 1, 9) {
            cout << x[i];
        }
        cout << endl;
    } else {
        REP(i, 3) {
            x[id] = i;
            backTrack(id + 1);
        }
    }
}

int main() {
    fileInput("nkrobot");
    fast;
    FOR(i, 1, 9) {
        string tmp;
        cin >> tmp;
        REP(j, tmp.length()) {
            a[i].pb(int(tmp[j]) - int('0'));
        }
    }
    cin >> query;
    REP(i, query.length()) {
        if (query[i] == 'X') target[i + 1] = 2;
        if (query[i] == 'V') target[i + 1] = 1;
        if (query[i] == 'T') target[i + 1] = 0;
    }

    backTrack(1);
    
    return (0);
}