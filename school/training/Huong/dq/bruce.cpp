#include <bits/stdc++.h>
using namespace std;
int n, f[10009];
struct dt {
	int u, v, c;
} a[10009];
bool cmp(dt a, dt b) {
	return a.v < b.v;
}
int main() {
	freopen("dq.inp", "r", stdin);
	freopen("dq.ans", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].u >> a[i].v >> a[i].c;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) f[i] = a[i].c;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[j].u >= a[i].v) {
				if (f[i] + a[j].c > f[j]) f[j] = f[i] + a[j].c;
			}
		}
	}
	int res = f[1];
	for (int i = 2; i <= n; i++) res = max(res, f[i]);
	cout << res;
	return 0;
}

//	Code supported by Võ Trường Trung Hiếu