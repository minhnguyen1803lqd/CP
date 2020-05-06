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

int n, k;
priority_queue < int, vector < int >, greater < int > > pq;

main()
{
	fast;
	freopen ("jesse-and-cookies.inp", "r", stdin);
	freopen ("jesse-and-cookies.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}
	int res = 0;
	while (pq.size() >= 2 && pq.top() < k) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		int newFront = a + 2 * b;
		pq.push(newFront);
		res++;
	}
	if (pq.top() >= k) {
		cout << res << endl;
	} else {
		cout << -1 << endl;
	}
}
