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

int n, k;
int x[N];	

bool Check() {
	int id = 1;
	while (id <= n + 1 - k) {
		int flag = 0;
		for (int i = id; i <= id + k - 2; i++) {
			if (x[i] != x[i + 1]) {
				flag = 1;
			}
		}
		if (flag == 0) {
			return false;
		}
		id++;
	}
	return true;
}

void Recur(int id) {
	if (id == n + 1) {
		if (Check()) {
			for (int i = 1; i <= n; i++) {
				cout << x[i] << " ";
			}
			cout << endl;
		}
	} else {
		for (int i = 0; i < 3; i++) {
			x[id] = i;
			Recur(id + 1);
		}
	}
}

int main()
{
	fast;
	freopen ("day-tam-phan.inp", "r", stdin);
	freopen ("day-tam-phan.out", "w", stdout);
	cin >> n >> k;
	Recur(1);
}
