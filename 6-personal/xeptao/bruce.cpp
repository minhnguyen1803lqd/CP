#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e6 + 10;
const int oo = 1e9 + 7;

#define setup freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".ans").c_str(), "w", stdout);
#define StartCountTime clock_t t;   t = clock();
#define StopCountTime t = clock() - t;    cerr << ((float)t) / CLOCKS_PER_SEC << endl;

int tmp, n, m;
string s1, s2, s;

int Find(string a, string b) {
    int cnt = 0;
    n = a.length();
    m = b.length();

}

int main() {
    setup;
    StartCountTime;

    cin >> tmp;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
    	if (i % 2 != 0) {
    		s1 += '1';
    		s2 += '0';
    	} else {
    		s1 += '0';
    		s2 += '1';
    	}
    }



    StopCountTime;
}
