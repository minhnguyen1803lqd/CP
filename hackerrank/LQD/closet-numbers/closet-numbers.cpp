#include <bits/stdc++.h>

#define fi first
#define se second
#define ii pair < int, int >
#define vi vector < int >
#define vii vector < ii >
#define fast ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int N = 2e5 + 10;
const int oo = 1e9 + 7;

int n;
int a[N];

int main()
{
	fast;
	freopen ("closet-numbers.inp", "r", stdin);
	freopen ("closet-numbers.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int minDiff = oo;
	for (int i = 1; i <= n - 1; i++) {
		minDiff = min(minDiff, abs(a[i + 1] - a[i]));
	}
	//cout << "minDiff: " << minDiff << endl;
	for (int i = 1; i <= n - 1; i++) {
		if (abs(a[i + 1] - a[i]) == minDiff) {
			cout << a[i] << " " << a[i + 1] << " ";
		}
	}
}
