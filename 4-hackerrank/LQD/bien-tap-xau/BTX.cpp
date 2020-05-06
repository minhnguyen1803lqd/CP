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
stack < pair < string, int > > st;

main()
{
	fast;
	freopen ("BTX.inp", "r", stdin);
	freopen ("BTX.out", "w", stdout);
	cin >> query;
	for (int qq = 1; qq <= query; qq++) {
		int type;
		cin >> type;
		if (type == 1) {
			string w;
			cin >> w;
			if (st.empty()) {
				st.push(make_pair(w, 1));
			} else {
				string tmp = st.top().fi;
				tmp += w;
				st.push(make_pair(tmp, 1));
			}
		} else if (type == 2) {
			int k, n;
			cin >> k;
			string tmp = st.top().fi;
			n = tmp.length();
			tmp.erase(n - k, k);
			st.push(make_pair(tmp, 2));
		} else if (type == 3) {
			int k;
			cin >> k;
			string tmp = st.top().fi;
			cout << tmp[k - 1] << endl;
		} else {
			if (st.top().se == 1 || st.top().se == 2) {
				st.pop();
			}
		}
	}
}
