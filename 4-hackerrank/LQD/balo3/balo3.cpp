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

struct node {
	int weight;
	int value;
};

int n, m;
node a[N];
int l[N], p[N];

int main()
{
	fast;
	freopen ("balo3.inp", "r", stdin);
	freopen ("balo3.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].weight >> a[i].value;
	}
	for (int i = 0; i <= m; i++) {
		l[i] = 0;
		p[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			p[j] = l[j];
		}
		for (int j = 0; j <= m; j++) {
			if (j < a[i].weight) {
				l[j] = p[j];
			} else {
				l[j] = max(p[j], l[j - a[i].weight] + a[i].value);
			}
		}
	}
	cout << l[m] << endl;

}
