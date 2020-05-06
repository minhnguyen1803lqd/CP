#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 50 + 10;
const int oo = 1e9 + 7;

#define setup freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".ans").c_str(), "w", stdout);
#define StartCountTime clock_t t;   t = clock();
#define StopCountTime t = clock() - t;    cerr << ((float)t) / CLOCKS_PER_SEC << endl;

int n, ans = 0;
int fibo[N];

void Fibo() {
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	return;
}

bool Prime(int x) {
	if (x == 0 || x == 1) return (false);
	if (x == 2) return (true);
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) return (false);
	}
	return (true);
}

void Count() {
	for (int i = 0; i <= n; i++) {
		if (Prime(fibo[i])) {
            //cerr << fibo[i] << " " << i << endl;
			ans++;
		}
	}
	//cerr << endl;
	return;
}

int main() {
    setup;
    StartCountTime;

    cin >> n;
    Fibo();
    Count();
    cout << ans << endl;

    StopCountTime;
}
