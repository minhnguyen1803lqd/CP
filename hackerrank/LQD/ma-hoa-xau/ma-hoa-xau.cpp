#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
const int oo = 1e9 + 7;

int query;
int n;
string s;

void Setup() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen ("ma-hoa-xau.inp", "r", stdin);
	freopen ("ma-hoa-xau.out", "w", stdout);
}

void Process(int l, int r) {
	int mid = (l + r) / 2;
	if (l == r) {
		cout << s[l];
		return;
	} else if (l == mid) {
		Process(l, mid);
		Process(mid + 1, r);
	} else {
		Process(mid, mid);
		Process(l, mid - 1);
		Process(mid + 1, r);
	}
}

int main() {
	Setup();
	cin >> query;
	for (int qq = 1; qq <= query; qq++) {
		cin >> n >> s;
		Process(0, n - 1);
		cout << endl;
	}
}
