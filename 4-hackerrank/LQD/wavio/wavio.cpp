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

int n;
int a[N], b[N];
int f[N], g[N], tmp[N];

void DP(int x[], int n, int dp[]) {
	for (int i = 0; i <= n; i++) {
		dp[i] = 0;
	}
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (x[j] < x[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	return;
}

int main()
{
	fast;
	freopen ("wavio.inp", "r", stdin);
	freopen ("wavio.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[n + 1 - i] = a[i];
	}
	
	DP(a, n, f);
	DP(b, n, tmp);
	for (int i = 1; i <= n; i++) {
		g[i] = tmp[n + 1 - i];
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, f[i] + g[i] - 1);
	}
	cout << res << endl;
	
}
