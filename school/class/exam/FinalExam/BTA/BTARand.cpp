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


const int N = 1e5 + 10;
const int oo = 1e9 + 7;

int n, m, ans;
int a[N], b[N];

main()
{
	fast;
	freopen ("BTA.inp", "r", stdin);
	freopen ("BTARand.out", "w", stdout);

	cin >> n >> m;
	FOR(i, 1, n) {
		cin >> a[i];
	}
	FOR(i, 1, m) {
		cin >> b[i];
	}

	FOR(i, 1, 100) {
		int flag1 = 0;
		int flag2 = 0;
		FOR(j, 1, n) {
			if (i % a[j] != 0) {
				flag1 = 1;
				break;
			}
		}
		FOR(k, 1, m) {
			if (b[k] % i != 0) {
				flag2 = 1;
				break;
			}
		}
		if (flag1 == 0 && flag2 == 0) {
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}
