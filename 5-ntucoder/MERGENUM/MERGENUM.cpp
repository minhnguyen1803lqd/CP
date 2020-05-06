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

string x, y, ansMin, ansMax;

string GetMin(string x, string y){
	int n = x.length(), m = y.length();

	int p1 = 0, p2 = 0;
	while (true) {
		if (p1 == n || p2 == m) break;
		if (x[p1] < y[p2]) {
			ansMin += x[p1];
			p1++;
		} else if (x[p1] == y[p2]) {

		} else {
			ansMin += y[p2];
			p2++;
		}
	}

	if (p1 < n) {
		while (p1 < n) {
			ansMin += x[p1++];
		}
	}
	if (p2 < m) {
		while (p2 < m) {
			ansMin += y[p2++];
		}
	}
	return (ansMin);
}
string GetMax(string x, string y){
	int n = x.length(), m = y.length();

	int p1 = 0, p2 = 0;
	while (true) {
		if (p1 == n || p2 == m) break;
		if (x[p1] > y[p2]) {
			ansMax += x[p1];
			p1++;
		} else if (x[p1] == y[p2]) {
			string tmps;
			int tmp1 = p1, tmp2 = p2;
			while (x[tmp1] == y[tmp2] && tmp1 < n && tmp2 < m) {
				tmps += x[tmp1];
				tmp1++;
				tmp2++;
			}
			ansMax += tmps;
			if (tmp1 >= n) {
				p1 = tmp1;
			} else if (tmp2 >= m) {
				p2 = tmp2;
			} else if (x[tmp1] > y[tmp2]) {
				p1 = tmp1;
			} else {
				p2 = tmp2;
			}
		} else {
			ansMax += y[p2];
			p2++;
		}
	}

	if (p1 < n) {
		while (p1 < n) {
			ansMax += x[p1++];
		}
	}
	if (p2 < m) {
		while (p2 < m) {
			ansMax += y[p2++];
		}
	}
	return (ansMax);
}

main()
{
	fast;
	freopen ("MERGENUM.inp", "r", stdin);
	freopen ("MERGENUM.out", "w", stdout);

	cin >> x >> y;
	
	cout << GetMin(x, y) << endl;
	cout << GetMax(x, y) << endl;


	return 0;
}
