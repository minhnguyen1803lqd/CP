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

int n, x, u, v, cnt;
int a[N], b[N], c[N];

int main()
{
	fast;
	freopen ("xoa-phan-tu-trong-vector.inp", "r", stdin);
	freopen ("xoa-phan-tu-trong-vector.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> x >> u >> v;
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (i != x) {
			cnt++;
			b[cnt] = a[i];
		}
	}
	n = cnt;
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!(u <= i && i < v)) {
			cnt++;
			c[cnt] = b[i];
		}
	}
	cout << cnt << endl;
	for (int i = 1; i <= cnt; i++) {
		cout << c[i] << " ";
	}
}
