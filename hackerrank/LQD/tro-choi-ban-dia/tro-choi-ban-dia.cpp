#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
const int oo = 1e9 + 7;

int n;
int a[N];
int f[N][10];

void Setup() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen ("tro-choi-ban-dia.inp", "r", stdin);
	freopen ("tro-choi-ban-dia.out", "w", stdout);
}

int main() {
	Setup();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	memset(f, -0x1f, sizeof(f));
	f[0][2] = 0;
	for (int i = 1; i <= n; i++) {
		f[i][0] = max(f[i][0], f[i - 1][1] + a[i]);
		f[i][1] = max(f[i - 1][2] + a[i] , max(f[i - 1][0] , f[i][1]));
        f[i][2] = max(f[i - 1][1] , max(f[i - 1][2] , f[i - 1][0]));
	}
	int res;
	for (int i = 0; i <= 2; i++) {
		res = max(res, f[n][i]);
	}
	cout << res << endl;
}
// #include<bits/stdc++.h>
// using namespace std;

// #define y1 as214
// #define ii pair < int , int >
// #define iii pair < int , ii >
// #define iv pair < ii , ii >

// #define fi first
// #define se second
// #define fr front()
// #define pb push_back
// #define t top()

// #define FOR(i , x , n) for(ll i = x ; i <= n ; ++i)
// #define REP(i , n) for(ll i = 0 ; i < n ; ++i)
// #define FORD(i , x , n) for(ll i = x ; i >= n ; --i)

// #define ll long long
// #define oo 1e17
// #define eps 1e-8
// #define div divv
// #define pow poww
// #define int long long

// const int N = 1e6 + 5;
// int n , res;
// int a[N];
// int dp[N][5];

// int32_t main()
// {
//     //freopen("test1.inp","r",stdin);
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n;
//     FOR(i , 1 , n)
//         cin >> a[i];
//     memset(dp , -0x1f , sizeof(dp));
//     dp[0][2] = 0;
//     FOR(i , 1 , n)
//     {
//         dp[i][0] = max(dp[i][0] , dp[i - 1][1] + a[i]);
//         dp[i][1] = max(dp[i - 1][2] + a[i] , max(dp[i - 1][0] , dp[i][1]));
//         dp[i][2] = max(dp[i - 1][1] , max(dp[i - 1][2] , dp[i - 1][0]));
//         //cerr << i << " " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
//     }
//     FOR(i , 0 , 2)
//         res = max(res , dp[n][i]);
//     cout << res;
// }