#include <bits/stdc++.h>

using namespace std;

typedef pair<long, long> pll;

vector <pll> save[100005] = {};
unordered_set <long> pos;
long n;

int main() {
	freopen("profesor.inp", "r", stdin);
	freopen("profesor.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		long a, b;
		cin >> a >> b;
		pos.insert(a);
		pos.insert(b);
		if (save[a].empty()) save[a].push_back({1, i});
		else {
			if (save[a].back().second == i-1) save[a].back().first++, save[a].back().second++;
			else save[a].push_back({1, i});
		}
		if (a != b) {
			if (save[b].empty()) save[b].push_back({1, i});
			else {
				if (save[b].back().second == i-1) save[b].back().first++, save[b].back().second++;
				else save[b].push_back({1, i});
			}
		}
	}
	pll maxx = {0, 0};
	for (auto id : pos) {
		for (auto i : save[id]) {
			if (maxx.first < i.first) maxx = {i.first, id};
			else if (maxx.first == i.first && maxx.second > id) maxx={i.first, id};
		}
	}
	cout << maxx.first << " " << maxx.second;
}