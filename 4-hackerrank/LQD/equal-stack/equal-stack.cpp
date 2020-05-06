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

int n1, n2, n3;
int x = 0, y = 0, z = 0;

int main()
{	
	fast;
	freopen ("equal-stack.inp", "r", stdin);
	freopen ("equal-stack.out", "w", stdout);
	cin >> n1 >> n2 >> n3;
	int a[n1], b[n2], c[n3];
	for (int i = 0; i < n1; i++) {
		cin >> a[i];
		x += a[i];
	}
	for (int i = 0; i < n2; i++) {
		cin >> b[i];
		y += b[i];
	}
	for (int i = 0; i < n3; i++) {
		cin >> c[i];
		z += c[i];
	}
	int i = 0, j = 0, k = 0;
	while (x != y || y != z || x != z) {
		if (x > y && x > z || x == y && x > z || x > y && x == z) {
			x -= a[i++];
		} else if (y > x && y > z || y == x && y > z || y > x && y == z) {
			y -= b[j++];
		} else if (z > x && z > y || z == x && z > y || z > x && z == y) {
			z -= c[k++];
		}
	}
	cout << x << endl;
	
}
