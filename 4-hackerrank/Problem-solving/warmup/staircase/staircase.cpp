/*

 */
#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e4 + 10;
const int inf = 1e9 + 7;

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);

int n;

int main() {
    FileOpen;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for (int j = n - i + 1; j <= n; j++) {
            cout << "#";
        }
        cout << endl;
    }
}
