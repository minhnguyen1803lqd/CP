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

#define ci pair < char, int >

using namespace std;

const int N = 1e5 + 10;
const int oo = 1e9 + 7;

stack < ci > st;
string s;

void PrintStack(stack < ci > x) {
	if (x.size() == 0) {
		return;
	} else {
		char tmp = x.top().fi;
		x.pop();
		PrintStack(x);
		cout << tmp;
	}
}

main()
{
	fast;
	freopen ("RGS.inp", "r", stdin);
	freopen ("RGS.out", "w", stdout);

	cin >> s;

	int id = 0;
	int n = s.length();

	while (id < n) {
		if (st.size() > 0 && s[id] == st.top().fi && abs(st.top().se - id) == 1) {
			st.pop();
		} else {
			st.push(make_pair(s[id], id));
		}
		id++;
	}
	cout << st.size() << endl;
	//PrintStack(st);

	return 0;
}
