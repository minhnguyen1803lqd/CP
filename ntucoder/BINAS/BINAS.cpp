#include <bits/stdc++.h>


#define fi first
#define se second
#define ii pair < int, int >
#define vi vector < int >
#define vii vector < ii >
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)


using namespace std;


const int N = 1e3 + 10;
const int oo = 1e9 + 7;

int n;
int x[N];

void Recur(int id) {
	if (id == n + 1) {
		FOR(i, 1, n) {
			cout << x[i];
		}
		cout << endl;
	} else {
		REP(i, 2) {
			x[id] = i;
			Recur(id + 1);
		}
	}
}

main()
{
	fast;
	freopen ("BINAS.inp", "r", stdin);
	freopen ("BINAS.out", "w", stdout);

	cin >> n;

	Recur(1);

	return 0;
}
