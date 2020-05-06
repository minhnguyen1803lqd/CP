/*

 */
#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e5 + 10;
const int inf = 1e9 + 7;

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);

double n, pos = 0, neg = 0, zer = 0;

int main() {
    FileOpen;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > 0) pos++;
        else if (tmp < 0) neg++;
        else zer++;
    }
    cout << fixed << setprecision(6) << pos / n << endl;
    cout << fixed << setprecision(6) << neg / n << endl;
    cout << fixed << setprecision(6) << zer / n << endl;
}
