#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e4 + 10;
const int oo = 1e9 + 7;

#define setup freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);
#define StartCountTime clock_t t;   t = clock();
#define StopCountTime t = clock() - t;    cerr << ((float)t) / CLOCKS_PER_SEC << endl;

int query, n, g, b;

int Cal(int n, int g, int b) {
    int GoodDay = 0;
    int selecter = 2;
    int cnt = 0;
    while (true) {
        if (selecter % 2 == 0) {
            cnt += g;
            GoodDay += g;
            if ((n % 2 == 0 and GoodDay == n / 2) or (n % 2 != 0 and GoodDay == n / 2 + 1)) break;
        } else {
            cnt += b;
        }
    }
    if (cnt < n) {

    } else {
        
    }
}

int main() {
    setup;
    StartCountTime;
    
    cin >> query;
    for (int qq = 1; qq <= query; qq++) {
        cin >> n >> g >> b;
        int res = Cal(n, g, b);
        cout << res << endl;
    }

    StopCountTime;
}
