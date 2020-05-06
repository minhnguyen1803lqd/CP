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

int n;
map < int, int > mp;

int main()
{
	fast;
	freopen ("loc-so.inp", "r", stdin);
	freopen ("loc-so.out", "w", stdout);
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		mp.insert(make_pair(a[i], i));
	}
	cout << mp.size() << endl;
	map < int, int > :: iterator i;
	for (i = mp.begin(); i != mp.end(); i++) {
		cout << i->fi << " ";
	}
}
