#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int inf = 1e9 + 7;

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);

int query, n;

int main() {
    FileOpen;
    cin >> query;
    for (int qq = 0; qq < query; qq++) {
        cin >> n;
        if (n % 2 == 0) cout << n / 2 - 1 << endl;
        else cout << n / 2 << endl;
    }
}
