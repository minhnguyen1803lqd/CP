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
stack < ii > st;

main()
{
	fast;
	freopen ("max-num-in-stack.inp", "r", stdin);
	freopen ("max-num-in-stack.out", "w", stdout);
	cin >> query;
	for (int qq = 1; qq <= query; qq++) {
		int type;
		cin >> type;
		if (type == 1) {
			int x;
			cin >> x;
			if (st.empty() == true) {
				st.push(make_pair(x, x));
			} else {
				int newMax = max(x, st.top().se);
				st.push(make_pair(x, newMax));
			}
		} else if (type == 2) {
			if (st.empty() == false) {
				st.pop();
			} else {
				exit(0);
			}
		} else {
			if (st.empty() == false) {
				cout << st.top().se << endl;
			}
		}
	}

}
