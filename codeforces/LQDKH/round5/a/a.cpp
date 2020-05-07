#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e4 + 10;
const int oo = 1e9 + 7;

#define setup freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);
#define StartCountTime clock_t t;   t = clock();
#define StopCountTime t = clock() - t;    cerr << ((float)t) / CLOCKS_PER_SEC << endl;

int query;

int main() {
    setup;
    StartCountTime;

    cin >> query;
    cin.ignore(1);
    while (query--) {
        string s;
        getline(cin, s);
        cout << (s == "Happy New Year!!!" ? "YES\n" : "NO\n");
    }    

    StopCountTime;
}
