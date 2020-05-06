#include <bits/stdc++.h>

#define fi first
#define se second
#define ii pair < int, int >
#define vi vector < int >
#define vii vector < ii >
#define fast ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int N = 1e5 + 10;
const int oo = 1e9 + 7;

int query;
set < int > s;

main()
{
	fast;
	freopen ("set.inp", "r", stdin);
	freopen ("set.out", "w", stdout);
	cin >> query;
	for (int qq = 1; qq <= query; qq++) {
		int type, x;
		cin >> type >> x;
		if (type == 1) {
			s.insert(x);
		} else if (type == 2) {
			s.erase(x);
		} else {
			if (s.find(x) != s.end()) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	}
}
