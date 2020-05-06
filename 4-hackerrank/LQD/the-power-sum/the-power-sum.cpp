#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
const int oo = 1e9 + 7;

int n, k, ans = 0;
int x[N], f[N];

void Setup() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen ("the-power-sum.inp", "r", stdin);
	freopen ("the-power-sum.out", "w", stdout);
}

int Pow(int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	if (a == 1) return 1;
	int res = Pow(a, b / 2);
	if (b % 2 == 0) return (res * res);
	else return (res * res * a);
}

int Find(int n, int k) {
	int res = 0;
	while (Pow(res, k) <= n) {
		++res;
	}
	for (int i = 1; i < res; i++) {
		f[i] = Pow(i, k);
	}
	return (res - 1);
}

void Recur(int id, int N) {
	if (id == N + 1) {
		int s = 0;
		for (int i = 1; i <= N; i++) {
			s += (x[i] * f[i]);
		}
		if (s == n) {
			ans++;
		}
	} else {
		for (int i = 0; i < 2; i++) {
			x[id] = i;
			Recur(id + 1, N);
		}
	}
}

int main() {
	Setup();
	cin >> n >> k;
	cout << totnum(n, k, 1) << endl;
}
// #include <cmath>
// #include <iostream>
// using namespace std;

// int totnum(int X,int N,int num){
//     if(pow(num,N)<X)
//         return totnum(X,N,num+1)+totnum(X-pow(num,N),N,num+1);
//     else if(pow(num,N)==X)
//         return 1;
//     else
//         return 0;
// }

// int main() {
//     int X,N;
//     cin>>X>>N;
//     cout<<totnum(X,N,1);
//     return 0;
// }
