#include <bits/stdc++.h>

#define fi first
#define se second
#define ii pair < int, int >
#define vi vector < int >
#define vii vector < ii >
#define fast ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int N = 1e4 + 10;
const int oo = 1e9 + 7;

long long n, query;

int main()
{
	fast;
	freopen ("hack-account.inp", "r", stdin);
	freopen ("hack-account.out", "w", stdout);
	cin >> query;
	for (int qq = 1; qq <= query; qq++) {
		cin >> n;
		int k = 1;
		if (n == 1) {
			cout << "YES\n";
			goto close;
		}
		for (int i = 0; i <= 13; i++) {
			int x = n;
			if (x % k == 0) {
				x /= k;
				if (x == 1) {
					cout << "YES\n";
					goto close;
				}
				while (x % 20 == 0) {
					x /= 20;
				}
				if (x == 1) {
					cout << "YES\n";
					goto close;
				}
			}
			k *= 10;
		}
		cout << "NO\n";
		close:;
	}
}
