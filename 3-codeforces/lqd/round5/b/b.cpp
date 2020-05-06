#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e4 + 10;
const int oo = 1e9 + 7;

#define setup freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);
#define StartCountTime clock_t t;   t = clock();
#define StopCountTime t = clock() - t;    cerr << ((float)t) / CLOCKS_PER_SEC << endl;

int a, b, c;
int cnt = 0;

int main() {
    setup;
    StartCountTime;
    
    cin >> a >> b >> c;

    while (a != 0 && b != 0 && c != 0) {
        cnt++;
        a--;
        b--;
        c--;
        if (a <= b && a <= c) {
            a++;
        } else if (b <= c && b <= a) {
            b++;
        } else {
            c++;
        }
    }    
    cout << cnt << endl;
    StopCountTime;
}
