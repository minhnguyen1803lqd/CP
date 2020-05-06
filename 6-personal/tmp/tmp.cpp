#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e6 + 10;
const int oo = 1e9 + 7;

#define setup freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);
#define StartCountTime clock_t t;   t = clock();
#define StopCountTime t = clock() - t;    cerr << ((float)t) / CLOCKS_PER_SEC << endl;

int n, k;
int a[N], cnt[N], f[N];

int main() {
    setup;
    StartCountTime;
    
    cin >> n >> k;
    for (int i =1 ; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }  
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            f[j + k] += cnt[j + k];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << f[a[i]] << " ";
    }

    StopCountTime;
}
