#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e4 + 10;
const int oo = 1e9 + 7;

#define setup freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);
#define StartCountTime clock_t t;   t = clock();
#define StopCountTime t = clock() - t;    cerr << ((float)t) / CLOCKS_PER_SEC << endl;

int query, res;
string s;

int Cal(string s) {
    //cout << "s = " << s << endl;
    int id = 0, ans = 0;
    while (id < s.length()) {
        while (s[id] == '0' && id < s.length()) id++;
        int i = id + 1;
        while (s[i] == '0' && i < s.length()) i++;
        if (i < s.length() ) {
            ans += (i - id - 1);
        }
        //cout << id << " " << i << endl;
        id = i;
    }
    return (ans);
}

int main() {
    setup;
    StartCountTime;
    
    cin >> query;
    for (int qq = 1; qq <= query; qq++) {
        cin >> s;
        res = Cal(s);
        cout << res << endl;
    }

    StopCountTime;
}
