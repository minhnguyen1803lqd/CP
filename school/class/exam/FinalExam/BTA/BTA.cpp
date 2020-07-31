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

int n, m;
vi a, b;

int GCD(vi a) {
	int res;
	res = __gcd(a[0], a[1]);
	for (int i = 2; i < a.size(); i++) {
		res = __gcd(res, a[i]);
	}
	return (res);
}

int LCD(vi a) {
	int res;
	res = (a[0] * a[1]) / __gcd(a[0], a[1]);
	for (int i = 2; i < a.size(); i++) {
		res = (res * a[i]) / __gcd(res, a[i]);
	}
	return (res);
}

main()
{
	fast;
	freopen ("BTA.inp", "r", stdin);
	freopen ("BTA.out", "w", stdout);

	cin >> n >> m;
	FOR(i, 1, n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	FOR(i, 1, m) {
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
	}

	int GCD1 = GCD(a), LCD1 = LCD(a);
	int GCD2 = GCD(b), LCD2 = LCD(b);
	int ans1 = 0, ans2 = 0;
	for (int i = LCD1; i <= GCD2; i++) {
		if (i % LCD1 == 0 && GCD2 % i == 0) {
			ans1++;
		}
	}
	for (int i = LCD2; i <= GCD1; i++) {
		if (i % LCD2 == 0 && GCD1 % i == 0) {
			ans2++;
		}
	}
	cout << max(ans1, ans2) << endl;

	return 0;
}