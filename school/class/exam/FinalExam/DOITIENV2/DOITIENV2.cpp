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
#define bug "bug "


using namespace std;


const int N = 1e4 + 10;
const int oo = 1e9 + 7;

int n, m;
int a[N];
int f[N][N];

main()
{
	fast;
	freopen ("DOITIENV2.inp", "r", stdin);
	freopen ("DOITIENV2.out", "w", stdout);

	cin >> m >> n;
	FOR(i, 1, n) {
		cin >> a[i];
	}

	sort(a + 1, a + 1 + n);

	FOR(i, 0, n) {
		FOR(j, 0, m) {
			f[i][j] = 0;
		}
	}

	FOR(j, 1, m) {
		f[1][j] = (j % a[1] == 0);
	}

	FOR(i, 2, n) {
		FOR(j, 1, m) {
			if (a[i] > j) {
				f[i][j] = f[i - 1][j];
			} else {
				int case1 = ( ( ((f[i][j - a[i]] != 0) * f[i][j - a[i]] ) - ( (j - a[i]) % a[i] == 0 )) > 0 );
				int case2 = f[i - 1][j];
				int case3 = (j % a[i] == 0);
				f[i][j] = case1 + case2 + case3;	
			}
		}
	}

	FOR(i, 1, n) {
		FOR(j, 1, m) {
			cout << f[i][j] << " ";
		}
		cout << endl;
	}

	cout << f[n][m] << endl;

	return 0;
}
